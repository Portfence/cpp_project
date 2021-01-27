#include <cpp_project/lib_source_a.h>
#include <cpp_project/lib_source_b.h>

#include <iostream>

int main()
{
  CppProject::LibSourceA a(0);
  CppProject::LibSourceB b;
  std::cout << "Conan test_package: Execute SUCCESSFUL" << std::endl;
  return 0;
}