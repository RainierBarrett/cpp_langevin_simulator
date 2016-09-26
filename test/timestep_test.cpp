#include "langevin.h"
#include "catch.hpp"

using namespace cpp_langevin_simulator;

SCENARIO( "Integrator can move the particle in a few steps'", "[integrator]"){

  GIVEN( "An integrator"){
    Langevin integrator;
    const double EPSILON = 0.0005;//for double "comparisons"
    const double x0 = 0.0;
    integrator.set_x(x0);
    const double v0 = 1.0;
    integrator.set_v(v0);
    const double lambda = 0.5;
    integrator.set_lambda(lambda);
    const double m = 5;
    integrator.set_m(m);
    double positions[11] = {0.0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0};
    integrator.set_positions(positions, 11);
    double forces[11] = {1.0,0.8,0.6,0.4,0.2,0.0,-0.2,-0.4,-0.6,-0.8,-1.0};//"parabolic"
    integrator.set_forces(forces, 11);
    const double timestep = 0.1;
    WHEN("Time progresses a step"){
      THEN( "The particle position should change"){
	double x_init = x0;
	for(int i = 0; i < 10; i++){
	  integrator.step();//this should update integrator.x and move enough to matter
	}
	double new_x = integrator.x;
	REQUIRE( abs(integrator.x - x_init) > EPSILON);
      }
    }
//    WHEN("Time progresses a ways"){}
  }
}
