#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "../Bytecode/Instructions.h"

class JITCompiler {
  private:
  public:
    Block* m_block_to_compile = nullptr;
};
