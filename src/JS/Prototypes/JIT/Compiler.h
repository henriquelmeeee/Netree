#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "../Bytecode/Instructions.h"

class JITCompiler {
  private:
  public:
    Block* m_block_to_compile = nullptr;

    JITCompiler(Block* block_to_compile) : m_block_to_compile(block_to_compile) {
      //block_to_compile->is_jit_compiled = true; 
    }

    void* compile();
};


