//
// Created by one on 2024/10/11.
//
#include <iostream>
#include "MatrixMulti.h"
using namespace std;
int main(int argc,char *argv[])
{
    int i,j;
    double a[4][5]={
        {1.0,3.0,-2.0,0.0,4.0},
        {-2.0,-1.0,5.0,-7.0,2.0},
        {0.0,8.0,4.0,1.0,-5.0},
        {3.0,-3.0,2.0,-4.0,1.0}
    };
    double b[5][3]={
      {4.0,5.0,-1.0},
        {2.0,-2.0,6.0},
        {7.0,8.0,1.0},
        {0.0,3.0,-5.0},
        {9.0,8.0,-6.0}
    };
    cout<<"real matrix A:"<<endl;
    for(i=0;i<=3;i++) {
        for(j=0;j<=4;j++) {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"real matrix B:"<<endl;
    for(i=0;i<=4;i++) {
        for(j=0;j<=2;j++) {
            cout<<b[i][j]<<" ";
        }
        cout<<endl;
    }
    double c[4][3];

    matrix_mul(&a[0][0],4,5,&b[0][0],5,3,&c[0][0]);
    cout<<"matrix mul C=AB:"<<endl;
    for(i=0;i<=3;i++) {
        for(j=0;j<=2;j++) {
            cout<<c[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<" complex matrix: "<<endl;
    Complex cc[3][4];
    Complex aa[3][4]={
      {Complex(1,1),Complex(2,-1),Complex(3,2),Complex(-2,1)},
        {Complex(1,-1),Complex(5,-1),Complex(1,2),Complex(3,0)},
        {Complex(0,-3),Complex(4,-1),Complex(2,2),Complex(-1,2)}
    };
    Complex bb[4][4]={
     {Complex(1.0,-1.0),Complex(4.0,-1.0),Complex(5.0,1.0),Complex(-2,1)},
        {Complex(3,2),Complex(0,1),Complex(2,0),Complex(-1,5)},
        {Complex(6,-3),Complex(3,2),Complex(1,1),Complex(2,-1)},
        {Complex(2,-1),Complex(-3,-2),Complex(-2,1),Complex(1,-2)}
    };
    cout<<"complex matrix A:"<<endl;
    for(i=0;i<3;i++) {
        for(j=0;j<4;j++) {
            aa[i][j].prt();
            cout<<" ";
        }
        cout<<endl;
    }
    cout<<" complex matrix B: "<<endl;
    for(i=0;i<4;i++) {
        for(j=0;j<4;j++) {
            bb[i][j].prt();
            cout<<"  ";
        }
        cout<<endl;
    }
   matrix_mul_complex(&aa[0][0],3,4,&bb[0][0],4,4,&cc[0][0]);
    for(i=0;i<3;i++) {
        for(j=0;j<4;j++) {
            cc[i][j].prt();
            cout<<" ";
        }
        cout<<endl;
    }
    return 0;
}