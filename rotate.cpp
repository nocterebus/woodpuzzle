/*
rotation matrix test
*/
//std::vector<int> reorient_x = {1,0,0,0,0,-1,0,1,0};
//std::vector<int> reorient_y = {0,0,1,0,1,0,-1,0,0};
//std::vector<int> reorient_z = {0,-1,0,1,0,0,0,0,1};
#include "solve.h"
std::vector<std::vector<int>> imat = {{1,0,0},{0,1,0},{0,0,1}};
std::vector<std::vector<int>> nmat = {{1,0,0},{0,1,0},{0,0,1}};
std::vector<std::vector<std::vector<int>>> sets(64,imat);
int count = 0;
int main (int argc, char** argv){
  for (int z = 0; z < 4; ++z){
    for (int y = 0; y < 4; ++y){
      for (int x = 0; x < 4; ++x){
        sets[count] = imat;

        ///*
        //check if a duplicate. if it is, don't print
        bool unseen = 1;
        for (int c = count-1; c >0; --c){
          if (sets[count] == sets[c]){
            unseen = 0;
          }
        }
        if (unseen == 1){
          std::cout<<"at "<<count<<" x:"<<x<<" y:"<<y<<" z:"<<z<<'\n';
          for (int p = 0; p < 3; ++p){
            for (int q = 0; q < 3; ++q){
              std::cout<<sets[count][p][q];
            }
            std::cout<<"\n";
          }
        }
        //*/
        imat = {{(imat[0][0]*1),(imat[0][2]*1),(imat[0][1]*-1)},
                {(imat[1][0]*1),(imat[1][2]*1),(imat[1][1]*-1)},
                {(imat[2][0]*1),(imat[2][2]*1),(imat[2][1]*-1)}};

        //std::cout<<"rotation along x\n";
        /*
        for (int j = 0; j < 3; ++j){
          for (int k = 0; k < 3; ++k){
            std::cout<<imat[j][k];
          }
          std::cout<<'\n';
        }
        */
        ++count;
      }
    }

    imat = {{(imat[0][1]*1),(imat[0][0]*-1),(imat[0][2]*1)},
            {(imat[1][1]*1),(imat[1][0]*-1),(imat[1][2]*1)},
            {(imat[2][1]*1),(imat[2][0]*-1),(imat[2][2]*1)}};/*std::cout<<"rotation along z\n";
    for (int p = 0; p < 3; ++p){
      for (int q = 0; q < 3; ++q){
        std::cout<<imat[p][q];
      }
      std::cout<<'\n';
    }*/

  }

  return 0;
}
