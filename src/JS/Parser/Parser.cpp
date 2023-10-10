/*
 Copyright (c) 2023 [Henrique] [Zing]
 SPDX-License-Identifier: BSD-2-Clause
*/

#include "Parser.h"

#include <string.h>

namespace JS {

void TODO(const char* todo_msg) {
  std::cout << "TODO(): " << todo_msg;
  while(true);
}

bool Parser::handle_var_keyword() {
  Token* token = peek();
  Token* next_token = peek(1);

  if(token->m_type != Identifier) {
    std::cerr << "Parser error: Expected 'Identifier', got '" << token->m_type << "'\n";
    return false;
  }

  if(next_token->m_type == Punctuator) {
    if(!strncmp(next_token->m_value, "=", 1)) {
      TODO("emit VariableDeclaration token in Parser::handle_var_keyword()");
    } else {
      std::cerr << "Parser error: Expected '=', got '" << token->m_value << "'\n";
      return false;
    }
  }
}

bool Parser::handle_keyword() {
  Token* token = peek();
  if(!strncmp(token->m_value, "var", sizeof("var"))) {
    if(!next()) {
      std::cerr << "Parser error: Unexpected EOF while handling 'var' keyword\n";
      return false;
    }
    if(!handle_var_keyword()) return false;
    return true;
  } else {
    TODO("Parser::handle_keyword()");
    while(true);
  }
}

bool Parser::handle_expression() {
  Token* token = peek();

  if(token == nullptr) {
    return false;
  }

  switch(token->m_type) {
    case Keyword:
      if(!handle_keyword()) return false;
      return true;
    case Identifier:
      TODO("Identifier parser::handle_expression()");
      return true;
    default:
      return false;
  }
}

bool Parser::handle_factor() {
  if(!next()) {
    std::cerr << "Parser error: Unexpected EOF while handling factor\n";
    return false;
  }
  if(!handle_expression()) {
    return false;
  }
  return true;
}

} // namespace JS
