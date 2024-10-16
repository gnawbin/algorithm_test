//
// Created by one on 2024/10/15.
//
#include "A_B_G_filtering.h"
#include <cmath>
#include <iostream>
#include <iomanip>
#include "RND.h"
using namespace std;
int main(int argc,char *argv[]) {
    int i;
    double x[150],y[150],z[150];
    double a,b,c,dt,t;
    RND p;
    a=0.271; b=0.0285; c=0.0005; dt=0.04;
    p = RND(0);
    for (i=0; i<150; i++) //产生150个均值为0，方差为0.25的高斯白噪声
        y[i]= p.rndg(0.0,0.5);
    for (i=0; i<=149; i++)
    {
        t=(i+1)*dt;
        z[i]=3.0*t*t-2.0*t+5.0;
        x[i]=z[i]+y[i];
    }
    A_B_G_FILTERING_H(150,x,dt,a,b,c,y);
    for (i=0; i<=149; i=i+5)
    {
        t=(i+1)*dt;
        cout <<"t=" <<t <<"  x(t)=" <<setw(10) <<x[i] <<"  y(t)="
               <<setw(10) <<y[i] <<"  z(t)=" <<setw(10) <<z[i] <<endl;
    }
    return 0;

}