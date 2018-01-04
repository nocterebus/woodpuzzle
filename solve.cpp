/*
3 x 3 wood puzzle solver

By Justen Yeung
*/
#include "solve.h"

int main (int argc, char** argv){
  std::vector<std::string> emptycolumn = {"0", "0", "0"};
  std::vector<std::vector<std::string>> emptylayer(3,emptycolumn);
  std::vector<std::vector<std::vector<std::string>>> cube(3, emptylayer);
  Lshape L;
  pout(cube);
  std::cout<<"Size of L : "<<L.size<<"\n";
  std::cout<<L.shape[0][1]<<"\n";
  int dz,dy = 0;
  int dx = 1;
  for (int block = 0; block < L.size; ++block){
    dx += L.shape.at(block).at(0);
    dy += L.shape.at(block)[1];
    dz += L.shape.at(block)[2];
    cube[dz][dy][dx] = L.name;
  }
  pout(cube);
  std::cout<<L.name<<"\n";

  return 0;
}
