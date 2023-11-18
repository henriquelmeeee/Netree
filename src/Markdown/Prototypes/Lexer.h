/*
 Copyright (c) 2023 [Henrique]
 SPDX-License-Identifier: BSD-2-Clause
*/

#pragma once

#include <stdlib.h>
#include <vector>

enum TokenType {
  STRING,
  DOUBLE_STAR,
  SINGLE_STAR,
  BACKTICK,
  TRIPLE_BACKTICK,
  HEADER,
};

class Token {
  private:
    TokenType m_token_type;
  public:
    const char* m_token_content;
    Token(TokenType token_type, const char* token_content) \
      : m_token_type(token_type), m_token_content(token_content) {
      
    }
};

class Lexer {
  private:
    unsigned long m_index = 0;
    std::vector<Token> m_tokens = {};
    const char* m_code = nullptr;

    unsigned long m_current_line = 0;
  public:
    const char current();
    const char next();
    const char go_back();

    std::vector<Token> tokenize();

    void handle_headers();
    void handle_string();
    void handle_special_char();
    void handle_current_char();
    void emit(Token);

    Lexer(const char* code) : m_code(code) {

    }
};
