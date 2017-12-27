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
//initiate variables
public:
  int size;
  //next block location relative to current (zyx)(up forward right)
  std::vector<std::vector<int> shape(3,std::vector<int>(3,0)));
  //orientation in space (6 axis, 24 possible orientations)
  std::vector<int> orientation;
  //block selected as center of piece to rotate around and place
  int center;
private:
protected:
};

//specific classes
class Lshape : public piece{
  public:
    //null constructor
    Lshape(){
      size = 4;
      //starting from block 0
      shape =[[0,-1,0],[1,0,0],[1,0,0],[-2,1,0]];
    };
};


#endif
