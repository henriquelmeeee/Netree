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

class Lexer {
  private:
    char* m_code = nullptr;

    u32 m_cursor = 0;
    u32 m_code_length = 0;

    std::vector<Token> m_tokens = {};
  public:
    Lexer(char* code, u32 length) : m_code(code), m_code_length(length) {
      std::cout << "JS::Lexer(): Created! \\o/\n";
    }

    char peek(u32 offset = 0) {
      if(m_code[m_cursor + offset] >= m_code_length) {
        std::cout << "Unexpected peek()";
        return 0;
      }
      return m_code[m_cursor + offset];
    }

    std::vector<Token> run() {
      // TODO
      return m_tokens;
    }

};

}
