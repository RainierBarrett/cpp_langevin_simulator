#include "langevin.h"
#include "catch.hpp"
#include <string>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>
#define TEST_SRC std::string("~/cpp_langevin_simulator/test/")

using namespace cpp_langevin_simulator;

SCENARIO( "Make sure our printing function works", "[printer]"){

  GIVEN( "An input file and the integrator's printer"){
    const double EPSILON = 0.0005;//for double "comparisons"
    Langevin integrator;
    std::string filename = "./pot_example.txt";
    //std::cout << "THE PLACE I AM LOOKING IS " << filename <<"\n";
    integrator.read_file(filename);
    integrator.set_x(integrator.positions[integrator.pos_size / 2]);
    integrator.set_v(10.0);
    WHEN("printing to a file"){
      for(int i = 0; i< 45; i++){
	integrator.step();	
      }
      using namespace std;
      ifstream input;
      string dataname = "output.dat";
      input.open(dataname.c_str());
      int nlines = 0;
      string line;
      for(int i = 0; std::getline(input,line);i++){
	nlines++;
      }
      THEN("we expect to have the output file exist"){
	REQUIRE( input.is_open() == true);//known number of lines
//	REQUIRE( sizeof(integrator.forces) == 200);
      }
      AND_THEN("The output file should have one line"){//just check a few points
	REQUIRE(nlines == 47);
      }
    }
  }
}
