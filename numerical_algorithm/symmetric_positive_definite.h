//
// Created by one on 2024/10/14.
//

#ifndef SYMMETRIC_POSITIVE_DEFINITE_H
#define SYMMETRIC_POSITIVE_DEFINITE_H
#include <cmath>
#include <iostream>
#include "Complex.h"
using namespace std;
double ffabs(double p) {
    double q;
    q=fabs(p);
    return q;
}
double ffabs(Complex p) {
    double q;
    q=p.cfabs();
    return q;
}
//double a[n][n] 对称正定矩阵A,返回其逆矩阵A-
//int n 矩阵阶数
template <typename T>
int symmetric_positive_definite(T  a[],int n) {
    //函数返回标志值,等于0表示失败,大于0表示成功
    int i,j,k,m;
    double w,g,*b;
    b=new double[n];
    for (k=0; k<=n-1; k++)
    { w=a[0];
        if (ffabs(w)+1.0==1.0)
        { delete[] b; cout <<"fail\n"; return(0);}
        m=n-k-1;
        for (i=1; i<=n-1; i++)
        { g=a[i*n]; b[i]=g/w;
            if (i<=m) b[i]=-b[i];
            for (j=1; j<=i; j++)
                a[(i-1)*n+j-1]=a[i*n+j]+g*b[j];
        }
        a[n*n-1]=1.0/w;
        for (i=1; i<=n-1; i++)
            a[(n-1)*n+i-1]=b[i];
    }
    for (i=0; i<=n-2; i++)
        for (j=i+1; j<=n-1; j++)
            a[i*n+j]=a[j*n+i];
    delete[] b;
    return(1);


}
#endif //SYMMETRIC_POSITIVE_DEFINITE_H
