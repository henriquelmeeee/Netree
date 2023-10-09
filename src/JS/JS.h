/*
 Copyright (c) 2023 [Henrique] [Zing]
 SPDX-License-Identifier: BSD-2-Clause
*/

/*
 This is the interface between HTML (DOM) and the Javascript engine.
*/

// TODO: Henrique: Javascript is unicode too?
// for now, just consider that Javascript is ASCII in Lexer.

#pragma once

#include <stdlib.h>

#include <stdio.h>
#include <iostream>
#include <vector>

#include "AST/AST.h"
#include "Lexer/Lexer.h"
#include "Parser/Parser.h"

class Parser {
  public:
    Parser() {}
    Parser(std::vector<Token> tokens) {}

    std::vector<JS::ASTNode> run() { return {}; }
}; // TODO parser class in Parser/*!

namespace JS {

class JavascriptEngine {
  private:
    Lexer m_lexer {};
    Parser m_parser {};
  public:
    JavascriptEngine(char* code, u32 length) {
      // FIXME Henrique: length is REALLY necessary? We can just use strlen()...
      std::cout << "JavascriptEngine::JavascriptEngine(): created!\n";
      m_lexer = Lexer(code, length);
      m_parser = Parser();
    }

    bool run() {
      std::cout << "JavascriptEngine::run(): running!\n";
      
      std::vector<Token> tokens = m_lexer.run();
      m_parser = Parser(tokens);
      // The parser returns an vector of ASTNode
      // the Javascript Engine is responsible for creation of AST 'Program' class.
      
      std::vector<ASTNode> ast_program = m_parser.run(); 
      Program* program = new Program();
      Scope main_scope_for_program = Scope();
      for(auto node : ast_program) {
        main_scope_for_program.append_node(node);
      }
      program->append_node(main_scope_for_program);

      program->run();
    }
};

}
