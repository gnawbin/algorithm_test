//
// Created by one on 2024/10/14.
//
#include <iostream>
#include "total_pivoting_gaussian_elimination.h"
using namespace std;
int main(int argc,char *argv[])
{
    int i,j;
    double x[4],p[4][4];
    double a[4][4]={
     {0.2368,0.2471,0.2568,1.2671},
        {0.1968,0.2071,1.2168,0.2271},
        {0.1581,1.1675,0.1768,0.1871},
        {1.1161,0.1254,0.1397,0.1490}
    };
    double b[4]={1.8471,1.7471,1.6471,1.5471};
    for(i=0;i<4;i++) {
        for(j=0;j<4;j++) {
            p[i][j]=a[i][j];
        }
        x[i]=b[i];
    }
    i=total_pivoting_gaussian_elimination(&p[0][0],x,4);
    if(i!=0) {
        for(i=0;i<4;i++) {
            cout<<"x("<<i<<")="<<x[i]<<endl;
        }
    }
    Complex xx[4],pp[4][4];
    Complex aa[4][4]={
        {Complex(1.0,3.0),Complex(3.0,-2.0),Complex(2.0,1.0),
                                           Complex(13.0,6.0)},
        {Complex(7.0,-2.0),Complex(2.0,7.0),Complex(1.0,5.0),
                                            Complex(-2.0,8.0)},
        {Complex(9.0,9.0),Complex(15.0,-3.0),Complex(3.0,15.0),
                                           Complex(-2.0,1.0)},
        {Complex(-2.0,-2.0),Complex(-2.0,-2.0),Complex(11.0,7.0),
                                           Complex(5.0,6.0)}};
   Complex bb[4]={Complex(2.0,1.0),Complex(7.0,2.0),
                Complex(3.0,-2.0),Complex(9.0,3.0)};

    for (i=0; i<4; i++)
    {
        for (j=0; j<4; j++)  pp[i][j]=aa[i][j];
        xx[i]=bb[i];
    }
    i=total_pivoting_gaussian_elimination(&pp[0][0],xx,4);
    if(i!=0) {
        for(i=0;i<4;i++) {
            cout<<"xx("<<i<<")=";
            xx[i].prt();
            cout<<endl;
        }

    }

    return 0;
}
