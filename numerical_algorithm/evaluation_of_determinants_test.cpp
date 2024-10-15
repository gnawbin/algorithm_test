//
// Created by one on 2024/10/15.
//
#include "evaluation_of_determinants.h"
#include <iostream>
#include <cmath>
using namespace std;
int main(int argc,char *argv[]){
    double a[4][4]={
      {1.0,2.0,3.0,4.0},
        {5.0,6.0,7.0,8.0},
        {9.0,10.0,11.0,12.0},
        {13.0,14.0,15.0,16.0}
    };
    double b[4][4]={
      {3.0,-3.0,-2.0,4.0},
        {5.0,-5.0,1.0,8.0},
        {11.0,8.0,5.0,-7.0},
        {5.0,-1.0,-3.0,-1.0}
    };
    cout<<"det(A)="<<evaluation_of_determinants(&a[0][0],4)<<endl;
    cout<<"det(A)="<<evaluation_of_determinants(&b[0][0],4)<<endl;
    return 0;

}