/*
 Copyright (c) 2023 [Henrique] [Zing]
 SPDX-License-Identifier: BSD-2-Clause
*/

#include "Nodes.h"

namespace JS {
/* execute() methods */

Value VariableDeclaration::execute(Scope* scope) {
  std::cout << "VariableDeclaration::execute(): called\n";
  return m_variable->execute(scope);
}

}
