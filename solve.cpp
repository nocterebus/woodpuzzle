/*
3 x 3 wood puzzle solver

By Justen Yeung
*/
#include "solve.h"


void pout(std::vector<std::vector<std::vector<std::string>>> input){
 for (int z = 0; z < 3; ++z){
   if (z == 0){
     std::cout<<"bottom layer\n";
   }
   else if (z == 1){
     std::cout<<"middle layer\n";
   }
   else {
     std::cout<<"top layer\n";
   }
   for (int y = 2; y >= 0; --y){
     for (int x = 0; x < 3; ++x){
       std::cout<<input[z][y][x];
     }
     std::cout<<"\n";
   }
   std::cout<<"\n";
 }
}
int main (int argc, char** argv){
  std::vector<std::string> emptycolumn = {"0", "0", "0"};
  std::vector<std::vector<std::string>> emptylayer(3,emptycolumn);
  std::vector<std::vector<std::vector<std::string>>> cube(3, emptylayer);
  Lshape L;
  pout(cube);
  std::cout<<L.size<<"\n";
  std::cout<<L.shape[0][1]<<"\n";
  int dz,dy = 0;
  int dx = 1;
  for (int block = 0; block < L.size; ++block){
    dz += L.shape.at(block).at(0);
    dy += L.shape.at(block)[1];
    dx += L.shape.at(block)[2];
    cube[dz][dy][dx] = L.name;
  }
  pout(cube);
  std::cout<<L.name;
  return 0;
}
