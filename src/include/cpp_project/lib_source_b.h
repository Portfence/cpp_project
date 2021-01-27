#pragma once

#include <string>

namespace CppProject
{
class LibSourceB
{
public:
  LibSourceB() = default;
  ~LibSourceB() = default;

  std::string getClassName() const;
private:
  std::string m_ClassName{"LibSourceB"};
};
} // namespace CppProject
