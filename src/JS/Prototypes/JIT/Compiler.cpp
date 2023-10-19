#include "Compiler.h"

void* JITCompiler::compile() {
  for(auto& instruction : m_block_to_compile->instructions) {
    switch(instruction.type) {
      case 1:
        break;
    }
  }
  return nullptr;
}
