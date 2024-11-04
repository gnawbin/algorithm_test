//
// Created by one on 2024/11/4.
//
#include "SpecialFunction.h"
#include <iostream>
#include <iomanip>
using namespace std;
int main(int argc ,char *argv[]) {
   SpecialFunction p;
    int i,j;
    double x,y;
    x = 0.0;  y = p.errf(x);
    cout <<setw(15) <<y <<endl;
    for (i=0; i<=7; i++)
    {
        for (j=0; j<=4; j++)
        {
            x = x + 0.05;   y=p.errf(x);
            cout <<setw(15) <<y;
        }
        cout <<endl;
    }
    return 0;

}