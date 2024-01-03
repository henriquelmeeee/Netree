#include "Lexer.h"

namespace JS {
  bool Lexer::__handle_special_char(char char_to_handle) {
   // Here we need to emit the current special char. ~Henrique 
  }

  bool Lexer::__consume_text() {
    // For now, we will ignore '\"' ~Henrique
    while(peek() != '"') {}
  }
} // namespace JS
