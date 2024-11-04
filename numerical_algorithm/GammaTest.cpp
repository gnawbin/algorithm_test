//
// Created by one on 2024/11/4.
//
#include "SpecialFunction.h"
#include <cmath>
#include <iostream>
using namespace std;
int main(int argc,char *argv[]) {
    SpecialFunction special_function;
    int i;
    double x,y;
    for (i=1; i<=10; i++)
    {
        x=0.5*i; y=special_function.gamma(x);
        cout <<"x = " <<x <<"     gamma(x) = " <<y <<endl;
    }
    y =special_function. gamma(1.5)*special_function.gamma(2.5)/special_function.gamma(4.0);
    cout <<"B(1.5,2.5) = " <<y <<endl;
    return 0;

}