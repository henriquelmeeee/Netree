/*
 Copyright (c) 2023 [Henrique] [Zing]
 SPDX-License-Identifier: BSD-2-Clause
*/

#pragma once

#include <stdlib.h>

#include <stdio.h>
#include <iostream>
#include <vector>

#include "AST.h"
#include "Value.h"

namespace JS {

class Program {

};

class Scope : public Program {
  private:
    std::vector<Variable*> m_variables;
    Scope* m_previous = nullptr;
  public:
    
    Scope(Scope* previous = nullptr) : m_previous(previous) {
      std::cout << "Scope::Scope() TODO"; exit(1); 
    }

    ~Scope() {
      free(this);
    }
};

#define CLASS_NAME(name) virtual const std::string class_name() { return name; }

class ASTNode : public Scope {
  public:
    CLASS_NAME("ASTNode")

    ASTNode() {
      std::cout << "ASTNode::ASTNode(): Generic ASTNode cannot be constructed.";
      exit(1);
    }

    virtual Value execute(Scope*) {
      std::cout << "ASTNode::execute(): Generic ASTNode cannot be executed.";
      exit(1);
    }

};

/* Declarations */

class VariableDeclaration : public ASTNode {
  private:
    std::string m_name; // var name
    Variable* m_variable;
  public:
    CLASS_NAME("VariableDeclaration")

    VariableDeclaration(std::string& name, Variable* variable) : m_name(name), m_variable(variable) {}

    virtual Value execute(Scope*);
};

class FunctionDeclaration : public ASTNode {
  public:
    std::vector<ASTNode*> m_ast_nodes;

    CLASS_NAME("FunctionDeclaration")

    virtual Value execute(Scope* current_scope) {
      // TODO pass it into 'Nodes.cpp'
      Scope* new_scope = new Scope(current_scope);
      for(ASTNode* node : m_ast_nodes) {
        Value returned = node->execute(new_scope);
        if(returned.from_return_instruction()) {
          delete new_scope;
          return returned;
        }
      }
      delete new_scope;
      return Value(Null);
    }
};

/* Expressions */

class ExpressionStatement : public ASTNode {
  private:
    ASTNode* m_expression;
  public:
    CLASS_NAME("ExpressionStatement")
    virtual Value execute(Scope*);
};

class MemberExpression : public ASTNode {
  private:
    ASTNode* m_lhs;
    ASTNode* m_rhs;
  public:
    CLASS_NAME("MemberExpression")

    virtual Value execute(Scope*);
};

class CallExpression : public ASTNode {
  private:
    ASTNode* m_function;
    std::vector<ASTNode*> m_arguments;
  public:
    CLASS_NAME("ClassExpression")

    virtual Value execute(Scope*);
};



}
