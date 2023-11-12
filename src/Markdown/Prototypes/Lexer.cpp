/*
 Copyright (c) 2023 [Henrique]
 SPDX-License-Identifier: BSD-2-Clause
*/

#include "Lexer.h"

#include <stdlib.h>
#include <iostream>
#include <algorithm>

std::vector<char> special_chars = {'*', '_', '#', '`', '>', '-', '+', '[', ']', '(', ')'};

bool __is_special_char(const char current_char) {
  return std::find(special_chars.begin(), special_chars.end(), current_char) != special_chars.end();
}

void __handle_string(const char current_char, std::vector<Token>* tokens) {
  while(!__is_special_char(current())) {

  }
}

void __handle_current_char(const char current_char) {
  if(!__is_special_char(current())) {
    __handle_string(current());
    return;
  }

  switch(current_char) {

  }
}

std::vector<Token> Lexer::tokenize(const char* code) {
  while(current()) {
    __handle_current_char(code[m_index]);
    next();
  }

  return m_tokens;
}
