//
// Created by one on 2024/11/4.
//

#ifndef JACOBI_PASS_METHOD_H
#define JACOBI_PASS_METHOD_H
#include <iostream>
#include <cmath>
using namespace std;
//a[n][n]     实对称矩阵。对角线元素返回特征值。
//v[n][n]     返回特征向量
//eps         精度要求
  //若矩阵不对称，则显示错误信息，并返回0标志值。
int Jacobi_Pass_Method(double a[],int n,double v[],double eps) {
  int i,j,p,q,u,w,t,s;
  double ff,fm,cn,sn,omega,x,y,d;
  for (i=0; i<n; i++)
    for (j=i+1; j<n; j++)
      if (a[i*n+j]!=a[j*n+i])
      {
        cout <<"矩阵不对称！" <<endl;  return 0;
      }
  for (i=0; i<=n-1; i++)      //特征向量初始化
  {
    v[i*n+i]=1.0;
    for (j=0; j<=n-1; j++)
      if (i!=j) v[i*n+j]=0.0;
  }
  ff=0.0;
  for (i=1; i<=n-1; i++)
    for (j=0; j<=i-1; j++)
    {
      d=a[i*n+j]; ff=ff+d*d;
    }
  ff=sqrt(2.0*ff);
  ff=ff/(1.0*n);
  while (ff>=eps)
  {
    d=0.0;
    for (i=1; (i<=n-1)&&(d<=ff); i++)
      for (j=0; (j<=i-1)&&(d<=ff); j++)
      {
        d=fabs(a[i*n+j]);
        p=i; q=j;
      }
    if (d<=ff)  ff=ff/(1.0*n);
    else
    {
      u=p*n+q; w=p*n+p; t=q*n+p; s=q*n+q;
      x=-a[u]; y=(a[s]-a[w])/2.0;
      omega=x/sqrt(x*x+y*y);
      if (y<0.0) omega=-omega;
      sn=1.0+sqrt(1.0-omega*omega);
      sn=omega/sqrt(2.0*sn);
      cn=sqrt(1.0-sn*sn);
      fm=a[w];
      a[w]=fm*cn*cn+a[s]*sn*sn+a[u]*omega;
      a[s]=fm*sn*sn+a[s]*cn*cn-a[u]*omega;
      a[u]=0.0; a[t]=0.0;
      for (j=0; j<=n-1; j++)
        if ((j!=p)&&(j!=q))
        {
          u=p*n+j; w=q*n+j;
          fm=a[u];
          a[u]=fm*cn+a[w]*sn;
          a[w]=-fm*sn+a[w]*cn;
        }
      for (i=0; i<=n-1; i++)
        if ((i!=p)&&(i!=q))
        {
          u=i*n+p; w=i*n+q;
          fm=a[u];
          a[u]=fm*cn+a[w]*sn;
          a[w]=-fm*sn+a[w]*cn;
        }
      for (i=0; i<=n-1; i++)
      {
        u=i*n+p; w=i*n+q;
        fm=v[u];
        v[u]=fm*cn+v[w]*sn;
        v[w]=-fm*sn+v[w]*cn;
      }
    }
  }
  return 1;

}
#endif //JACOBI_PASS_METHOD_H
