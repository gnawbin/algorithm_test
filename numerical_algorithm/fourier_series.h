//
// Created by one on 2024/10/12.
//

#ifndef FOURIER_SERIES_H
#define FOURIER_SERIES_H
#include <cmath>
#include <iostream>
using namespace std;
//n  等据点数为2n+1
//f[2n+1] 存放区间[0,2*3.141592]内的2n+1个等距点处的函数值
//a[n+1] 返回Fourier级数中的系数
//b[n+1] 返回Fourier级数中的系数
void fourier_series(int n,double f[],double a[],double b[]){
   int i,j;
   double t,c,s,c1,s1,u1,u2,u0;
   t=6.283185306/(2.0*n+1.0);
   c=cos(t);
   s=sin(t);
   t=2.0/(2.0*n+1.0);
   c1=1.0;
   s1=0.0;
   for(i=0;i<=n;i++){
     u1=0.0;
     u2=0.0;
     for(j=2*n;j>=1;j--){
        u0=f[j]+2.0*c1*u1-u2;
        u2=u1;
        u1=u0;
     }
     a[i]=t*(f[0]+u1*c1-u2);
     b[i]=t*u1*s1;
     u0=c*c1-s*s1;
     s1=c*s1+s*c1;
     c1=u0;
   }
}
#endif //FOURIER_SERIES_H
