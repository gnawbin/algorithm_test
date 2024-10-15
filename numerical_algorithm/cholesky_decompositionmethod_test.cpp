//
// Created by one on 2024/10/15.
//
#include "cholesky_decompositionmethod.h"
#include <cmath>
#include <iostream>
using namespace std;
int main(int argc,char *argv[]) {
    int i,j;
    double a[4][4]={
    {5.0,7.0,6.0,5.0},
        {7.0,10.0,8.0,7.0},
        {6.0,8.0,10.0,9.0},
        {5.0,7.0,9.0,10.0}
    };
    i=cholesky_decompositionmethod(&a[0][0],4);
    if(i>0) {
        cout<<"MAT L:\n";
        for(i=0;i<4;i++) {
            for(j=0;j<4;j++)
                cout<<a[i][j]<<"  ";
            cout<<endl;
        }

    }
    return 0;
}