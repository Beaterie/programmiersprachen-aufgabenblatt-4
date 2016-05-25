#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <math.h>
#include "Vec2.hpp"
#include "color.hpp"
#include "circle.hpp"
#include "List.hpp"

TEST_CASE("test_of_List", "[List]"){
	List<int> l1;
	REQUIRE(l1.size() == 0);
	REQUIRE(l1.empty() == true);
}


int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}