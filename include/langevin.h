#include <vector>
#include <cstdlib>
#include <string>
namespace cpp_langevin_simulator{

  class Langevin{

  public:
    double x; //our position (one particle??)
    void set_x(double new_x);//sets the position, called in setup and main loop
    double v; //the velocity
    void set_v(double new_v);//sets the velocity, called in setup and main loop
    double lambda;//The damping term
    void set_lambda(double new_lambda);//sets the lambda, called in setup
    double m;//The big particle mass
    void set_m(double new_m);//sets the mass, called in setup
    double dt = 0.0001;//The length of each timestep
    double * positions;//the "grid" positions
    double * forces;//the forces we'll use
    double * potentials;//the potential table
    void read_file(const std::string& filename);//reads in the positions, potentials, and forces.
    void step();
    int get_idx(double x);
  };
}
