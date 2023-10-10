/*
 Copyright (c) 2023 [Henrique] [Zing]
 SPDX-License-Identifier: BSD-2-Clause
*/

#pragma once

/*
Henrique:
  This parser implements a function that handles each possible token type

  So for example, the "Keyword" token would be handled by a "handle_keyword()" function, 
  which would check the value of the token and call the corresponding function to handle it. 
  If it is "var", then we would call something like "handle_var_keyword()" which would consume 
  the following tokens in search of a variable declaration.
  As the code can be very dynamic, for example, having a factor (any expression inside parentheses), 
  so functions like "parse_factor()" will always be called, and if they do not find the opening of a parentheses 
  in the current token, they will simply return. 

  It's like a descending recursive parser.
*/

#include <stdlib.h>

#include <stdio.h>
#include <iostream>
#include <vector>

#include "../../Core/Types.h"

#include "../Lexer/Tokens.h"

#include "../AST/AST.h"

namespace JS {

class Parser {
  private:
    std::vector<Token> m_tokens = {};
    u32 m_cursor = 0;

    Program ast;
  public:
    Parser(std::vector<Token> tokens) : m_tokens(tokens) {

    }

    Token* next() {
      if(m_cursor+1 >= m_tokens.size()) {
        return nullptr;
      }
      ++m_cursor;
      return &m_tokens[m_cursor];
    }

    Token* peek(u32 offset = 0) {
      if(m_cursor+offset >= m_tokens.size()) {
        return nullptr;
      }
      return &m_tokens[m_cursor+offset];
    }

    bool handle_keyword();
      bool handle_var_keyword();
      bool handle_let_keyword();

    bool handle_factor();
    bool handle_term();
    bool handle_expression(); // entrypoint, called by the "run()" wrapper

    Program run() {
      while(handle_expression());
      return ast;
    }


}; // class Parser

} // namespace JS
