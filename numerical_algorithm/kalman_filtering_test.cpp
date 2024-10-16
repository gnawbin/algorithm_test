//
// Created by one on 2024/10/15.
//
#include "kalman_filtering.h"
#include <cmath>
  #include <iostream>
  #include <iomanip>
#include "RND.h"
int main(int argc,char *argv[]) {
    int i,j,js;
    RND pp;
    double p[3][3],x[150][3],y[150][1],g[3][1],t,s;
    double f[3][3]={{1.0,0.05,0.00125},
               {0.0,1.0,0.05},{0.0,0.0,1.0}};
    double q[3][3]={{0.25,0.0,0.0},
               {0.0,0.25,0.0},{0.0,0.0,0.25}};
    double r[1][1]={0.25};
    double h[1][3]={1.0,0.0,0.0};
    for (i=0; i<=2; i++)
        for (j=0; j<=2; j++) p[i][j]=0.0;
    for (i=0; i<=149; i++)
        for (j=0; j<=2; j++) x[i][j]=0.0;
    pp = RND(0);
    for (i=0; i<149; i++) //产生150个均值为0，方差为0.25的高斯白噪声
        y[i][0] = pp.rndg(0.0,0.5);
    for (i=0; i<=149; i++)
    { t=0.05*i;
        y[i][0]=5.0-2.0*t+3.0*t*t+y[i][0];
    }
    js=kalman_filtering(3,1,150,&f[0][0],&q[0][0],&r[0][0],&h[0][0],&y[0][0],
                                      &x[0][0],&p[0][0],&g[0][0]);
    if (js==0) return 0;
    cout <<setw(5) <<"t" <<setw(10) <<"s"  <<setw(10) <<"y"
         <<setw(10) <<"x(0)" <<setw(10) <<"x(1)"
         <<setw(10) <<"x(2)" <<endl;
    for (i=0; i<=149; i=i+5)
    {
        t=0.05*i; s=5.0-2.0*t+3.0*t*t;
        cout <<setw(5) <<t <<setw(10) <<s
         <<setw(10) <<y[i][0] <<setw(10) <<x[i][0]
         <<setw(10) <<x[i][1]  <<setw(10) <<x[i][2] <<endl;
    }
    return 0;


}