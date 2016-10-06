#include "../include/langevin.h"
#include <cstdlib>
#include <math.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <string>
#include <boost/random.hpp>
#include <boost/random/normal_distribution.hpp>
#include <ctime>
namespace cpp_langevin_simulator{
  
  void Langevin::read_file(const std::string& filename){
    using namespace std;
    ifstream input;
    input.open(filename.c_str());
    int nlines = 0;
    string line;
    if(!input.is_open()){cout <<"UH OH.\n";}
    for(int i = 0; std::getline(input,line);i++){
      nlines++;
    }
    set_pos_size(nlines);
    input.close();
    input.open(filename.c_str());
    /*cout << "Please enter the number of lines in target file.\n";
      cin >> nlines;*/
    //cout << "the number of lines is now " << nlines <<".\n";
    positions = new double[nlines];
    forces = new double[nlines];
    potentials = new double[nlines];
    int idx = 0;//a placeholder - I don't use this...
    for(int i = 0; i < nlines; i++){
      input >> idx >> positions[i] >> potentials[i] >> forces[i];
    }
    set_pos_min(positions[0]);
    set_pos_max(positions[pos_size -1]);
    set_dx();
    //cout << "and now forces[0] = " << forces[0] << "\n";
  }

  void Langevin::set_pos_size(int size){
    pos_size = size;
    return;
  }

  void Langevin::set_pos_min(double min){
    pos_min = min;
    return;
  }

  void Langevin::set_pos_max(double max){
    pos_max = max;
    return;
  }

  void Langevin::set_x(double new_x){
    const double EPSILON = 0.0005;//for double "comparisons"
    if(new_x > pos_max){
      x = ((new_x - (pos_max - pos_min)));
    }
    else if(new_x < pos_min){
        x = (new_x + (pos_max - pos_min));
    }
    else{
      x = new_x;
    }
    
    return;
  }

  void Langevin::set_v(double new_v){
    v = new_v;
    return;
  }

  void Langevin::set_m(double new_m){
    m = new_m;
    return;
  }

  void Langevin::set_lambda(double new_lambda){
    lambda = new_lambda;
    return;
  }

  void Langevin::set_positions(double * positions_arr, int length){
    positions = (double *)malloc(length * sizeof(double));
    for(int i = 0; i < length; i++){
      positions[i] = positions_arr[i];
    }
//    set_pos_min(positions_arr[0]);
//    set_pos_max(positions_arr[length]);
    return;
  }

  void Langevin::set_forces(double * forces_arr, int length){
    forces = (double *)malloc(length * sizeof(double));
    for(int i = 0; i < length; i++){
      forces[i] = forces_arr[i];
    }
    return;
  }

  void Langevin::set_potentials(double * potentials_arr, int length){
    potentials = (double *)malloc(length * sizeof(double));
    for(int i = 0; i < length; i++){
      potentials[i] = potentials_arr[i];
    }
    return;
  }

  //return the grid index given a location
  int Langevin::get_idx(double spot){
//    return(x == 0 ? 0 : fmod(fmod(x, pos_max), ((pos_size-1)/ (pos_max - pos_min))));
    //a lazy brute-force way of finding the idx
    const double EPSILON = 0.0005;//for double "comparisons"
    set_dx();
//    std::cout << "dx is " << dx << "\n";
//    for(int i = 0; i < pos_size; i++){
//      if((((spot*10 - positions[i]*10) - dx*10) <= EPSILON*10)){
//	return(i);
//    }
//    std::cout<< "the minimum position is "<<pos_min << "and dx is " << dx <<"\n";
//    int idx = (int(floor((spot - pos_min) / dx)));
//    double remainder = fmod(spot, dx);
//    double near_bottom_point = (spot - remainder);
    for(int i = 0; i < pos_size; i++){
      if(fabs(positions[i] - spot) < dx){
//	std::cout<<"The size of the positions array is " << pos_size <<".\n";
	return(i);
      }
    }
  }

  void Langevin::set_dx(){
    dx = positions[1] - positions[0];
    return;
  }


  //seeding the RNG
  void Langevin::seed_rng(){
    rng.seed(static_cast<unsigned int>(std::time(0)));
    return;
    }
  //the gaussian process term
  double Langevin::eta(){//should make some way to have the distro be class member. Later.
    boost::normal_distribution<> nd(0.0,1.0);
    boost::variate_generator<boost::mt19937&, boost::normal_distribution<> > var_nor(rng, nd);
    double number = var_nor();
    return(number);
  }
  
  //A simple Euler-integrated Langevin timestep. Updates the position and velocity.
  void Langevin::step(){
    using namespace std;
    int idx = get_idx(x);
    if(time == 0){
      outfile.open(outfile_name.c_str());
      outfile<<setw(5)<<"Index"<<setw(10)<<"Time"<<setw(15)<<"Position" <<setw(15) << "Velocity\n";
      outfile << setw(5) << idx<< setw(10) <<  time << setw(15) << x << setw(15) << v << endl;
    }

    double tot_force = -lambda * v + eta() - forces[idx]/m;
    double new_x = x + dt*v;
    set_x(new_x);
    idx = get_idx(x);
//    std:: cout << "New x value is " << new_x << "\n";
    double new_v = v + dt * tot_force;
    set_v(new_v);
    time += dt;
    outfile << setw(5) << idx<< setw(10) <<  time << setw(15) << x << setw(15) << v << endl;

  }
}
