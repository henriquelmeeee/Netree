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
#include "../../Core/Unicode.h"

/*
 
Since HTML tokenization is often complex, we were inspired by Andreas Kling's lexer 
(html-spec-compliant parser) which uses a series of macros to make the code more verbose.
*/

#define ON(__char)                \
  if(peek() == __char)  

#define STATE(__state)      \
  case State::__state:

enum State {
  Data,
  // 78 more...
};

namespace HTML {

class Lexer {
  private:
    u32 m_cursor = 0;
    UNICODE_CHAR* m_code = nullptr;
    u32 m_code_length = 0;
  public:
    Lexer(UNICODE_CHAR* code, u32 length) : m_code(code), m_code_length(length) {
      std::cout << "Lexer::Lexer(): created!\n";
    }

    UNICODE_CHAR peek(u32 offset = 0) {
      // TODO
      return 0;
    }

    void tokenize() {
      for(;;) {
        
      }
    }

};

} // namespace HTML
