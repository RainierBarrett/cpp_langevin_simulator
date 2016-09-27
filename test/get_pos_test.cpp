#include "langevin.h"
#include "catch.hpp"
#include <string>
#include <cstdlib>
#define TEST_SRC std::string("~/cpp_langevin_simulator/test/")

using namespace cpp_langevin_simulator;

SCENARIO( "Ensure the get_idx method is working properly", "[get_idx]"){

  GIVEN( "An integrator and a dummy grid"){
    const double EPSILON = 0.0005;//for double "comparisons"
    Langevin integrator;
    double lam = 0.5;
    double x0 = 0.55;
    double v0 = -1.24;
    double mass = 1.54;
    double positions[11] = {0.0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0};
    double forces[11] = {1.0,0.8,0.6,0.4,0.2,0.0,-0.2,-0.4,-0.6,-0.8,-1.0};//"parabolic"
    integrator.set_x(x0);
    integrator.set_v(v0);
    integrator.set_lambda(lam);
    integrator.set_m(mass);
    integrator.set_positions(positions, 11);
    integrator.set_forces(forces, 11);
    integrator.set_pos_size(11);
    integrator.set_pos_min(positions[0]);
    integrator.set_pos_max(positions[11]);

    WHEN("Getting the index of a known point"){
      THEN("we should get the right index"){
	REQUIRE( integrator.get_idx(0.0) == 0);//these should be exact
	REQUIRE( integrator.get_idx(0.04) == 0);//always round down
	REQUIRE( integrator.get_idx(0.50011) == 5);//always round down
	REQUIRE( integrator.get_idx(0.75) == 7);//always round down
	REQUIRE( integrator.get_idx(0.64) == 6);//always round down
      }
    }
  }
}
