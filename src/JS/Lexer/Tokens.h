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
    Token(TokenType type, const char* value = 0) : m_type(type) {
      if(value != nullptr) {
        m_value = value;
      }
    }


};

} // namespace JS
