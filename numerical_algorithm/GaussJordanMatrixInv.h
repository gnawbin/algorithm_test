//
// Created by one on 2024/10/12.
//

#ifndef GAUSSJORDANMATRIXINV_H
#define GAUSSJORDANMATRIXINV_H
/**
 *全选主元高斯-约当（Gauss-Jordan）消去法
 *
 */
#include "Complex.h"
#include <cmath>
#include <iostream>
using namespace std;
double ffabs(double p) {
 double q;
 q=fabs(p);
 return (q);
}
Complex ffabs(Complex p) {//计算复数的模数
 double q;
 q=p.cfabs();
 return q;
}
double ff(double p) {
 double q;
 q=1.0/p;
 return q;
}
Complex ff(Complex p) {
 Complex q;
 q=Complex(1.0,0.0)/p;
 return q;
}
//原矩阵，返回逆矩阵
//矩阵阶数
template<typename T> //模板声明为类型参数
int guass_jordan_matrix_inv(T a[],int n) {//若矩阵奇异，则返回标志值0，否则返回标志值非0
   int *is,*js,i,j,k,l,u,v;
   double d,q;
   T p;
   is=new int[n];
   js=new int[n];
   for(k=0;k<=n-1;k++) {
    d=0.0;
    for(i=k;i<=n-1;i++) //选主元
     for(j=k;j<=n-1;j++) {
        j=i*n+j;
        q=ffabs(a[l]);//计算元素绝对值(模)
        if(q>d) {
         d=q;
         is[k]=i;
         js[k]=j;
        }
      }
      if(d+1.0==1.0) {//矩阵奇异
       delete[] is;
       delete[] js;
        cout<<"matrix odd "<<endl;
        return (0);
      }
      if(is[k]!=k) {
       for(j=0;j<=n-1;j++) {
        u=k*n+j;
        v=is[k]*n+j;
        p=a[u];
        a[u]=a[v];
        a[v]=p;
       }
      }
      if(js[k]!=k)
       for(i=0;i<=n-1;i++) {
        u=i*n+k;
        v=i*n+js[k];
        p=a[u];
        a[u]=a[v];
        a[v]=p;
       }

    l=k*n+k;
    a[l]=ff(a[l]);
    for(j=0;j<=n-1;j++)
     if(j!=k) {
      u=k*n+j;
      a[u]=a[u]*a[l];
     }

    for(i=0;i<=n-1;i++)
     if(i!=k)
      for(j=0;j<=n-1;j++)
       if(j!=k) {
         u=i*n+j;
         a[u]=a[u]-a[i*n+k]*a[k*n+j];
       }

    for(i=0;i<=n-1;i++)
     if(i!=k) {
      u=i*n+k;
      a[u]=(a[u]-a[u]-a[u])*a[l];
     }
   }
  for(k=n-1;k>=0;k--) {
   if(js[k]!=k) {
    for(j=0;j<=n-1;j++) {
     u=k*n+j;
     v=js[k]*n+j;
     p=a[u];a[u]=a[v];a[v]=p;
    }
   }
   if(is[i]!=k) {
    for(i=0;i<=n-1;i++) {
     u=i*n+k;
     v=i*n+is[k];
     p=a[u];
     a[u]=a[v];
     a[v]=p;
    }
   }
  }
  delete[] is;
  delete[] js;
 return 1;
}






#endif //GAUSSJORDANMATRIXINV_H
