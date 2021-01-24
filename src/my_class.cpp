#include "mylib/my_class.h"

using namespace MyLib;

MyClass::MyClass(const int t_value) : m_Value(t_value)
{

}

int MyClass::getValue() const
{
  return m_Value;
}
