//
// Created by one on 2024/10/15.
//
#include "household_transformation_qr_decomposition.h"
#include <cmath>
#include <iostream>
int main(int argc,char* argv[]) {
    int i,j;
    double r[4][3],q[4][4],a[4][3]={ {1.0,1.0,-1.0},
    {2.0,1.0,0.0},
    {1.0,-1.0,0.0},
    {-1.0,2.0,1.0}};
    for (i=0; i<=3; i++)
        for (j=0; j<=2; j++)   r[i][j]=a[i][j];
    i=household_transformation_qr_decomposition(&r[0][0],4,3,&q[0][0]);
    if (i==0) return 0;
    cout <<"MAT Q:\n";
    for (i=0; i<=3; i++)
    {
        for (j=0; j<=3; j++)  cout <<q[i][j] <<"    ";
        cout <<endl;
    }
    cout <<"MAT R:\n";
    for (i=0; i<=3; i++)
    {
        for (j=0; j<=2; j++)  cout <<r[i][j] <<"    ";
        cout <<endl;
    }
    return 0;

}