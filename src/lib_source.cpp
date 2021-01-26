#include "lib_source.h"

using namespace MyLib;

LibSource::LibSource(const int t_value) : m_Value(t_value)
{

}

int LibSource::getValue() const
{
  return m_Value;
}
