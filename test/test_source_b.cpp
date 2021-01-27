#include <cpp_project/lib_source_b.h>

#include <doctest/doctest.h>
#include <doctest/trompeloeil.hpp>


/**
 * @test getClassName return name of the class
 */
TEST_CASE("getClassName")
{
  // ARRANGE
  CppProject::LibSourceB b;
  const std::string expected = "LibSourceB";

  // ACT
  const std::string result = b.getClassName();

  // ASSERT
  REQUIRE(result == expected);
}
