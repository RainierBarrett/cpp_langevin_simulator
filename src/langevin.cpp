#include "../include/langevin.h"
#include <cstdlib>
#include <math.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <string>
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
    x = new_x;
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
    forces = (double *)malloc(length * sizeof(double));
    for(int i = 0; i < length; i++){
      potentials[i] = potentials_arr[i];
    }
    return;
  }

  //return the grid index given a location
  int Langevin::get_idx(double spot){
//    return(x == 0 ? 0 : fmod(fmod(x, pos_max), ((pos_size-1)/ (pos_max - pos_min))));
    //a lazy brute-force way of finding the idx
    double dx = abs(positions[1] - positions[0]);//I assume an even grid (I sure hope so)
    const double EPSILON = 0.0005;//for double "comparisons"
    std::cout << "dx is " << dx << "\n";
    for(int i = 0; i < pos_size; i++){
      if((((spot - positions[i]) - dx) < EPSILON)){
	return(i);
      }
    }
    return(-1);
  }

  //the gaussian process term
  double Langevin::eta(){
    return(1.0);
  }
  
  //A simple Euler-integrated Langevin timestep. Updates the position and velocity.
  void Langevin::step(){
    int idx = get_idx(x);
    double tot_force = -lambda * v + eta() - forces[get_idx(x)];
    x += dt * v;
    v += dt * tot_force;
  }
}
