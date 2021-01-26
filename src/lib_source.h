#pragma once

namespace MyLib
{
class LibSource
{
public:
  explicit LibSource(const int t_value);
  ~LibSource() = default;
  int getValue() const;
private:
  int m_Value;
};
} // namespace Mylib
