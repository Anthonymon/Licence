#include <cstdlib>  // For exit
#include <iostream> // For std::cerr
#include "irgen.hh"

#include "llvm/Support/raw_ostream.h"

#define UNIMPLEMENTED() do { \
  std::cerr << "Error: unimplemented feature\n"; \
  exit(1); \
} while(0)

namespace irgen {

llvm::Value *IRGenerator::visit(const IntegerLiteral &literal) {
  return Builder.getInt32(literal.value);
}

llvm::Value *IRGenerator::visit(const StringLiteral &literal) {
  return Builder.CreateGlobalStringPtr(literal.value.get());
}

llvm::Value *IRGenerator::visit(const Break &b) {
//question 7 
		llvm::BasicBlock* break_block =/* on construit le basic block du break */ loop_exit_bbs[&b.get_loop()];
  Builder.CreateBr(break_block);
  return nullptr;
  
}

llvm::Value *IRGenerator::visit(const BinaryOperator &op) {
  llvm::Value *l = op.get_left().accept(*this);
  llvm::Value *r = op.get_right().accept(*this);

  if (op.get_left().get_type() == t_string) {
    auto const strcmp = Mod->getOrInsertFunction(
        "__strcmp", Builder.getInt32Ty(), Builder.getInt8PtrTy(),
        Builder.getInt8PtrTy(), nullptr);
    l = Builder.CreateCall(strcmp, {l, r});
    r = Builder.getInt32(0);
  }

  switch(op.op) {
    case o_plus: return Builder.CreateBinOp(llvm::Instruction::Add, l, r);
    case o_minus: return Builder.CreateBinOp(llvm::Instruction::Sub, l, r);
    case o_times: return Builder.CreateBinOp(llvm::Instruction::Mul, l, r);
    case o_divide: return Builder.CreateBinOp(llvm::Instruction::SDiv, l, r);
    default: break;
  }

  // Comparisons return an i1 result which needs to be
  // casted to i32, as Tiger might use that as an integer.
  llvm::Value *cmp;

  switch(op.op) {
    case o_eq: cmp = Builder.CreateICmpEQ(l, r); break;
    case o_neq: cmp = Builder.CreateICmpNE(l, r); break;
    case o_gt: cmp = Builder.CreateICmpSGT(l, r); break;
    case o_lt: cmp = Builder.CreateICmpSLT(l, r); break;
    case o_ge: cmp = Builder.CreateICmpSGE(l, r); break;
    case o_le: cmp = Builder.CreateICmpSLE(l, r); break;
    default: assert(false); __builtin_unreachable();
  }

  return Builder.CreateIntCast(cmp, Builder.getInt32Ty(), true);
}

llvm::Value *IRGenerator::visit(const Sequence &seq) {
  llvm::Value *result = nullptr;
  for (auto expr : seq.get_exprs())
    result = expr->accept(*this);
  // An empty sequence should return () but the result
  // will never be used anyway, so nullptr is fine.
  return result;
}

llvm::Value *IRGenerator::visit(const Let &let) {
  for (auto decl : let.get_decls())
    decl->accept(*this);

  return let.get_sequence().accept(*this);
}

llvm::Value *IRGenerator::visit(const Identifier &id) {
  //question3
  // avec CreateLoad on associe l'identifier avec son adresse
	return Builder.CreateLoad(address_of(id),""); //on cree un Load avec l'adresse de id
}

llvm::Value *IRGenerator::visit(const IfThenElse &ite) {
	//question5
	//les grandes lignes du visiteur IfThenElse sont dans le slide 4.4
   //Allocate stack space (in the entry block) to represent the result
   llvm::Value * result;
   bool result_null = ite.get_type() != t_void; 
   //test pour savoir si le ifThenElse est de type void
   if(result_null){
	   //si cela retourne un type different de void alors 
	   result = alloca_in_entry(llvm_type(ite.get_type()), "if_result");
   }
   else result=nullptr;
   
   //si il n'y a pas de ELSE
   if(ite.get_else_part().accept(*this)==NULL){ 
		//Build two new basic blocks: if_then block, if_end block
		llvm::BasicBlock *const then_block = llvm::BasicBlock::Create(Context, "if_then", current_function);
		llvm::BasicBlock *const end_block = llvm::BasicBlock::Create(Context, "if_end", current_function);
   
		//on construit une branche de condition entre le then et le end block
		Builder.CreateCondBr(Builder.CreateIsNotNull(ite.get_condition().accept(*this)), then_block, end_block);
   
		Builder.SetInsertPoint(then_block); 
		llvm::Value *const then_result = ite.get_then_part().accept(*this);
		
		if(result_null) Builder.CreateStore(then_result, result);
		//on construit une branche pour le end block
		Builder.CreateBr(end_block);
		Builder.SetInsertPoint(end_block);
	}
	
	//si il y a un ELSE 
	else{
		//Build three new basic blocks: if_then block, if_else block to, if_end block
		llvm::BasicBlock *const then_block = llvm::BasicBlock::Create(Context, "if_then", current_function);
		llvm::BasicBlock *const else_block = llvm::BasicBlock::Create(Context, "if_else", current_function);
		llvm::BasicBlock *const end_block = llvm::BasicBlock::Create(Context, "if_end", current_function);
   
		//on construit une branche de condition entre le then et le else block
		Builder.CreateCondBr(Builder.CreateIsNotNull(ite.get_condition().accept(*this)), then_block, else_block);
   
		Builder.SetInsertPoint(then_block); 
		llvm::Value *const then_result = ite.get_then_part().accept(*this);
		if(result_null) Builder.CreateStore(then_result, result);
		Builder.CreateBr(end_block);
	
		Builder.SetInsertPoint(else_block);
		llvm::Value *const else_result = ite.get_else_part().accept(*this);
		if(result_null) Builder.CreateStore(else_result, result);
		//on construit une branche pour le end block
		Builder.CreateBr(end_block);
		Builder.SetInsertPoint(end_block);
	}
	
	
	if(result_null) return Builder.CreateLoad(result); //si le ifThenElse renvoie qqch on Load
	return nullptr; //sinon on renvoie nullptr 
}

llvm::Value *IRGenerator::visit(const VarDecl &decl) {
  //question2
  llvm::Value* my_value_varDecl; //on declare un pointeur sur Value
  my_value_varDecl=generate_vardecl(decl); //on genere la vardecl avec decl
  //on associe la declaration avec sa variable
	Builder.CreateStore(decl.get_expr()->accept(*this),my_value_varDecl); 
  return my_value_varDecl;
}

llvm::Value *IRGenerator::visit(const FunDecl &decl) {
  std::vector<llvm::Type *> param_types;

  // Internal functions have a static link
  if (!decl.is_external)
    param_types.push_back(frame_type[&decl.get_parent().get()]->getPointerTo());

  for (auto param_decl : decl.get_params()) {
    param_types.push_back(llvm_type(param_decl->get_type()));
  }

  llvm::Type *return_type = llvm_type(decl.get_type());

  llvm::FunctionType *ft =
      llvm::FunctionType::get(return_type, param_types, false);

  llvm::Function::Create(ft,
                         decl.is_external ? llvm::Function::ExternalLinkage
                                          : llvm::Function::InternalLinkage,
                         decl.get_external_name().get(), Mod.get());

  if (decl.get_expr())
    pending_func_bodies.push_front(&decl);

  return nullptr;
}

llvm::Value *IRGenerator::visit(const FunCall &call) {
  // Look up the name in the global module table.
  const FunDecl &decl = call.get_decl().get();
  llvm::Function *callee =
      Mod->getFunction(decl.get_external_name().get());

  if (!callee) {
    // This should only happen for primitives whose Decl is out of the AST
    // and has not yet been handled
    assert(!decl.get_expr());
    decl.accept(*this);
    callee = Mod->getFunction(decl.get_external_name().get());
  }

  std::vector<llvm::Value *> args_values;
  // Internal functions pass a static link
  if (!decl.is_external) {
    // For non primitives, first push the static link
    // Fetch the correct static link by taking into account the respective
    // depths of the called and callee functions
    int levels = call.get_depth() - decl.get_depth();
    // Sanity check, this is already tested in the TypeChecker module
    assert(levels >= 0);
    auto type_and_sl = frame_up(levels);
    args_values.push_back(type_and_sl.second);
  }
  for (auto expr : call.get_args()) {
    args_values.push_back(expr->accept(*this));
  }

  if (decl.get_type() == t_void) {
    Builder.CreateCall(callee, args_values);
    return nullptr;
  }
  return Builder.CreateCall(callee, args_values, "call");
}

llvm::Value *IRGenerator::visit(const WhileLoop &loop) {
    //question 6 
    //il faut s'inspirer de ForLoop et de IfThenElse
    //on cree 3 blocs sur la meme base que ForLoop
    llvm::BasicBlock *const test_block =
      llvm::BasicBlock::Create(Context, "while_test", current_function);
  llvm::BasicBlock *const body_block =
      llvm::BasicBlock::Create(Context, "while_body", current_function);
  llvm::BasicBlock *const end_block =
      llvm::BasicBlock::Create(Context, "while_end", current_function);
      //on cree la condition que l'on utilisera apres
  //llvm::Value *const condition = loop.get_condition().accept(*this);
  // ajout pour le break
     loop_exit_bbs[&loop]=end_block; //si on rencontre le break alors on va dans le end_block
  //on cree une branche sur test_block
  Builder.CreateBr(test_block);

  Builder.SetInsertPoint(test_block);
  //si la condition est vraie on va dans body_block sinon on va dans end_block
  Builder.CreateCondBr(Builder.CreateIsNotNull(loop.get_condition().accept(*this)), body_block, end_block);
	
  Builder.SetInsertPoint(body_block);
  loop.get_body().accept(*this);
  Builder.CreateBr(test_block);

  Builder.SetInsertPoint(end_block);
  
  return nullptr; //on renvoie nullptr car un while ne renvoie rien (comme le For)
}

llvm::Value *IRGenerator::visit(const ForLoop &loop) {
  llvm::BasicBlock *const test_block =
      llvm::BasicBlock::Create(Context, "loop_test", current_function);
  llvm::BasicBlock *const body_block =
      llvm::BasicBlock::Create(Context, "loop_body", current_function);
  llvm::BasicBlock *const end_block =
      llvm::BasicBlock::Create(Context, "loop_end", current_function);
  llvm::Value *const index = loop.get_variable().accept(*this);
  llvm::Value *const high = loop.get_high().accept(*this);
  // ajout pour le break
     loop_exit_bbs[&loop]=end_block; //si on rencontre le break alors on va dans le end_block
     //on cree une branche test_block
  Builder.CreateBr(test_block);

  Builder.SetInsertPoint(test_block);
  Builder.CreateCondBr(Builder.CreateICmpSLE(Builder.CreateLoad(index), high),
                       body_block, end_block);

  Builder.SetInsertPoint(body_block);
  loop.get_body().accept(*this);
  Builder.CreateStore(
      Builder.CreateAdd(Builder.CreateLoad(index), Builder.getInt32(1)), index);
      //on cree une branche test_block ici aussi
  Builder.CreateBr(test_block);

  Builder.SetInsertPoint(end_block);
  return nullptr;
}

llvm::Value *IRGenerator::visit(const Assign &assign) {
  //question 4
  // le store correspond au couple (valeur,adresse)
  // assign : lhs = adresse ; rhs = valeur
	return Builder.CreateStore(assign.get_rhs().accept(*this),address_of(assign.get_lhs()));
	// voir optimisation : src/driver/dtiger -i --dump-ir tests/question4.tig | opt-3.9 | llvm-dis-3.9
}

} // namespace irgen
