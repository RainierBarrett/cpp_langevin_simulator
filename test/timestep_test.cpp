#include "langevin.h"
#include "catch.hpp"

using namespace cpp_langevin_simulator;

SCENARIO( "Integrator can move the particle in a step", "[integrator]"){

  GIVEN( "An integrator"){
    Langevin integrator;
    const double EPSILON = 0.00001;//for double "comparisons"
    const double x0 = 0.0;
    const double v0 = 1.0;
    const double lambda = 0.5;
    const double forces[11] = {1.0,0.8,0.6,0.4,0.2,0.0,-0.2,-0.4,-0.6,-0.8,-1.0};//"parabolic"
    const double timestep = 0.1;
    WHEN("Time progresses a step"){
      THEN( "The particle position should change"){
	double x_init = x0;
	for(int i = 0; i < 10; i++){
	  integrator.step();//this should update integrator.x and move enough to matter
	}
	double new_x = integrator.x;
	REQUIRE( abs(new_x - x_init) < EPSILON);
      }
    }
  }
}
