/*
3 x 3 wood puzzle solver

By Justen Yeung
*/
#include "solve.h"

//initialize containing cube
std::vector<std::string> emptycolumn = {"0", "0", "0"};
std::vector<std::vector<std::string>> emptylayer(3,emptycolumn);
std::vector<std::vector<std::vector<std::string>>> cube(3, emptylayer);
//initialize all shapes
Lshape L;
Tshape T;
Sshape S;
Pshape P;
Qshape Q;
Cshape C;
Vshape V;
//place pieces into vector
std::vector<piece> filler = {L,T,S,P,Q,C,V};
//initialize vector that keeps track of checked pieces
std::vector<int> checked = {7,7,7,7,7,7,7};
//which place currently being checked (x,y,z)
std::vector<int> checking = {0,0,0};
//start at bottom to try filling pieces from
int dz,dy,dx = 0;


int main (int argc, char** argv){

  pout(cube);
  for (int block = 0; block < L.size; ++block){
    dx += L.shape.at(block).at(0);
    dy += L.shape.at(block)[1];
    dz += L.shape.at(block)[2];
    cube[dz][dy][dx] = L.name;
  }
  Solve(&cube, &filler, &checked, checking);
  pout(cube);

  return 0;
}
