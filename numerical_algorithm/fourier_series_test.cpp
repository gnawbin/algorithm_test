//
// Created by one on 2024/10/12.
//
#include <iostream>
#include <cmath>
#include <iomanip>
#include "fourier_series.h"
int main()
{
  int i;
    double f[61],a[31],b[31],c,h;
    h=6.283185306/61.0;
    for(i=0;i<61;i++) {
        c=(i+0.5)*h;
        f[i]=c*c;

    }
    fourier_series(30,f,a,b);
    cout<<setw(5)<<"k"<<setw(20)<<"a(k)"<<setw(20)<<"b(k)"<<endl;
    for(i=0;i<=30;i++) {
        cout<<setw(5)<<i<<setw(20)<<a[i]<<setw(20)<<b[i]<<endl;
    }
    return 0;
}