#ifndef BINDER_HH
#define BINDER_HH

#include <unordered_map>

#include "nodes.hh"

namespace ast {
namespace binder {

typedef std::unordered_map<Symbol, Decl *> scope_t;

class Binder : public ASTVisitor {
  int depth;
  std::vector<scope_t> scopes;
  std::vector<FunDecl *> functions;
  std::vector<Loop *> loops;
  std::string external_prefix = "";
  void push_scope();
  void pop_scope();
  scope_t &current_scope();
  void enter(Decl &);
  void enter_variable(VarDecl &);
  Decl &find(const location loc, const Symbol &name);
  void resolve(Identifier &);
  void enter_primitive(const std::string &, const std::string &,
                       const std::vector<std::string> &);

public:
  Binder();
  FunDecl *analyze_program(Expr &);
  virtual void visit(IntegerLiteral &);
  virtual void visit(StringLiteral &);
  virtual void visit(BinaryOperator &);
  virtual void visit(Sequence &);
  virtual void visit(Let &);
  virtual void visit(Identifier &);
  virtual void visit(IfThenElse &);
  virtual void visit(VarDecl &);
  virtual void visit(FunDecl &);
  virtual void visit(FunCall &);
  virtual void visit(WhileLoop &);
  virtual void visit(ForLoop &);
  virtual void visit(Break &);
  virtual void visit(Assign &);
};

} // namespace binder
} // namespace ast

#endif // BINDER_HH
