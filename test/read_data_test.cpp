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
    const double EPSILON = 0.0005;//for double "comparisons"
    Langevin integrator;
    WHEN("reading the parameter file"){
      integrator.param_file_name = "test_input.txt";
      integrator.read_params();
      THEN("we expect the parameters to match up"){
	REQUIRE(integrator.x < EPSILON);
	REQUIRE(pow((integrator.v+1.0),2) < EPSILON );
	REQUIRE(pow((integrator.T-35.0),2) < EPSILON );
	REQUIRE(pow((integrator.lambda-0.55),2) < EPSILON );
	REQUIRE(pow((integrator.dt-0.05),2) < EPSILON );
	REQUIRE(pow((integrator.tot_time -4.0),2) < EPSILON );
      }
    }
  }
}
