#pragma once

class Block;
class Instruction;

class VirtualRegister {
  private:
  public:
    unsigned long value; // TODO todos tipos em JS devem ser assinados, na verdade
    unsigned long m_identifier;
    VirtualRegister(unsigned long _identifier) \
      : m_identifier(_identifier) {}
    VirtualRegister() {}
};
