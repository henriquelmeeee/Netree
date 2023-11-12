/*
 Copyright (c) 2023 [Henrique]
 SPDX-License-Identifier: BSD-2-Clause
*/

#include "Markdown.h"
#include "Lexer.h"
#include "Parser.h"

#include <stdlib.h>
#include <vector>

void Markdown::engine() {
  std::vector<Token> md_tokens = Lexer(m_code).tokenize();
  //Parser::display(&md_tokens);
}

int main() {
  Markdown("**oi**, tudo `bem`?");
}
