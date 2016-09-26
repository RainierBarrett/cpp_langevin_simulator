#include "langevin.h"
#include "catch.hpp"
#include <string>
#include <cstdlib>
#define TEST_SRC std::string("~/cpp_langevin_simulator/test/")

using namespace cpp_langevin_simulator;

SCENARIO( "Make sure built-in file reader can parse known example file properly", "[reader]"){

  GIVEN( "An input file and the integrator's reader"){
    const double EPSILON = 0.0005;//for double "comparisons"
    Langevin integrator;
    std::string filename = "./pot_example.txt";
    //std::cout << "THE PLACE I AM LOOKING IS " << filename <<"\n";
    integrator.read_file(filename);
    WHEN("reading from a file"){
      THEN("we should get correct array lengths"){
	int nlines = 0;
	REQUIRE( integrator.pos_size == 200);//known number of lines
//	REQUIRE( sizeof(integrator.forces) == 200);
      }
      AND_THEN("We should have the right numbers"){//just check a few points
	REQUIRE( (integrator.forces[0] + 0.113475) < EPSILON );
	REQUIRE( (integrator.potentials[50] - 0.012177) < EPSILON);
      }
      AND_THEN("The max and min should be set properly"){
	REQUIRE( integrator.pos_min == integrator.positions[0]);
	REQUIRE( integrator.pos_max == integrator.positions[integrator.pos_size -1]);
      }
    }
  }
}
