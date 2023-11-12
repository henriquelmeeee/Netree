/*
 Copyright (c) 2023 [Henrique]
 SPDX-License-Identifier: BSD-2-Clause
*/

#pragma once

#include <stdlib.h>
#include <vector>

enum TokenType {
  String,
  Mark,
};

class Token {
  private:
    TokenType m_token_type;
    const char* m_token_content;
  public:
    Token(TokenType token_type, const char* token_content) \
      : m_token_type(token_type), m_token_content(token_content) {
      
    }
};

namespace Lexer {
  std::vector<Token> tokenize();
} // namespace Lexer
