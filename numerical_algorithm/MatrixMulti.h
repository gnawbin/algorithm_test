//
// Created by one on 2024/10/11.
//

#ifndef MATRIXMULTI_H
#define MATRIXMULTI_H
#include "Complex.h"
#include <iostream>
using namespace std;
double init(double p) {//复数初始化
    p=0.0;
    return (p);
}
Complex init(Complex p) {
    p=Complex(0.0,0.0);
    return p;
}
//a,ma,na 矩阵A[ma][na]
//b,mb,nb 矩阵B[mb][nb]
//c，ma,nb矩阵乘积C[ma][nb]=A[ma][na]*B[mb][nb]

void matrix_mul(double   a[],int ma,int na,double  b[],int mb,int nb,double  c[]){
    int i,j,k,u;
    if(na!=mb){
        cout<<"matrix is not multiply!"<<endl;
        return;
    }
    for(i=0;i<=ma-1;i++)
        for(j=0;j<=nb-1;j++) {
            u = i * nb + j;
            c[u] = init(c[u]);
            for (k = 0; k <= mb - 1; k++) {
                double  aa=a[i * na + k];
                double bb=b[k * nb + j];
                double    cc = aa *bb;
                c[u] = c[u] + cc;
            }
        }

}
void matrix_mul_complex(Complex   a[],int ma,int na,Complex  b[],int mb,int nb,Complex  c[]){
    int i,j,k,u;
    if(na!=mb){
        cout<<"matrix is not multiply!"<<endl;
        return;
    }
    for(i=0;i<=ma-1;i++)
        for(j=0;j<=nb-1;j++) {
            u = i * nb + j;
            c[u] = init(c[u]);
            for (k = 0; k <= mb - 1; k++) {
                Complex  aa=a[i * na + k];
                Complex bb=b[k * nb + j];
               Complex    cc = aa *bb;
                c[u] = c[u] + cc;
            }
        }

}
#endif //MATRIXMULTI_H
