#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include "Registers.h"

struct InstructionType {};

class VM {
  private:
  public:
    std::vector<Block*> blocks;

    VirtualRegister allocate_register(unsigned long value, Block* block) {
      return {};
    }

    VM() {}
};

class Block {
  private:
  public:
    std::vector<Instruction*> instructions;
    unsigned short m_identifier;

    void dump_all();

    Block() {}
};

class Instruction {
  private:
  public:
    InstructionType type;
    
    virtual void execute(VM*, Block*) {
      std::cerr << "Cannot execute an generic Instruction";
      exit(1);
    }

    virtual void dump() {
      std::cout << "?\n";
    }

    Instruction() {}
};

/* Instructions */

class LoadImmediate : public Instruction {
  private:
  public:
    unsigned long m_value = 0;
    VirtualRegister m_dst;
    virtual void execute(VM* vm, Block* block) {
      m_dst.value = m_value;
    }

    virtual void dump() {
      std::cout << "\tLoad $" << m_dst.m_identifier << ", #" << m_value << "\n"; 
    }

    LoadImmediate(unsigned long value = 0, VirtualRegister dst = 0) : m_value(value), m_dst(dst) {}
};

class Add : public Instruction {
  private:
  public:
    unsigned long result = 0;

    VirtualRegister m_lhs;
    VirtualRegister m_rhs;

    virtual void execute(VM*, Block*) {
      m_lhs.value += m_rhs.value;
    }

    virtual void dump() {
      std::cout << "\tAdd $" << m_lhs.m_identifier << ", $" << m_rhs.m_identifier << "\n";
    }

    Add(VirtualRegister lhs, VirtualRegister rhs) \
      : m_lhs(lhs), m_rhs(rhs) {}
};

void Block::dump_all() {
  for(auto& instruction : instructions) {
    instruction->dump();
  }
}

