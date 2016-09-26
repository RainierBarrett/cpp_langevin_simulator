#include "langevin.h"
#include "catch.hpp"

using namespace cpp_langevin_simulator;

SCENARIO( "Can set up integrator constants correctly", "[integrator]"){

  GIVEN( "An integrator and some constants"){
    Langevin integrator;
    const double EPSILON = 0.0005;//for double "comparisons"
    double lam = 0.5;
    double x0 = 0.55;
    double v0 = -1.24;
    double mass = 1.54;
    double positions[11] = {0.0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0};
    double forces[11] = {1.0,0.8,0.6,0.4,0.2,0.0,-0.2,-0.4,-0.6,-0.8,-1.0};//"parabolic"
    WHEN("We call the setup functions"){
      integrator.set_x(x0);
      integrator.set_v(v0);
      integrator.set_lambda(lam);
      integrator.set_m(mass);
      integrator.set_positions(positions, 11);
      integrator.set_forces(forces, 11);

      THEN( "The values should be set"){
	REQUIRE( abs(integrator.x - x0) < EPSILON);
	REQUIRE( abs(integrator.lambda - lam) < EPSILON);
	REQUIRE( abs(integrator.v - v0) < EPSILON);
	REQUIRE( abs(integrator.m - mass) < EPSILON);
	for(int i = 0; i < 11; i++){
	  REQUIRE( abs(integrator.positions[i] - positions[i]) < EPSILON);
	  REQUIRE( abs(integrator.forces[i] - forces[i]) < EPSILON);
	}
      }
    }
  }
}
