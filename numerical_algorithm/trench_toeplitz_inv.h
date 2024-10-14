//
// Created by one on 2024/10/14.
//

#ifndef TRENCH_TOEPLITZ_INV_H
#define TRENCH_TOEPLITZ_INV_H
/**
* 用特兰持(Trench)求托伯利兹(Toeplitz)矩阵的逆矩阵
*/
#include <cmath>
#include <iostream>
#include "Complex.h"
using namespace std;
//t[n] 存放T型矩阵中的元素t[0]~t[n-1]
//tt[] 后n-1个元素存放T型矩阵中的元素tt[1]~t[n-1]
//b[n][n] 返回T型矩阵的逆矩阵
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
template<typename T>
int trench_toeplitz_inv(T t[],T tt[],int n,T b[]){
  int i,j,k;
    double a,s,*c,*r,*p;
    c=new double[n];
    r=new double[n];
    p=new double[n];
    if (fabs(t[0])+1.0==1.0)
	{ delete[] c; delete[] r; delete[]p;
      cout <<"fail\n"; return(0);
    }
    a=t[0]; c[0]=tt[1]/t[0]; r[0]=t[1]/t[0];
    for (k=0; k<=n-3; k++)
      { s=0.0;
        for (j=1; j<=k+1; j++) s=s+c[k+1-j]*tt[j];
        s=(s-tt[k+2])/a;
	    for (i=0; i<=k; i++) p[i]=c[i]+s*r[k-i];
        c[k+1]=-s;
        s=0.0;
        for (j=1; j<=k+1; j++) s=s+r[k+1-j]*t[j];
        s=(s-t[k+2])/a;
        for (i=0; i<=k; i++)
          { r[i]=r[i]+s*c[k-i];
            c[k-i]=p[k-i];
          }
        r[k+1]=-s;
	    a=0.0;
        for (j=1; j<=k+2; j++) a=a+t[j]*c[j-1];
        a=t[0]-a;
        if (fabs(a)+1.0==1.0)
          { delete[] c; delete[] r; delete[]p;
            cout <<"fail\n"; return(0);
          }
      }
    b[0]=1.0/a;
    for (i=0; i<=n-2; i++)
      { k=i+1; j=(i+1)*n;
        b[k]=-r[i]/a; b[j]=-c[i]/a;
      }
    for (i=0; i<=n-2; i++)
    for (j=0; j<=n-2; j++)
      { k=(i+1)*n+j+1;
        b[k]=b[i*n+j]-c[i]*b[j+1];
        b[k]=b[k]+c[n-j-2]*b[n-i-1];
      }
    delete[] c; delete[] r; delete[]p;
    return(1);
  }


#endif //TRENCH_TOEPLITZ_INV_H
