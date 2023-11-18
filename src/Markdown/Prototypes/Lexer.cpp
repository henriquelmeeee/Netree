/*
 Copyright (c) 2023 [Henrique]
 SPDX-License-Identifier: BSD-2-Clause
*/

#define DEBUG

#include "Lexer.h"

#include <stdlib.h>
#include <iostream>
#include <algorithm>

// All functions '__handleX' expects that the current char of m_index is already ready.

std::vector<char> special_chars = {'*', '_', '#', '`', '>', '-', '+', '[', ']', '(', ')', '\0'};

const char Lexer::current() {
  return m_code[m_index];
}

const char Lexer::next() {
  ++m_index;
  return m_code[m_index];
}

const char Lexer::go_back() {
  --m_index;
  return m_code[m_index];
}

bool __is_special_char(const char current_char) {
  return std::find(special_chars.begin(), special_chars.end(), current_char) != special_chars.end();
}

void Lexer::handle_headers() {
  char headers[7] = {};
  int headers_quantity = 0;
  while(current() == '#') {
    if(headers_quantity == 6) {
      headers[headers_quantity] = '#';
      break;
    }
    headers[headers_quantity] = '#';
    ++headers_quantity;
    next();
  }
  emit(Token(HEADER, headers));
}

void Lexer::handle_string() {
  std::string the_string;
  while(!__is_special_char(current())) {
    the_string.push_back(current());
    if(current() == '\n')
      ++m_current_line;
    next();
  }
  emit(Token(STRING, the_string.c_str()));
}

void Lexer::handle_special_char() {
  switch(current()) {
    case '*':
      {
        if(next() == '*') {
          next();
          emit(Token(DOUBLE_STAR, "**"));
          break;
        } else {
          emit(Token(SINGLE_STAR, "*"));
          break;
        }
      }
    case '`':
      {
        if(next() == '`') {
          if(! (next() == '`') ) { // so it is like '``', empty
            emit(Token(BACKTICK, "`"));
            emit(Token(BACKTICK, "`"));
            break;
          } else {
            next();
            emit(Token(TRIPLE_BACKTICK, "```"));
            break;
          }
        } else { // so it is like '`string`'
          emit(Token(BACKTICK, "`"));
          break;
        }
      }
    case '#':
      {
        handle_headers();
        break;
      }
    default:
      std::cerr << "Lexer error line " << m_current_line << ": expected 'special char', found '" << current() << "'";
      exit(1);
  }
}

void Lexer::handle_current_char() {
  if(!__is_special_char(current())) {
    handle_string();
    return;
  }
  handle_special_char();
}

std::vector<Token> Lexer::tokenize() {
  while(current()) {
    if(current() == '\n')
      ++m_current_line;
    handle_current_char();
  }

  return m_tokens;
}

void Lexer::emit(Token token) {
#ifdef DEBUG
  std::cout << "Emit new token " << token.m_token_content << "\n";
#endif
  m_tokens.push_back(token);
}
