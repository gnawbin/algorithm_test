//
// Created by one on 2024/11/1.
//

#ifndef SYMMETRIC_MATRICES_HOUSEHOLDER_TRANSFORMATION_H
#define SYMMETRIC_MATRICES_HOUSEHOLDER_TRANSFORMATION_H
/**
 * 用豪斯荷尔德变换为将n阶实对称矩阵约化为对称三对角阵
 * double a[n][n] 存放实对称矩阵A
 * int n 实对称矩阵A的阶数
 * double q[n][n] 返回豪斯荷尔德变换德乘积矩阵Q,在
 * double b[n] 返回对称三角阵中德主对角线元素
 * double e[n] 前n-1个元素返回对称三角阵中的次对角线元素
 * double c[n] 前n-1个元素返回对称三角阵中的次对角线元素
 */
#include <iostream>
#include <cmath>
using namespace std;
int symmetric_matrices_householder_transformation(double a[],int n,double q[],double b[],double c[]) {
 int i,j,k,u;
 double h,f,g,h2;
 for (i=0; i<n; i++)
  for (j=0; j<i-1; j++)
   if (a[i*n+j]!=a[j*n+i])
   {
    cout <<"矩阵不对称！" <<endl;  return 0;
   }
 for (i=0; i<=n-1; i++)
  for (j=0; j<=n-1; j++)
  {
   u=i*n+j; q[u]=a[u];
  }
 for (i=n-1; i>=1; i--)
 {
  h=0.0;
  if (i>1)
   for (k=0; k<=i-1; k++)
   {
    u=i*n+k; h=h+q[u]*q[u];
   }
  if (h+1.0==1.0)
  {
   c[i]=0.0;
   if (i==1) c[i]=q[i*n+i-1];
   b[i]=0.0;
  }
  else
  {
   c[i]=sqrt(h);
   u=i*n+i-1;
   if (q[u]>0.0) c[i]=-c[i];
   h=h-q[u]*c[i];
   q[u]=q[u]-c[i];
   f=0.0;
   for (j=0; j<=i-1; j++)
   {
    q[j*n+i]=q[i*n+j]/h;
    g=0.0;
    for (k=0; k<=j; k++) g=g+q[j*n+k]*q[i*n+k];
    if (j+1<=i-1)
     for (k=j+1; k<=i-1; k++) g=g+q[k*n+j]*q[i*n+k];
    c[j]=g/h;
    f=f+g*q[j*n+i];
   }
   h2=f/(h+h);
   for (j=0; j<=i-1; j++)
   {
    f=q[i*n+j];
    g=c[j]-h2*f;
    c[j]=g;
    for (k=0; k<=j; k++)
    {
     u=j*n+k;
     q[u]=q[u]-f*c[k]-g*q[i*n+k];
    }
   }
   b[i]=h;
  }
 }
 for (i=0; i<=n-2; i++) c[i]=c[i+1];
 c[n-1]=0.0;
 b[0]=0.0;
 for (i=0; i<=n-1; i++)
 {
  if ((b[i]!=0.0)&&(i-1>=0))
   for (j=0; j<=i-1; j++)
   {
    g=0.0;
    for (k=0; k<=i-1; k++)  g=g+q[i*n+k]*q[k*n+j];
    for (k=0; k<=i-1; k++)
    {
     u=k*n+j;
     q[u]=q[u]-g*q[k*n+i];
    }
   }
  u=i*n+i;
  b[i]=q[u]; q[u]=1.0;
  if (i-1>=0)
   for (j=0; j<=i-1; j++)
   {
    q[i*n+j]=0.0; q[j*n+i]=0.0;
   }
 }
 return 1;
}
#endif //SYMMETRIC_MATRICES_HOUSEHOLDER_TRANSFORMATION_H
