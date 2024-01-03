#include "Lexer.h"

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
  }

  bool Lexer::__consume_text() {
    // For now, we will ignore '\"' ~Henrique
    while(peek() != '"') {}
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
