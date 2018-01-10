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
        sets[count] = imat;

        ///*
        //check for duplicates
        for (int c = count-1; c >0; --c){
          if (sets[count] == sets[c]){
            std::cout<<"equal rotation found at count="<<count<<" "<<x<<y<<z<<" and "<<"c="<<c<<" "<<(c%4)<<((c/4)/4)<<((c/16))<<'\n';
            for (int p = 0; p < 3; ++p){
              for (int q = 0; q < 3; ++q){
                std::cout<<sets[count][p][q];
              }
              std::cout<<"   ";
              for (int q = 0; q < 3; ++q){
                std::cout<<sets[c][p][q];
              }
              std::cout<<"\n";
            }
          }
        }
        //*/
        ++count;
      }

      imat = {{(imat[0][2]*-1),(imat[0][1]*1),(imat[0][0]*1)},
              {(imat[1][2]*-1),(imat[1][1]*1),(imat[1][0]*1)},
              {(imat[2][2]*-1),(imat[2][1]*1),(imat[2][0]*1)}};/*std::cout<<"rotation along y\n";
      for (int a = 0; a < 3; ++a){
        for (int b = 0; b < 3; ++b){
          std::cout<<imat[a][b];  
        }
        std::cout<<'\n';
      }*/
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
