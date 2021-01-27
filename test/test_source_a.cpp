#include "cpp_project/lib_source_a.h"

#include <doctest/doctest.h>
#include <doctest/trompeloeil.hpp>


/**
 * @test getValue return the value contained in class under test 
 */
TEST_CASE("GetValue")
{
  // ARRANGE
  const int expected = 2;
  CppProject::LibSourceA a(expected);

  // ACT
  const int result = a.getValue();

  // ASSERT
  REQUIRE(result == expected);
}
