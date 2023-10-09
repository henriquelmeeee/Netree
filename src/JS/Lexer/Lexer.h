/*
 Copyright (c) 2023 [Henrique] [Zing]
 SPDX-License-Identifier: BSD-2-Clause
*/

#pragma once

#include <stdlib.h>

#include <stdio.h>
#include <iostream>
#include <vector>

#include "../../Core/Types.h"

namespace JS {

class Token {
  public:
    Token() {}
};

std::vector<char> special_chars = \
    {
      ')', '(', '\\', '\'', '"', '{', '}', '.', ';', '!', '=', '>', '<', '-'
    };

class Lexer {
  private:
    char* m_code = nullptr;

    u32 m_cursor = 0;
    u32 m_code_length = 0;

    std::vector<Token> m_tokens = {};
  public:
    Lexer() {}
    Lexer(char* code, u32 length) : m_code(code), m_code_length(length) {
      std::cout << "JS::Lexer(): Created! \\o/\n";
    }

    bool __handle_special_char(char);

    bool __consume_text();

    char peek(u32 offset = 0) {
      if(m_code[m_cursor + offset] >= m_code_length) {
        std::cout << "Unexpected peek()";
        return 0;
      }
      return m_code[m_cursor + offset];
    }

    char next(u32 offset = 1) {
      m_cursor+=offset;
      return m_code[m_cursor];
    }

    std::vector<Token> run() {
      while(true) {
        char current_char = peek();
        if(!__consume_text()) {
          // We need to handle special char
          // because '__consume_text()' returns 'false'
          // if the current char is special.
          if(!__handle_special_char(current_char)) {
            // exit because we encountered an EOF.
            return m_tokens;
          }
        } else {
          next();
        }
      }
      return m_tokens;
    }

}; // class Lexer

} // namespace JS
