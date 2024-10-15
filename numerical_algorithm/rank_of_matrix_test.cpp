//
// Created by one on 2024/10/15.
//
#include "rank_of_matrix.h"
#include <iostream>
#include <cmath>
using namespace std;
int main(int argc,char *argv[]) {
    double a[5][4]={
     {1.0,2.0,3.0,4.0},
        {5.0,6.0,7.0,8.0},
        {9.0,10.0,11.0,12.0},
        {13.0,14.0,15.0,16.0},
        {17.0,18.0,19.0,20.0}
    };
    cout<<"RANK="<<rank_of_matrix(&a[0][0],5,4)<<endl;
    return 0;
}