//
// Created by one on 2024/11/4.
//
#include "Jacobi_Pass_Method.h"

#include <iostream>
#include <cmath>
using namespace std;
int main(int argc,char *argv[]) {
    int i,j;
    double eps, v[5][5];
    double a[5][5]={ {10.0,1.0,2.0,3.0,4.0},
                          {1.0,9.0,-1.0,2.0,-3.0},
                          {2.0,-1.0,7.0,3.0,-5.0},
                          {3.0,2.0,3.0,12.0,-1.0},
                          {4.0,-3.0,-5.0,-1.0,15.0}};
    eps=0.000001;
    i=Jacobi_Pass_Method(&a[0][0],5,&v[0][0],eps);
    if (i==0)  return 0;
    cout <<"特征值:"  <<endl;;
    for (i=0; i<=4; i++)  cout <<a[i][i] <<"    ";
    cout <<endl;
    cout <<"特征向量:" <<endl;
    for (i=0; i<=4; i++)
    {
        for (j=0; j<=4; j++)  cout <<v[i][j] <<"    ";
        cout <<endl;
    }
    return 0;

}
