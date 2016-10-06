#include "../include/langevin.h"
//#include "langevin.cpp"
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
int main(){
  using namespace cpp_langevin_simulator;
  Langevin integrator;
  integrator.read_params();
  integrator.read_file(integrator.potential_file_name);
  while(integrator.time < integrator.tot_time){
    integrator.step();
  }
  using namespace std;
  cout<<"FINAL CONFIGURATION: " << setw(5) << "x =" << setw(5) << integrator.x  << setw(5) << "v =" << setw(5) << integrator.v <<".\n" << "See "<<  integrator.outfile_name<<" for full trajectory.\n";
  return(0);
}
