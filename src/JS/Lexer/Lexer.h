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
#include "Tokens.h"

namespace JS {

std::vector<char> special_chars = \
    {
      ')', '(', '\\', '\'', '"', '{', '}', '.', ';', '!', '=', '>', '<', '-',
      '\0'
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

    char peek(u32 offset = 0);
    char next(u32 offset = 1);
    bool emit(Token);

    bool is_special_char(char);

    std::vector<Token> run() {
      while(true) {
        char current_char = peek();
        if(is_special_char(current_char)) {
          std::cout << current_char << " é especial\n";
          if(!__handle_special_char(current_char))
            return m_tokens;
        } else {
          __consume_text();
        }
      }
      return m_tokens;
    }

}; // class Lexer

} // namespace JS