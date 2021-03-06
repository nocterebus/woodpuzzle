/*
solve header file

By Justen Yeung
*/
#ifndef SOLVE_H_
#define SOLVE_H_

#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <chrono>
#include <random>

//general class
class piece{
private:
protected:
//initiate variables
public:
  std::string name;
  int size;
  //hard set block locations kept in case of need of reset
  //starting from block 0 at [1,0,0,0,1,0,0,0,1] orientation
  std::vector<std::vector<int>> Shape;
  //next block location relative to current (xyz)(up away right) alterable
  std::vector<std::vector<int>> shape;
  //orientation in space (xyz, 24 possible orientations)(a b c, d e f, g h i)
  std::vector<int> orient_now = {1,0,0,0,1,0,0,0,1};
  //right hand rule rotations around stated axis (counter clockwise 90degrees)
  //std::vector<int> reorient_x = {1,0,0,0,0,-1,0,1,0};
  //std::vector<int> reorient_y = {0,0,1,0,1,0,-1,0,0};
  //std::vector<int> reorient_z = {0,-1,0,1,0,0,0,0,1};
  int x_rotations = 0;
  int y_rotations = 0;
  int z_rotations = 0;
  //block selected as center of piece to rotate around and place...will be initially as 0 to start, later implement random center
  int center = 0;
  //amount of times center of piece has been changed
  int recenters = 0;
  //reset stats on piece if all placement combinations tested on current placement block
  void reset();
  //change the block of piece designated as center of piece
  void recenter();
  //rotate piece along an axis to a rotation that has not been checked yet
  void reorient();
};
//reset stats on piece if all placement combinations tested on current placement block
void piece::reset(){
  shape = Shape;
  x_rotations, y_rotations, z_rotations, center, recenters = 0;
  orient_now = {1,0,0,0,1,0,0,0,1};
}
//change the block of piece designated as center of piece
void piece::recenter(){
  ++center;
  if (center >= size){
    center = 0;
  }
  if (recenters >= size){
    std::cout<<"piece does not fit here. moving to another spot\n";
    //reset stats on piece
    reset();
  }
}
//rotate piece along an axis to a rotation that has not been checked yet
void piece::reorient(){
  //make rotation depending on number of tested rotations
  //if z rotated 4 times then piece will not fit in this spot and has made all possible rotations
  if (z_rotations >= size){
    //back at original orientation along z axis
    std::cout<<name<<" doesn't fit. changing center.\n";
    recenter();
    return;
  }
  //if back at original orientation along y axis, rotate once along z axis
  if (y_rotations >= size){
    //back at original orientation along y axis. can reset Y_rotations count to 0
    y_rotations = 0;
    //rotate along z_axis
    for (int nblock = 0; nblock < size; ++nblock){
      shape[nblock] = {(shape[nblock][1]*1),(shape[nblock][0]*-1),(shape[nblock][2]*1)};
    }

    //increase z_rotations count by 1
    ++z_rotations;
  }
  //if back at original orientation along x axis, rotate along z axis once
  if (x_rotations >= size){
    //back at original orientation along x axis. can reset x_rotations count to 0
    x_rotations = 0;
    //rotate along y_axis
    for (int nblock = 0; nblock < size; ++nblock){
      shape[nblock] = {(shape[nblock][2]*-1),(shape[nblock][1]*1),(shape[nblock][0]*1)};
    }
    //increase y_rotations count by 1
    ++y_rotations;
  }
  //else rotate piece along x_axis
  else {
    //rotate along x_axis
    for (int nblock = 0; nblock < size; ++nblock){
      shape[nblock] = {(shape[nblock][0]*1),(shape[nblock][2]*1),(shape[nblock][1]*-1)};
    }
    //increase x_rotations count by 1
    ++x_rotations;
  }
}

