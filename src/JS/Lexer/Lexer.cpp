#include "Lexer.h"
#include <stdlib.h>
#include <algorithm>


#define OR ||

// Temporary function. Needs improvement. ~Henrique 
void [[noreturn]] __fatal(const char* msg) {
  std::cout << msg;
  while(true);
}

namespace JS {

  bool Lexer::__handle_special_char(char char_to_handle) {
    switch(char_to_handle) {
      case '=' OR '(' OR ')' OR ']' OR '[' OR ',' OR ';':
        emit(Token(Punctuator, char_to_handle));
        break;
      case '\0':
        std::cout << "EOF\n";
        return false;
      default:
        __fatal("__handle_special_char");
    }
    return true;
  }

  bool Lexer::is_special_char(char c) {
    return std::find(special_chars.begin(), special_chars.end(), c) != special_chars.end();
  }

  bool Lexer::__consume_text() {
    // For now, we will ignore '\"' ~Henrique
    char current_char = peek();
    char* buffer = (char*) malloc(2048);

    int amount_of_chars_already_writed = 0;
    int current_buffer_size = 2048;
    std::cout << "consuming text\n";

    while(!is_special_char(current_char)) {
      if(current_buffer_size == amount_of_chars_already_writed) {
        if(current_buffer_size > 100000)
          __fatal("__consume_text too many characters");

        current_buffer_size += 2048;
        // We add '1' to the current_buffer_size in realloc() function
        // to ensure that the addition of a null-byte will be suceeded.
        buffer = (char*) realloc(buffer, current_buffer_size + 1);
      }

      buffer[amount_of_chars_already_writed++] = current_char;
      current_char = next();
    }

    buffer[++amount_of_chars_already_writed] = '\0';
  }

  /* Basic functions */

  char Lexer::next(u32 offset = 1) {
    ++m_cursor;
    if(m_cursor > m_code_length)
      __fatal("next overflow");
    return m_code[offset];
  }

  char Lexer::peek(u32 offset = 0) {
    m_cursor += offset;
    if(m_cursor > m_code_length)
      __fatal("peek overflow");
    return m_code[m_cursor];
  }

  bool Lexer::emit(Token token) {
    if(token.m_value != nullptr)
      std::cout << "emit " << token.m_value << "\n";
    else
      std::cout << "emit " << token.m_value_of_unique_char << "\n";
    m_tokens.push_back(token);
  }

} // namespace JS

#define __JS_LEXER_DEBUGGER
#ifdef __JS_LEXER_DEBUGGER

int main() {
  std::cout << "[JS Lexer Debugger] started\n";
  JS::Lexer lexer = JS::Lexer("'.", 9);
  lexer.run();

}

#endif
