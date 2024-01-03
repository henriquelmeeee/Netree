/*
 Copyright (c) 2023 [Henrique] [Zing]
 SPDX-License-Identifier: BSD-2-Clause
*/

#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <iostream>

namespace JS {

enum TokenType {
  Keyword,          // "var"
  Identifier,       // "name"
  Punctuator,       // "=", "*", etc
  Numeric,          // "6"
};

class Token {
  private:
  public:
    TokenType m_type;

    const char* m_value = nullptr;
    const char m_value_of_unique_char = 0;
    
    Token(TokenType type, const char* value = 0) : m_type(type) {
      m_value = value;
    }

    Token(TokenType type, const char value) : m_type(type) {
      m_value = nullptr;
      m_value_of_unique_char = value;
    }


};

} // namespace JS
