/*
 Copyright (c) 2023 [Henrique] [Zing]
 SPDX-License-Identifier: BSD-2-Clause
*/

#pragma once

#include <stdlib.h>

#include <stdio.h>
#include <iostream>

namespace JS {

enum class VariableKind {
  INTENGER,
  BOOLEAN
};


class Value; // TODO at ./Value.h

class Variable {
private:
    VariableKind m_kind;
    Value m_value;
public:
  Variable(VariableKind kind, Value value) : m_value(value), m_kind(kind) {
    std::cout << "Variable::Variable(): Variable created!\n";
  }

  VariableKind getKind() const;
  Value getValue() const;

  // TODO: a method to modify m_value (Henrique: since 'Value' will use C++ features, it will be implemented different.)
};
}
