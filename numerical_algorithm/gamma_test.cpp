//
// Created by one on 2024/10/15.
//
#include "gamma.h"
#include <iostream>
#include <cmath>
using namespace std;
int main(int argc,char *argv[]) {
    int i;
    double x,y;
    for(i=1;i<=10;i++) {
        x=0.5*i;
        y=gamma(x);
        cout<<"x="<<x<<" gamma(x)="<<y<<endl;
    }
    y=gamma(1.5)*gamma(2.5)/gamma(4.0);
    cout<<"B(1.5,2.5)="<<y<<endl;
    return 0;
}