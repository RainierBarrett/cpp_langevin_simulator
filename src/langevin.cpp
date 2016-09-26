#include "../include/langevin.h"
#include <cstdlib>
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
    //cout << "and now forces[0] = " << forces[0] << "\n";
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

  void set_lambda(double new_lambda){
    lambda = new_lambda;
    return;
  }
  
  //A simple Euler-integrated Langevin timestep. Updates the position and velocity.
  void Langevin::step(){
    int idx = get_idx(x);
    x += dt * v;
    v += dt * forces[idx]/m;
  }
}
