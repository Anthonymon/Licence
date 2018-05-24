#include "binder.hh"
#include "../utils/errors.hh"
#include "../utils/nolocation.hh"
#include <iostream>

//Clement CAUMES 21501810

using utils::error;
using utils::non_fatal_error;

namespace ast {
namespace binder {

/* Returns the current scope */
scope_t &Binder::current_scope() { return scopes.back(); }

/* Pushes a new scope on the stack */
void Binder::push_scope() { 
scopes.push_back(scope_t()); 
}

/* Pops the current scope from the stack */
void Binder::pop_scope() {
scopes.pop_back(); 
}

/* Enter a declaration in the current scope. Raises an error if the declared name
 * is already defined */
void Binder::enter(Decl &decl) {
  scope_t &scope = current_scope();
  auto previous = scope.find(decl.name);
  if (previous != scope.end()) {
    non_fatal_error(decl.loc,
                    decl.name.get() + " is already defined in this scope");
    error(previous->second->loc, "previous declaration was here");
  }
  scope[decl.name] = &decl;
}

/* Finds the declaration for a given name. The scope stack is traversed
 * front to back starting from the current scope. The first matching
 * declaration is returned. Raises an error, if no declaration matches. */
Decl &Binder::find(const location loc, const Symbol &name) {
  for (auto scope = scopes.crbegin(); scope != scopes.crend(); scope++) {
    auto decl_entry = scope->find(name);
    if (decl_entry != scope->cend()) {
      return *decl_entry->second;
    }
  }
  error(loc, name.get() + " cannot be found in this scope"); 
}

Binder::Binder() : scopes() {
  /* Create the top-level scope */
  push_scope();

  /* Populate the top-level scope with all the primitive declarations */
  enter_primitive("print_err", "void", {"string"});
  enter_primitive("print", "void", {"string"});
  enter_primitive("print_int", "void", {"int"});
  enter_primitive("flush", "void", {});
  enter_primitive("getchar", "string", {});
  enter_primitive("ord", "int", {"string"});
  enter_primitive("chr", "string", {"int"});
  enter_primitive("size", "int", {"string"});
  enter_primitive("substring", "string", {"string", "int", "int"});
  enter_primitive("concat", "string", {"string", "string"});
  enter_primitive("strcmp", "int", {"string", "string"});
  enter_primitive("streq", "int", {"string", "string"});
  enter_primitive("not", "int", {"int"});
  enter_primitive("exit", "void", {"int"});
}

/* Declares a new primitive into the current scope*/
void Binder::enter_primitive(
    const std::string &name, const std::string &type_name,
    const std::vector<std::string> &argument_typenames) {
  std::vector<VarDecl *> args;
  int counter = 0;
  for (const std::string &tn : argument_typenames) {
    std::ostringstream argname;
    argname << "a_" << counter++;
    args.push_back(
        new VarDecl(utils::nl, Symbol(argname.str()), nullptr, Symbol(tn)));
  }

  FunDecl *fd = new FunDecl(utils::nl, Symbol(name), std::move(args), nullptr,
                            Symbol(type_name), true);
  fd->set_external_name(Symbol("__" + name));
  enter(*fd);
}

/* Binds a whole program. This method wraps the program inside a top-level main
 * function.  Then, it visits the programs with the Binder visitor; binding
 * each identifier to its declaration and computing depths.*/
FunDecl *Binder::analyze_program(Expr &root) {
  std::vector<VarDecl *> main_params;
  Sequence *const main_body = new Sequence(
      utils::nl,
      std::vector<Expr *>({&root, new IntegerLiteral(utils::nl, 0)}));
  FunDecl *const main = new FunDecl(utils::nl, Symbol("main"), main_params,
                                    main_body, Symbol("int"), true);
  main->accept(*this);
  return main;
}

void Binder::visit(IntegerLiteral &literal) {
	//aucune manipulation pour les IntegerLiteral
}

void Binder::visit(StringLiteral &literal) {
	//aucune manipulation pour les StringLiteral
}

void Binder::visit(BinaryOperator &op) {
  op.get_left().accept(*this);
  op.get_right().accept(*this);
}

void Binder::visit(Sequence &seq) {
  const auto exprs = seq.get_exprs();
  for (auto expr = exprs.cbegin(); expr != exprs.cend(); expr++) {
    (*expr)->accept(*this);
  }
}

void Binder::visit(Let &let) {
	std::vector<FunDecl*> pile; //on declare une pile de declarations
	FunDecl* myFunDecl; //on declare un pointeur de FunDecl
	push_scope(); //on met un nouveau scope dans le stack car on demarre un LET

	for (auto decl : let.get_decls()) { //on regarde chaque declaration
		myFunDecl=dynamic_cast<FunDecl*>(decl);
		if(myFunDecl!=NULL){ //si la declaration est un FunDecl on l'ajoute dans la pile
			enter(*decl);
			pile.push_back(myFunDecl);
		}
		else{  //si la declaration n'est pas un FunDecl, on vide la pile
			decl->accept(*this);
			int un= 1;
			while(!pile.empty()){ //tant que la pile n'est pas vide, on la vide et on accepte chaque element
				pile[pile.size()-un]->accept(*this);
				pile.pop_back();
			}
		}
	}
  
	while(!pile.empty()){ //tant que la pile n'est pas vide on la vide
		int taille=pile.size()-1; 
		pile[taille]->accept(*this);
		pile.pop_back();
	}
	const auto exprs = let.get_sequence().get_exprs(); //on s'occupe du IN
	for (auto expr = exprs.cbegin(); expr != exprs.cend(); expr++) {
		(*expr)->accept(*this);
	}
	pop_scope();
}

void Binder::visit(Identifier &id) {	
	id.set_depth(my_depth); //on met dans my_depth la profondeur correspondante
	// on associe à Identifier la declaration de la variable
	VarDecl* variable = dynamic_cast<VarDecl*>(&find(id.loc, id.name));
	if(variable !=NULL) id.set_decl(variable); //si cela fonctionne alors on bind id sur la declaration variable
	else error("manque la declaration de Identifier "); // si il n'y a pas d'association ERROR
	//si il y une difference de profondeur entre la declaration et sa variable
	if(variable->get_depth()!= id.get_depth()){ 
		variable->set_escapes(); //alors on marque la variable comme echappee /*e*/
	}
}

void Binder::visit(IfThenElse &ite) {
  ite.get_condition().accept(*this);
  ite.get_then_part().accept(*this);
  ite.get_else_part().accept(*this);
}

void Binder::visit(VarDecl &decl) {
	decl.set_depth(my_depth);
	//on met dans my_depth la profondeur correspondante
	  enter(decl);
  if (auto expr = decl.get_expr()) {
    expr->accept(*this);
  }
}

void Binder::visit(FunDecl &decl) {
	decl.set_depth(my_depth); //on met dans my_depth la profondeur correspondante
		my_depth++; //on incremente la profondeur
	push_scope(); //on place l'element dans stack 
  auto params = decl.get_params();
  for (auto param = params.cbegin(); param != params.cend(); param++) {
    (*param)->accept(*this);
  }
  decl.get_expr()->accept(*this);
 
  pop_scope(); //on enleve l'element de stack
   my_depth--; //on decremente my_depth 
}

void Binder::visit(FunCall &call) {
	call.set_depth(my_depth); //on met dans my_depth la profondeur correspondante
	Decl& d = find(call.loc,call.func_name); //on associe la declaration avec son appel 
	if (FunDecl *decl=dynamic_cast<FunDecl*>(&d)) {
		call.set_decl(decl);
	}
	else error(" miss a Function Call");
	
	push_scope();
  auto args = call.get_args();
  for (auto arg = args.cbegin(); arg != args.cend(); arg++) {
    (*arg)->accept(*this);
  }
  pop_scope();
}

void Binder::visit(WhileLoop &loop) {
	my_loop_binder.push_back(&loop);
	
  loop.get_condition().accept(*this);
  loop.get_body().accept(*this);
  
  my_loop_binder.pop_back();
}

void Binder::visit(ForLoop &loop) {
	
	my_loop_binder.push_back(&loop);
  loop.get_variable().get_expr()->accept(*this);
  loop.get_high().accept(*this);
  loop.get_body().accept(*this);
  
    my_loop_binder.pop_back();
}

void Binder::visit(Break &b) { 
	if(!my_loop_binder.empty()){
		int constante=1;
		int taille=my_loop_binder.size()-constante;
		b.set_loop(my_loop_binder[taille]); //associe le Break avec son parent LOOP
	}
	else error("Break hors de la boucle While ou For ");
}

void Binder::visit(Assign &assign) {
  assign.get_lhs().accept(*this);
  assign.get_rhs().accept(*this);
}

} // namespace binder
} // namespace ast
