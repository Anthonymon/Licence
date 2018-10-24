#include <boost/program_options.hpp>
#include <iostream>

#include "../ast/ast_dumper.hh"
#include "../ast/binder.hh"
#include "../ast/escaper.hh"
#include "../ast/type_checker.hh"
#include "../parser/parser_driver.hh"
#include "../irgen/irgen.hh"
#include "../utils/errors.hh"

int main(int argc, char **argv) {
  std::string output_file;
  std::vector<std::string> input_files;
  namespace po = boost::program_options;
  po::options_description options("Options");
  options.add_options()
  ("help,h", "describe arguments")
  ("dump-ast", "dump the parsed AST")
  ("dump-ir", "dump the generated IR")
  ("bind,b", "run the binder on the parsed AST")
  ("type,t", "run the type checker on the parsed AST")
  ("irgen,i", "run the LLVM IR code generator")
  ("trace-parser", "enable parser traces")
  ("trace-lexer", "enable lexer traces")
  ("verbose,v", "be verbose")
  ("input-file", po::value(&input_files), "input Tiger file")
  ("object,o", po::value(&output_file), "generate object code file");

  po::positional_options_description positional;
  positional.add("input-file", 1);

  po::variables_map vm;
  po::store(po::command_line_parser(argc, argv)
                .options(options)
                .positional(positional)
                .run(),
            vm);
  po::notify(vm);

  if (vm.count("help")) {
    std::cout << options << "\n";
    return 1;
  }

  if (input_files.size() != 1) {
    utils::error("usage: dtiger [options] input-file");
  }

  ParserDriver parser_driver = ParserDriver(vm.count("trace-lexer"), vm.count("trace-parser"));

  if (!parser_driver.parse(input_files[0])) {
    utils::error("parser failed");
  }

  FunDecl *main = nullptr;
  if (vm.count("bind") || vm.count("type") || vm.count("irgen") || vm.count("object")) {
    ast::binder::Binder binder;
    main = binder.analyze_program(*parser_driver.result_ast);
    ast::escaper::Escaper escaper;
    main->accept(escaper);
  }

  if (vm.count("type") || vm.count("irgen") || vm.count("object")) {
    ast::type_checker::TypeChecker type_checker;
    main->accept(type_checker);
  }

  if (vm.count("irgen") || vm.count("object")) {
    irgen::IRGenerator ir_generator;
    ir_generator.generate_program(main);

    if (vm.count("dump-ir")) {
      ir_generator.print_ir(&std::cout);
    }
    if (vm.count("object")) {
      ir_generator.write_object(output_file);
    }
  }

  if (vm.count("dump-ast")) {
    ast::ASTDumper dumper(&std::cout, vm.count("verbose") > 0);
    if (main)
      main->accept(dumper);
    else
      parser_driver.result_ast->accept(dumper);
    dumper.nl();
  }
  delete parser_driver.result_ast;
  return 0;
}
