//
// Created by one on 2024/11/4.
//
#include "eigenvector_corresponding_to_the_maximum_eigenvalue_of_power.h"
int main(int argc,char *argv) {
    int i;
    double a1[3][3] = {{0,1,1.5},{-5,-0.5,1},{-1,2,3.5}};
    double a2[3][3] = {{-5,1,5},{1,0,0},{0,1,0}};
    double v[3] = {0,0,1};
    double lambda;
    lambda = power(3, &a1[0][0], 0.0000001, v);
    cout <<"绝对值最大的特征值 lambda1 = " <<lambda <<endl;
    for (i=0; i<3; i++)
        cout <<"v(" <<i <<")= " <<v[i] <<endl;
    cout <<endl;
    lambda = power(3, &a2[0][0], 0.0000001, v);
    cout <<"绝对值最大的特征值 lambda2 = " <<lambda <<endl;
    for (i=0; i<3; i++)
        cout <<"v(" <<i <<")= " <<v[i] <<endl;
    return 0;

}