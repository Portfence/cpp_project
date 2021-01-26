#pragma once

namespace CppProject
{
class LibSourceA
{
public:
  explicit LibSourceA(const int t_value);
  ~LibSourceA() = default;
  int getValue() const;
private:
  int m_Value;
};
} // namespace CppProject
