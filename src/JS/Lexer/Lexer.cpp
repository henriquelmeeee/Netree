#include "Lexer.h"
#include <stdlib.h>

#define OR ||

namespace JS {

  bool Lexer::__handle_special_char(char char_to_handle) {
    switch(char_to_handle) {
      case '=' OR '(' OR ')' OR ']' OR '[' OR ',' OR ';':
        emit(Token(Punctuator, char_to_handle));
        break;
      default:
        perror("__handle_special_char");
    }
    return true;
  }

  bool Lexer::__consume_text() {
    // For now, we will ignore '\"' ~Henrique
    char current_token = peek();
    char* buffer = (char*) malloc(2048);

    int amount_of_chars_already_writed = 0;
    int current_buffer_size = 2048;

    while(current_token != '"') {
      if(current_buffer_size == amount_of_chars_already_writed) {
        if(current_buffer_size > 100000)
          perror("__consume_text too many characters");

        current_buffer_size += 2048;
        // We add '1' to the current_buffer_size in realloc() function
        // to ensure that the addition of a null-byte will be suceeded.
        buffer = (char*) realloc(buffer, current_buffer_size + 1);
      }

      buffer[++amount_of_chars_already_writed] = current_token;
      current_token = next();
    }
    buffer[++amount_of_chars_already_writed] = '\0';
  }

  /* Basic functions */

  char Lexer::next(u32 offset = 1) {
    ++m_cursor;
    if(m_cursor > m_code_length)
      perror("peek() overflow");
    return m_code[offset];
  }

  char Lexer::peek(u32 offset = 0) {
    m_cursor += offset;
    if(m_cursor > m_code_length)
      perror("peek overflow");
    return m_code[m_cursor];
  }

  bool Lexer::emit(Token token) {
    m_tokens.push_back(token);
  }

} // namespace JS
