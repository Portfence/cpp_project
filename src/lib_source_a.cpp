#include "lib_source_a.h"

#include <plog/Log.h>

using namespace CppProject;

LibSourceA::LibSourceA(const int t_value) : m_Value(t_value)
{

}

int LibSourceA::getValue() const
{
  return m_Value;
}
