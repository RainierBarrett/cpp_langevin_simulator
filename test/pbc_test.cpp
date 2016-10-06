#include "langevin.h"
#include "catch.hpp"
#include <string>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>
#define TEST_SRC std::string("~/cpp_langevin_simulator/test/")

using namespace cpp_langevin_simulator;

SCENARIO( "Make sure our PBCs are working", "[PBCs]"){

  GIVEN( "An input file with negative x-values"){
    const double EPSILON = 0.0005;//for double "comparisons"
    Langevin integrator;
    std::string filename = "./negative_axis_pot.txt";
    //std::cout << "THE PLACE I AM LOOKING IS " << filename <<"\n";
    integrator.read_file(filename);
    WHEN("setting x above the max"){
      integrator.set_x(integrator.pos_max + 1);
      THEN("we expect x to be a little above the min"){
	REQUIRE(pow((integrator.x - integrator.pos_min - 1),2) < EPSILON);
//	REQUIRE( sizeof(integrator.forces) == 200);
      }
      
      AND_THEN("we expect x to be a little below the max"){
	integrator.set_x(integrator.pos_min - 1);
	REQUIRE(pow((integrator.pos_max - integrator.x - 1),2) < EPSILON);
//	REQUIRE( sizeof(integrator.forces) == 200);
      }
    }
  }
}
