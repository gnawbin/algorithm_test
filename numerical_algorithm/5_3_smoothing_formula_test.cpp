//
// Created by one on 2024/10/15.
//
#include "5_3_smoothing_formula.h"
#include <iostream>
#include <iomanip>
using namespace std;
int main(int argc,char *argv[]) {
    int i;
    double y[9]={
    54.0,145.0,227.0,359.0,401.0,342.0,259.0,112.0,65.0
    };
    double yy[9];
    smoothing_formula_5_3(9,y,yy);
    for(i=0;i<=8;i++) {
        cout<<"y("<<i<<")="<<setw(6)<<y[i]
        <<"  yy("<<i<<")="<<setw(10)<<yy[i]<<endl;
    }
    return 0;
}
