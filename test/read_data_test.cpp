#include "langevin.h"
#include "catch.hpp"
#include <string>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>
#define TEST_SRC std::string("~/cpp_langevin_simulator/test/")

using namespace cpp_langevin_simulator;

SCENARIO( "Make sure our routine for reading in params works", "[params]"){

  GIVEN( "A parameter file and our integrator"){
//    const double EPSILON = 0.0005;//for double "comparisons"
    Langevin integrator;
    std::string filename = "./test_params.txt";
    //std::cout << "THE PLACE I AM LOOKING IS " << filename <<"\n";
    WHEN("reading the parameter file"){
      integrator.read_params(filename);
      THEN("we expect x to be a little above the min"){
	REQUIRE(;
      }
    }
  }
}
