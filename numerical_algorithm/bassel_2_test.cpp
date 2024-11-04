//
// Created by one on 2024/11/4.
//
#include "SpecialFunction.h"
#include <cmath>
#include <iostream>
#include <iomanip>
using namespace std;
int main(int argc,char *argv[]) {
    SpecialFunction p;
    int n,i;
    double x,y;
    for (n=0; n<=5; n++)
    {
        x=0.05;
        for (i=1; i<=4; i++)
        {
            y=p.bessel_2(n,x);
            cout <<"n=" <<n <<"   x=" <<setw(5) <<x
                 <<"    Y(n,x)=" <<y <<endl;
            x=x*10.0;
        }
    }
    return 0;

}