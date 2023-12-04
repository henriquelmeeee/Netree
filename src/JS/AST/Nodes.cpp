/*
 Copyright (c) 2023 [Henrique] [Zing]
 SPDX-License-Identifier: BSD-2-Clause
*/

#include "Nodes.h"
#include <string.h>

namespace JS {
/* execute() methods */

Value VariableDeclaration::execute(Scope* current_scope) {
  std::cout << "VariableDeclaration::execute(): called\n";
  return m_variable->execute(current_scope);
}

Value MemberExpression::execute(Scope* current_scope) {
  std::cout << "MemberExpression::execute(): called\n";
  if(strcmp("Object", m_lhs->class_name()).as_string() == 0) {
    std::cout << "\tIt's a object\n";
    // TODO
    return Value(Null);
  }

  return Value(Null);
}

} // namespace JS
