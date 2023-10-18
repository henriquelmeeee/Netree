#include <stdlib.h>
#include <stdio.h>

#include <iostream>
#include <vector>

#include "Instructions.h"

int main() {
  std::cout << "Protótipo de Bytecode\n";
  Block block1 = Block();

  VirtualRegister reg_1 = VirtualRegister(0);
  VirtualRegister reg_2 = VirtualRegister(1);
  
  block1.instructions.push_back(new LoadImmediate(5, reg_1));
  block1.instructions.push_back(new LoadImmediate(10, reg_2));
  block1.instructions.push_back(new Add(reg_1, reg_2));

  block1.dump_all();
}
