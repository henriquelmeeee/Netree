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

struct VarValue {
  u32 IntengerValue;
  _Bool BooleanValue;
};

class Variable {
public:
    VariableKind m_kind;
    VarValue m_value;
private:
  Variable(VariableKind kind, VarValue value);

  VariableKind getKind() const;
  VarValue getValue() const;

  // TODO: a method to modify m_value
};
}
