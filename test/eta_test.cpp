#define CATCH_CONFIG_MAIN
#include "langevin.h"
#include "catch.hpp"
#include <string>
#include <cstdlib>
#include <unistd.h>
#define TEST_SRC std::string("~/cpp_langevin_simulator/test/")

using namespace cpp_langevin_simulator;

SCENARIO( "Make sure eta function is random enough", "[eta]"){

  GIVEN( "An input file"){
    const double EPSILON = 0.0005;//for double "comparisons"
    Langevin integrator;
    std::string filename = "./pot_example.txt";
    integrator.read_file(filename);
    WHEN("making random numbers"){
      double eta1 = integrator.eta();
//      sleep(1);
      double eta2 = integrator.eta();
//      sleep(1);
      double eta3 = integrator.eta();
      THEN("we should get lots of different results"){
	REQUIRE( eta1 != eta2);//known number of lines
	REQUIRE( eta1 != eta3);
	REQUIRE( eta2 != eta3);
      }
    }
  }
}
