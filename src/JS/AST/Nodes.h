/*
 Copyright (c) 2023 [Henrique] [Zing]
 SPDX-License-Identifier: BSD-2-Clause
*/

#pragma once

#include <stdlib.h>

#include <stdio.h>
#include <iostream>
#include <vector>

#include "Variable.h"

namespace JS {

class Program {

};

class Scope : public Program {
  private:
    std::vector<Variable> m_variables;
  public:
    Scope() { std::cout << "Scope::Scope() TODO"; exit(1); }
};

class ASTNode : public Scope {
  public:
    virtual const std::string class_name() { return "ASTNode"; }

    ASTNode() {
      std::cout << "ASTNode::ASTNode(): Generic ASTNode cannot be constructed.";
      exit(1);
    }

    virtual Variable execute(Scope&) {
      std::cout << "ASTNode::execute(): Generic ASTNode cannot be executed.";
      exit(1);
    }

};

class VariableDeclaration : public ASTNode {
  private:
		Variable m_variable = {};
};

}
