#include "ast_dumper.hh"
#include "../utils/errors.hh"

namespace ast {

void ASTDumper::visit(const IntegerLiteral &literal) {
  *ostream << literal.value;
}

void ASTDumper::visit(const StringLiteral &literal) {
  *ostream << '"';
  for (auto &c : static_cast<std::string>(literal.value)) {
    switch (c) {
    case '"':
      *ostream << "\\\"";
      break;
    case '\\':
      *ostream << "\\\\";
      break;
    case '\a':
      *ostream << "\\a";
      break;
    case '\b':
      *ostream << "\\b";
      break;
    case '\t':
      *ostream << "\\t";
      break;
    case '\n':
      *ostream << "\\n";
      break;
    case '\v':
      *ostream << "\\v";
      break;
    case '\f':
      *ostream << "\\f";
      break;
    case '\r':
      *ostream << "\\r";
      break;
    default:
      *ostream << c;
    }
  }
  *ostream << '"';
}

void ASTDumper::visit(const BinaryOperator &binop) {
  *ostream << '(';
  binop.get_left().accept(*this);
  *ostream << operator_name[binop.op];
  binop.get_right().accept(*this);
  *ostream << ')';
}

void ASTDumper::visit(const Sequence &seqExpr) {
  *ostream << "(";
  inc();
  const auto exprs = seqExpr.get_exprs();
  for (auto expr = exprs.cbegin(); expr != exprs.cend(); expr++) {
    if (expr != exprs.cbegin())
      *ostream << ';';
    nl();
    (*expr)->accept(*this);
  }
  dnl();
  *ostream << ")";
}

void ASTDumper::visit(const Let &let) {
  *ostream << "let";
  inc();
  for (auto decl : let.get_decls()) {
    nl();
    decl->accept(*this);
  }
  dnl();
  *ostream << "in";
  inc();
  const auto exprs = let.get_sequence().get_exprs();
  for (auto expr = exprs.cbegin(); expr != exprs.cend(); expr++) {
    if (expr != exprs.cbegin())
      *ostream << ';';
    nl();
    (*expr)->accept(*this);
  }
  dnl();
  *ostream << "end";
}

void ASTDumper::visit(const Identifier &id) {
  *ostream << id.name;
  if (verbose)
    if (auto decl = id.get_decl())
      if (int depth_diff = id.get_depth() - decl->get_depth())
        *ostream << "/*" << depth_diff << "*/";
}

void ASTDumper::visit(const IfThenElse &ite) {
  *ostream << "if ";
  inl();
  ite.get_condition().accept(*this);
  dnl();
  *ostream << " then ";
  inl();
  ite.get_then_part().accept(*this);
  dnl();
  *ostream << " else ";
  inl();
  ite.get_else_part().accept(*this);
  dec();
}

void ASTDumper::visit(const VarDecl &decl) {
  if (decl.get_expr())
    *ostream << "var ";
  *ostream << decl.name;
  if (verbose && decl.get_escapes())
    *ostream << "/*e*/";
  if (decl.type_name)
    *ostream << ": " << *decl.type_name;
  if (auto expr = decl.get_expr()) {
    *ostream << " := ";
    expr->accept(*this);
  }
}

void ASTDumper::visit(const FunDecl &decl) {
  *ostream << "function " << decl.name;
  if (verbose && decl.name != decl.get_external_name())
    *ostream << "/*" << decl.get_external_name() << "*/";
  *ostream << '(';
  auto params = decl.get_params();
  for (auto param = params.cbegin(); param != params.cend(); param++) {
    if (param != params.cbegin())
      *ostream << ", ";
    (*param)->accept(*this);
  }
  *ostream << ")";
  if (decl.type_name)
    *ostream << ": " << decl.type_name.get();
  *ostream << " = ";
  inl();
  decl.get_expr()->accept(*this);
  dec();
}

void ASTDumper::visit(const FunCall &call) {
  *ostream << call.func_name << '(';
  auto args = call.get_args();
  for (auto arg = args.cbegin(); arg != args.cend(); arg++) {
    if (arg != args.cbegin())
      *ostream << ", ";
    (*arg)->accept(*this);
  }
  *ostream << ')';
}

void ASTDumper::visit(const WhileLoop &loop) {
  *ostream << "while ";
  loop.get_condition().accept(*this);
  *ostream << " do";
  inl();
  loop.get_body().accept(*this);
  dec();
}

void ASTDumper::visit(const ForLoop &loop) {
  *ostream << "for " << loop.get_variable().name << " := ";
  loop.get_variable().get_expr()->accept(*this);
  *ostream << " to ";
  loop.get_high().accept(*this);
  *ostream << " do";
  inl();
  loop.get_body().accept(*this);
  dec();
}

void ASTDumper::visit(const Break &brk) { *ostream << "break"; }

void ASTDumper::visit(const Assign &assign) {
  assign.get_lhs().accept(*this);
  *ostream << " := ";
  assign.get_rhs().accept(*this);
}

//////////////////////////////
/* Methodes de ASTEvaluator */
//////////////////////////////

int ASTEvaluator::visit(const IntegerLiteral &literal) { //retourne la valeur de l'entier
  return literal.value;
}

int ASTEvaluator::visit(const StringLiteral &literal) { //retourne une erreur
	utils::error("Invalid Node [StringLiteral]");
	return -1;
}

int ASTEvaluator::visit(const BinaryOperator &binop) { //retourne le calcul de l'operation
  if(binop.op==o_plus) return binop.get_left().accept(*this)+binop.get_right().accept(*this); //+
  else if(binop.op==o_minus) return binop.get_left().accept(*this)-binop.get_right().accept(*this); //-
  else if(binop.op==o_times) return binop.get_left().accept(*this)*binop.get_right().accept(*this); //*
  else if(binop.op==o_divide) return binop.get_left().accept(*this)/binop.get_right().accept(*this); // /
  else if(binop.op==o_eq){ //=
	  if(binop.get_left().accept(*this)==binop.get_right().accept(*this)) return 1;
	  else return 0;
  }
  else if(binop.op==o_neq){ //<>
	  if(binop.get_left().accept(*this)==binop.get_right().accept(*this)) return 0;
	  else return 1;
  }
  else if(binop.op==o_lt){ //<
	  if(binop.get_left().accept(*this)<binop.get_right().accept(*this)) return 1;
	  else return 0;
  }
  else if(binop.op==o_le){ //<=
	  if(binop.get_left().accept(*this)<=binop.get_right().accept(*this)) return 1;
	  else return 0;
  }
  else if(binop.op==o_gt){ //>
	  if(binop.get_left().accept(*this)>binop.get_right().accept(*this)) return 1;
	  else return 0;
  }
  else if(binop.op==o_ge){ //>=
	  if(binop.get_left().accept(*this)>=binop.get_right().accept(*this)) return 1;
	  else return 0;
  }
  return 0; 
}

int ASTEvaluator::visit(const Sequence &seqExpr) { //retourne la derniere expression et une erreur si c'est une sequence vide
  int constante=1;
  const auto exprs = seqExpr.get_exprs();
  for (auto expr = exprs.cbegin(); expr != exprs.cend(); expr++) {
    (*expr)->accept(*this);
  }
  if((exprs.cbegin())==((exprs.cend()))){ utils::error("Sequence Vide");} 
  //si la premiere expression est egale a la derniere alors la sequence est vide
  return (*(exprs.cend()-constante))->accept(*this);
}

int ASTEvaluator::visit(const Let &let) { //retourne une erreur 
	utils::error("Invalid Node [Let]");	
	return -1;
}

int ASTEvaluator::visit(const Identifier &id) { //retourne une erreur
	utils::error("Invalid Node [Identifier]");
	return -1;
}

int ASTEvaluator::visit(const IfThenElse &ite) { //retourne l'evaluation de l'expression du then ou du else 
  if(ite.get_condition().accept(*this)){
	  return ite.get_then_part().accept(*this); //si le if est vrai on retourne le then
  }
  else return ite.get_else_part().accept(*this); //sinon on retourne le else
  return 1;
}

int ASTEvaluator::visit(const VarDecl &decl) { //retourne une erreur
	utils::error("Invalid Node [VarDecl]");
	return -1;
}

int ASTEvaluator::visit(const FunDecl &decl) { //retourne une erreur
	utils::error("Invalid Node [FunDecl]");
	return -1;
}

int ASTEvaluator::visit(const FunCall &call) { //retourne une erreur
	utils::error("Invalid Node [FunCall]");
	return -1;
}

int ASTEvaluator::visit(const WhileLoop &loop) { //retourne une erreur
	utils::error("Invalid Node [WhileLoop]");
	return -1;
}

int ASTEvaluator::visit(const ForLoop &loop) { //retourne une erreur
	utils::error("Invalid Node [ForLoop]");
	return -1;
}

int ASTEvaluator::visit(const Break &brk) { 	utils::error("Invalid Node [Break]"); return -1; } //retourne une erreur

int ASTEvaluator::visit(const Assign &assign) { //retourne une erreur
	utils::error("Invalid Node [Assign]");
	return -1;
}

} // namespace ast
