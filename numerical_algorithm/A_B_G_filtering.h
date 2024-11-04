//
// Created by one on 2024/10/15.
//

#ifndef A_B_G_FILTERING_H
#define A_B_G_FILTERING_H
#include <cmath>
#include <iostream>
using namespace std;
//a-b-c滤波
//int n 量测数据的点数
//n         量测数据点数。
//x[n]      n个等间隔点上的量测值。
//t         采样周期。
//a         滤波器结构参数Alpha。
//b         滤波器结构参数Beta。
//c         滤波器结构参数Gamma。
//y[n]      返回n个等间隔点上的滤波估值。
void A_B_G_FILTERING(int n, double x[], double t, double a, double b, double c, double y[]) {
    int i;
    double s1,ss,v1,vv,a1,aa;
    aa=0.0; vv=0.0;ss=0.0;
    for (i=0; i<=n-1; i++)
    {
        s1=ss+t*vv+t*t*aa/2.0;
        v1=vv+t*aa;
        a1=aa;
        ss=s1+a*(x[i]-s1);
        y[i]=ss;
        vv=v1+b*(x[i]-s1);
        aa=a1+2.0*c*(x[i]-s1)/(t*t);
    }

}

#endif //A_B_G_FILTERING_H
