/*
 Copyright (c) 2023 [Henrique]
 SPDX-License-Identifier: BSD-2-Clause
*/

#pragma once

#include <stdlib.h>
#include <iostream>

#include "Lexer.h"
#include "Parser.h"

class Markdown {
  private:
    const char* m_code = nullptr;
  public:
    void engine();

    Markdown(const char* code) : m_code(code) {
      std::cout << "Markdown object created\n";
      engine();
    }
};
