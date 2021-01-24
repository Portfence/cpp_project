#pragma once

namespace MyLib
{
class MyClass
{
public:
  explicit MyClass(const int t_value);
  ~MyClass() = default;
  int getValue() const;
private:
  int m_Value;
};
} // namespace Mylib
