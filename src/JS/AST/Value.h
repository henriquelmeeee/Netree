/*
 Copyright (c) 2023 [Henrique] [Zing]
 SPDX-License-Identifier: BSD-2-Clause
*/

#pragma once

#include <stdlib.h>

#include <stdio.h>
#include <iostream>
#include <vector>

class Variable;
class Scope;

namespace JS {
enum ValueType {
  Number,
  Double,
  String,
  Boolean,
  Undefined,
  Null,
  Object,
  Array,
  Function,
  BigInt,
  Symbol,
  Date,
  NaN
};

class Value {
  private:
    union Data {
      std::string stringValue;                  // String
      bool boolValue;                           // Boolean
      int intValue;                             // Number
      double doubleValue;                       // Number
      Data() {}
      ~Data() {}
    } m_data;
  public:
    ValueType m_type = {};

    std::string type_as_string() const {
      switch(m_type) {
        case String:  
          return "String";
        case Boolean:
          return "Boolean";
        case Null:
          return "Null";
        case Undefined:
          return "Undefined";
        case Number:
          return "Number";
        case Double:
          return "Double";
        default:
          return "Unknown";
      }
    }

    Value(const std::string& value) : m_type(String) {
      new(&m_data.stringValue) std::string(value);
    }

    Value(bool value) : m_type(Boolean) {
      m_data.boolValue = value;
    }

    Value(int value) : m_type(Number) {
      m_data.intValue = value;
    }

    Value(double value) : m_type(Double) {
      m_data.doubleValue = value;
    }

    Value(const Value& other) : m_type(Undefined) {}
    Value() : m_type(Null) {}

    // TODO Henrique: maybe use move() for strings?
    Value& operator=(const Value& other) {
      if(this == &other) return *this;

      if(m_type == String) {
        m_data.stringValue.~basic_string();
      }
      
      m_type = other.m_type;

      switch(other.m_type) {
        case String:
          new(&m_data.stringValue) std::string(other.m_data.stringValue); break;
        case Boolean:
          m_data.boolValue = other.m_data.boolValue; break;
        case Number:
          m_data.intValue = other.m_data.intValue; break;
        case Double:
          m_data.doubleValue = other.m_data.doubleValue; break;
        default:
          m_type = Undefined; break;
      }

    }

    virtual Value execute(Scope&) {
      return *this;
    }
}; // class Value
} // namespace JS
