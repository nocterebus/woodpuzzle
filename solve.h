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
  std::vector<std::vector<int>> Shape;
  //next block location relative to current (zyx)(up away right) alterable
  std::vector<std::vector<int>> shape;
  //orientation in space (6 axis, 24 possible orientations)(a b c, d e f, g h i)
  std::vector<int> orientation = {1,0,0,0,1,0,0,0,1};
  //block selected as center of piece to rotate around and place
  int center = 0;

  void reorient(std::vector<int>);
  void recenter();
};

void piece::reorient(std::vector<int> axis){
  //ensure input is correct
  if (axis.size() != 9){
    std::cout<<"Unable to reorient with given orientation \n";
    return;
  }
  //ensure size of piece is correct
  if(size == 4 or size == 3){
    shape = Shape;
    int c = center;
    //iterate through piece blocks starting from current center
    for (int i = 0; i < size; ++ i){
      if (c >= size){
        c = 0;
      }
      //change next block location depending on axis orientation
      for (int i = 0; i < 3; ++ i){
        //shape[c] =
      }
      ++ c;
    }
  }
  else{
    std::cout<<"Attempted to reorient a piece that was not of size 4 or 3 \n";
    return;
  }
}

void piece::recenter(){

}

//specific classes
class Lshape : public piece{
public:
  //null constructor
  Lshape(){
    name = "L";
    size = 4;
    //hard set block locations kept in case of need of reset
    Shape = {{0,1,0},{1,0,0},{1,0,0},{-2,-1,0}};
    //starting from block 0 at [1,1,1] orientation
    shape = {{0,1,0},{1,0,0},{1,0,0},{-2,-1,0}};
  };
};

#endif
