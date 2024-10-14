//
// Created by one on 2024/10/14.
//

#ifndef GAUSS_JORDAN_ELIMINATION_H
#define GAUSS_JORDAN_ELIMINATION_H
#include "Complex.h"
#include <cmath>
#include <iostream>
using namespace std;
double init(double p){
    p=0.0;
    return (p);
}
Complex init(Complex p){
    p=Complex(0.0,0.0);
    return (p);
}
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
//a[n][n] 系数矩阵，返回时被破坏
//b[n] 常数向量,返回解向量,若系数矩阵奇异，则返回0向量
//n 方程组阶数
template<typename T>
int gauss_jordan_elimination(T *a,T *b,int n) {
    int *js,k,i,j,is,p,q;
    double d,t;
    T  s;
    js=new int[n];
    for(k=0;k<=n-1;k++) {
        d=0.0;
        for(i=k;i<=n-1;i++) {
            for(j=k;j<=n-1;j++) {
                t=ffabs(a[i*n+j]);
                if(t>d) {
                    d=t;
                    js[k]=j;
                    is=i;
                }
            }
        }
        if(d+1.0==1.0) {
            cout<<"系数矩阵奇异，求解失败！！！";
            for(i=0;i<n;i++) {
                b[i]=init(s);
            }
            delete[] js;
            return 0;
        }
        if(js[k]!=k) {
            for(i=0;i<=n-1;i++) {
                p=i*n+k;
                q=i*n+js[k];
                s=a[p];
                a[p]=a[q];
                a[q]=s;
            }
        }
        if(is!=k) {
            for(j=k;j<=n-1;j++) {
                p=k*n+j;
                q=is*n+j;
                s=a[p];
                a[p]=a[q];
                a[q]=s;
            }
            s=b[k];b[k]=b[is];b[is]=s;
        }
        s=a[k*n+k];
        for(j=k+1;j<=n-1;j++) {
            p=k*n+j;
            a[p]=a[p]/s;
        }
        b[k]=b[k]/s;
        for(i=0;i<=n-1;i++) {//消元
            if(i!=k) {
                for(j=k+1;j<=n-1;j++) {
                    p=i*n+j;
                    T aa1=a[i*n+k];
                    T aa2=a[k*n+j];
                    T aa=aa1*aa2;
                    a[p]=a[p]-aa;
                }
                T aa=a[i*n+k];
                T bb=b[k];
                T aabb=aa*bb;
                b[i]=b[i]-aabb;
            }

        }

    }
    //恢复
    for(k=n-1;k>=0;k--) {
        if(js[k]!=k) {
            s=b[k];
            b[k]=b[js[k]];
            b[js[k]]=s;
        }

    }
    delete[] js;
    return 1;


}
#endif //GAUSS_JORDAN_ELIMINATION_H
