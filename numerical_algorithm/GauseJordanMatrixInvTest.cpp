//
// Created by one on 2024/10/12.
//
#include <iostream>
#include <cmath>
#include <iostream>
#include "GaussJordanMatrixInv.h"
using namespace std;
int main(int argc,char *argv[])
{
     int i,j;
     double a[4][4]={
         {0.2368,0.2471,0.2568,1.2671},
         {1.1161,0.1254,0.1397,0.1490},
         {0.1582,1.1675,0.1768,0.1871},
         {0.1968,0.2071,1.2168,0.2271}
     };
    double b[4][4];
    for(i=0;i<4;i++) {
        for(j=0;j<4;j++) {
            b[i][j]=a[i][j];
        }
    }
   i=guass_jordan_matrix_inv(&b[0][0],4);
  //  if(i!=0) {
        cout<<"real matrix A:"<<endl;
        for(i=0;i<4;i++) {
            for(j=0;j<4;j++){
                cout<<a[i][j]<<" ";
            }
            cout<<endl;
        }
 //   }
 //   std::cout << "Hello, World!" << std::endl;
    return 0;
}
