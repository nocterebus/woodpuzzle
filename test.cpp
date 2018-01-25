/*
simple math operations
*/
#include <iostream>
#include <vector>
#include <array>

int main (int argc, char** argv){
  std::cout<<((16*3)+(4*0)+3)<<'\n';

  std::vector<std::vector<int>> imat = {{1,0,0},{0,1,0},{0,0,1}};

      imat = {{(imat[0][1]*1),(imat[0][0]*-1),(imat[0][2]*1)},
              {(imat[1][1]*1),(imat[1][0]*-1),(imat[1][2]*1)},
              {(imat[2][1]*1),(imat[2][0]*-1),(imat[2][2]*1)}};
                  imat = {{(imat[0][1]*1),(imat[0][0]*-1),(imat[0][2]*1)},
                          {(imat[1][1]*1),(imat[1][0]*-1),(imat[1][2]*1)},
                          {(imat[2][1]*1),(imat[2][0]*-1),(imat[2][2]*1)}};
                              imat = {{(imat[0][1]*1),(imat[0][0]*-1),(imat[0][2]*1)},
                                      {(imat[1][1]*1),(imat[1][0]*-1),(imat[1][2]*1)},
                                      {(imat[2][1]*1),(imat[2][0]*-1),(imat[2][2]*1)}};

  /*  imat = {{(imat[0][2]*-1),(imat[0][1]*1),(imat[0][0]*1)},
            {(imat[1][2]*-1),(imat[1][1]*1),(imat[1][0]*1)},
            {(imat[2][2]*-1),(imat[2][1]*1),(imat[2][0]*1)}};

                  imat = {{(imat[0][2]*-1),(imat[0][1]*1),(imat[0][0]*1)},
                          {(imat[1][2]*-1),(imat[1][1]*1),(imat[1][0]*1)},
                          {(imat[2][2]*-1),(imat[2][1]*1),(imat[2][0]*1)}};
                                imat = {{(imat[0][2]*-1),(imat[0][1]*1),(imat[0][0]*1)},
                                        {(imat[1][2]*-1),(imat[1][1]*1),(imat[1][0]*1)},
                                        {(imat[2][2]*-1),(imat[2][1]*1),(imat[2][0]*1)}};
                                        */
      imat = {{(imat[0][0]*1),(imat[0][2]*1),(imat[0][1]*-1)},
              {(imat[1][0]*1),(imat[1][2]*1),(imat[1][1]*-1)},
              {(imat[2][0]*1),(imat[2][2]*1),(imat[2][1]*-1)}};
                imat = {{(imat[0][0]*1),(imat[0][2]*1),(imat[0][1]*-1)},
                        {(imat[1][0]*1),(imat[1][2]*1),(imat[1][1]*-1)},
                        {(imat[2][0]*1),(imat[2][2]*1),(imat[2][1]*-1)}};
                          imat = {{(imat[0][0]*1),(imat[0][2]*1),(imat[0][1]*-1)},
                                  {(imat[1][0]*1),(imat[1][2]*1),(imat[1][1]*-1)},
                                  {(imat[2][0]*1),(imat[2][2]*1),(imat[2][1]*-1)}};

  std::cout<<"\n";
  for (int p = 0; p < 3; ++p){
    for (int q = 0; q < 3; ++q){
      std::cout<<imat[p][q];
    }
    std::cout<<"\n";
  }
  return 0;
}
