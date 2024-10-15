//
// Created by one on 2024/10/15.
//
#include "triangular_decomposition_of_matrices.h"
#include <iostream>
using namespace std;

int main(int argc,char *argv[]) {
  int i,j;
  double l[4][4],u[4][4];
  double a[4][4]={
     {2.0,4.0,4.0,2.0},
      {3,3,12,6},
      {2,4,-1,2},
      {4.0,2.0,1.0,1.0}
  };
    i=triangular_decomposition_of_matrices(&a[0][0],4,&l[0][0],&u[0][0]);
    if(i>0) {
        cout<<"MAT L"<<endl;
        for(i=0;i<4;i++) {
            for(j=0;j<4;j++) {
                cout<<l[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<"MAT U"<<endl;
        for(i=0;i<4;i++) {
            for(j=0;j<4;j++) {
                cout<<u[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}