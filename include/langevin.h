#include <vector>
#include <cstdlib>
#include <string>
namespace cpp_langevin_simulator{

  class Langevin{

  public:
    double x; //our position (one particle??)
    double * positions;//the "grid" positions
    double * forces;//the forces we'll use
    double * potentials;//the potential table
    void read_file(const std::string& filename);
    void step();
  };
}