//specific classes
class Lshape : public piece{
public:
  //null constructor
  Lshape(){
    name = "L";
    size = 4;
    //hard set block next locations kept in case of need of reset{dx, dy, dz}
    Shape = {{0,1,0},{0,0,1},{0,0,1},{0,-1,-2}};
    //starting from block 0 at [1,0,0,0,1,0,0,0,1] orientation
    shape = {{0,1,0},{0,0,1},{0,0,1},{0,-1,-2}};
  };
};
class Tshape : public piece{
public:
  //null constructor
  Tshape(){
    name = "T";
    size = 4;
    //hard set block next locations kept in case of need of reset{dx, dy, dz}
    Shape = {{0,1,0},{0,1,0},{0,-1,1},{0,-1,-1}};
    //starting from block 0 at [1,0,0,0,1,0,0,0,1] orientation
    shape = {{0,1,0},{0,1,0},{0,-1,1},{0,-1,-1}};
  }
};
class Sshape : public piece{
public:
  //null constructor
  Sshape(){
    name = "S";
    size = 4;
    //hard set block next locations kept in case of need of reset{dx, dy, dz}
    Shape = {{0,1,0},{0,0,1},{0,1,0},{0,-2,-1}};
    //starting from block 0 at [1,0,0,0,1,0,0,0,1] orientation
    shape = {{0,1,0},{0,0,1},{0,1,0},{0,-2,-1}};
  }
};
class Pshape : public piece{
public:
  //null constructor
  Pshape(){
    name = "P";
    size = 4;
    //hard set block next locations kept in case of need of reset{dx, dy, dz}
    Shape = {{0,1,0},{0,0,1},{1,0,0},{-1,-1,-1}};
    //starting from block 0 at [1,0,0,0,1,0,0,0,1] orientation
    shape = {{0,1,0},{0,0,1},{1,0,0},{-1,-1,-1}};
  }
};
class Qshape : public piece{
public:
  //null constructor
  Qshape(){
    name = "Q";
    size = 4;
    //hard set block next locations kept in case of need of reset{dx, dy, dz}
    Shape = {{0,1,0},{0,0,1},{-1,0,0},{1,-1-1}};
    //starting from block 0 at [1,0,0,0,1,0,0,0,1] orientation
    shape = {{0,1,0},{0,0,1},{-1,0,0},{1,-1,-1}};
  }
};
class Cshape : public piece{
public:
  //null constructor
  Cshape(){
    name = "C";
    size = 4;
    //hard set block next locations kept in case of need of reset{dx, dy, dz}
    Shape = {{0,1,0},{0,0,1},{1,0,-1},{-1,-1,0}};
    //starting from block 0 at [1,0,0,0,1,0,0,0,1] orientation
    shape = {{0,1,0},{0,0,1},{1,0,-1},{-1,-1,0}};
  }
};
class Vshape : public piece{
public:
  //null constructor
  Vshape(){
    name = "V";
    size = 3;
    //hard set block next locations kept in case of need of reset{dx, dy, dz}
    Shape = {{0,1,0},{0,0,1},{0,-1,-1}};
    //starting from block 0 at [1,0,0,0,1,0,0,0,1] orientation
    shape = {{0,1,0},{0,0,1},{0,-1,-1}};
  }
};
//main solving function
//Solve(filling, filler, checked, checking)
void Solve(std::vector<std::vector<std::vector<std::string>>>* filling, std::vector<piece>* filler, std::vector<int>* checked, std::vector<int> checking){
  if (checked->at(0) == 7){
    std::cout<<"all pieces checked no answer\n";
    for (int i = 0; i < checked->size(); ++i){
      checked->at(i) = 0;
    }
    return;
  }
  //z direction
  for (int z = 0; z < filling->size(); ++z){
    //y direction
    for (int y = 0; y < filling->size(); ++y){
      //z direction
      for (int x = 0; x < filling->size(); ++x){

      }
    }
  }

  //return Solve(&filling, &filler, &checked);
}

void pout(std::vector<std::vector<std::vector<std::string>>> input){
 for (int z = 2; z >=0; --z){
   if (z == 0){
     std::cout<<"bottom layer\n";
   }
   else if (z == 1){
     std::cout<<"middle layer\n";
   }
   else if (z ==2){
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
#endif










/*
A solution (or The solution)
layer bottom
LSS
LPV
LLV
layer mid
SSQ
TPV
PPC
layer top
TQQ
TQC
TCC


*/
/*
pointer notes for future reference

void doubleValue (int* a) {
  // Double the value at the pointer
  *a = (*a )*2;
  return ;
}

int main (int argc , char ** argv ) {
  int number = 3;
  doubleValue (& number );
  // Number is now 6
  std :: cout <<" Number is now " <<number <<'\n';
  return 0;
}


*/
