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
    const double lambda = 2.5;
    integrator.set_lambda(lambda);
    const double m = 5;
    integrator.set_m(m);
    double some_positions[11] = {0.0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0};
    integrator.set_positions(some_positions, 11);
    integrator.set_dx();
//    std::cout << "integrator now contains a few numbers? "<< integrator.positions[5] << "\n";
    double forces[11] = {1.0,0.8,0.6,0.4,0.2,0.0,-0.2,-0.4,-0.6,-0.8,-1.0};//"parabolic"
    integrator.set_forces(forces, 11);
    integrator.set_pos_max(some_positions[10]);
    integrator.set_pos_min(some_positions[0]);


    WHEN("Time progresses a step"){
      THEN( "The particle position should change"){
	double x_init = x0;
	for(int i = 0; i < 10; i++){
	  integrator.step();//this should update integrator.x and move enough to matter
	}
	double new_x = integrator.x;
	REQUIRE( pow((integrator.x - x_init),2) > EPSILON);
      }
      AND_THEN("The time value should change."){
	double t_init = integrator.time;
	integrator.step();
	REQUIRE( (integrator.time - t_init) > EPSILON);
      }
    }
//    WHEN("Time progresses a ways"){}
  }
}
