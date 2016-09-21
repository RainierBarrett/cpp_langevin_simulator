#include "langevin.h"
#include "catch.hpp"

using namespace std;

SCENARIO( "Make sure built-in file reader can parse known example file properly", "[reader]"){

  GIVEN( "An input file and the integrator's reader"){
    Langevin integrator;
    string filename = "pot_example.txt";
    integrator.read_file(filename);
    WHEN("reading from a file"){
      THEN("we should get correct array lengths"){
	REQUIRE( sizeof(integrator.potentials) == 200);//known number of lines
	REQUIRE( sizeof(integrator.forces) == 200);
      }
    }
  }
}
