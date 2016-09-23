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
    cout << "the number of lines is now " << nlines <<".\n";
    positions = new double[nlines];
    forces = new double[nlines];
    potentials = new double[nlines];
    int idx = 0;//a placeholder - I don't use this...
    for(int i = 0; i < nlines; i++){
      input >> idx >> positions[i] >> potentials[i] >> forces[i];
    }
    cout << "and now forces[0] = " << forces[0] << "\n";
  }
  void Langevin::step(){
    return;
  }
}
