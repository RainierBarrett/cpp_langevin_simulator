#include <vector>
#include <boost/random.hpp>
#include <boost/random/normal_distribution.hpp>
#include <cstdlib>
#include <string>
#include <fstream>

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

    double T;//no set method for this guy, he's read right from the input.
        
    double dt;//The length of each timestep-- no set method, it's got a default value only.

    double tot_time;
    
    double dx;//the change between grid points

    double time;//The amount of "time" since sim started
    void set_dx();

    int pos_size;//the number of indices we have -- the same as the lines in the input file
    void set_pos_size(int size);
    double * positions;//the "grid" positions
    void set_positions(double * positions_arr, int length);//for testing
    double * forces;//the forces we'll use
    void set_forces(double * forces_arr, int length);//for testing
    double * potentials;//the potential table
    void set_potentials(double * potentials_arr, int length);//for testing
    
    void read_file(const std::string& filename);//reads in the positions, potentials, and forces.

    double pos_min;
    void set_pos_min(double min);
    double pos_max;
    void set_pos_max(double max);

    boost::mt19937 rng;
    void seed_rng();
    
    void step();//a single timestep in the simulation
    double eta();
    int get_idx(double spot);
    std::string outfile_name;
    std::ofstream outfile;

    std::string param_file_name;
    std::ifstream param_file;

    std::string potential_file_name;
    std::ifstream potential_file;

    void read_params();
    
  Langevin() : T(1.0), m(1), dt(0.01), tot_time(10.0), time(0.0), lambda(3.0), outfile_name("output.dat"), param_file_name("input.txt") {}
  };
}
