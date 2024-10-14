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

double ffabs(double p)        //计算实数的绝对值
{
 double q;
 q = fabs(p);
 return(q);
}
double ffabs(Complex p)      //计算复数的模
{
 double q;
 q = p.cfabs();
 return(q);
}
double ff(double p)         //计算1.0/p
{
 double q;
 q = 1.0/p;
 return(q);
}
Complex ff(Complex p)       //计算(1+j0)/p
{
 Complex q;
 q = Complex(1.0, 0.0)/p;
 return(q);
}
//原矩阵，返回逆矩阵
//矩阵阶数
template<typename T> //模板声明为类型参数
int guass_jordan_matrix_inv(T a[],int n) {//若矩阵奇异，则返回标志值0，否则返回标志值非0
 int *is,*js,i,j,k,l,u,v;
 double d, q;
 T p;
 is=new int[n];
 js=new int[n];
 for (k=0; k<=n-1; k++)
 {
  d=0.0;
  for (i=k; i<=n-1; i++)      //选主元
   for (j=k; j<=n-1; j++)
   {
    l=i*n+j;
    q = ffabs(static_cast<T>(a[l]));        //计算元素绝对值（模）
    if (q>d) { d=q; is[k]=i; js[k]=j;}
   }
  if (d+1.0==1.0)            //矩阵奇异
  {
   delete[] is; delete[] js;
   cout <<"矩阵奇异！" <<endl;
   return(0);             //返回奇异标志值
  }
  if (is[k]!=k)
   for (j=0; j<=n-1; j++)     //行交换
   {
    u=k*n+j; v=is[k]*n+j;
    p=a[u]; a[u]=a[v]; a[v]=p;
   }
  if (js[k]!=k)
   for (i=0; i<=n-1; i++)     //列交换
   {
    u=i*n+k; v=i*n+js[k];
    p=a[u]; a[u]=a[v]; a[v]=p;
   }
  l=k*n+k;
  a[l] = ff(a[l]);            //计算1/a[l]
  for (j=0; j<=n-1; j++)      //归一化
   if (j!=k)
   { u=k*n+j; a[u]=a[u]*a[l];}
  for (i=0; i<=n-1; i++)      //消元计算
   if (i!=k)
    for (j=0; j<=n-1; j++)
     if (j!=k)
     {
      u=i*n+j;
      T t1=a[i*n+k];
      T t2=a[k*n+j];
      T t=t1*t2;
      a[u]=a[u]-t;
     }
  for (i=0; i<=n-1; i++)
   if (i!=k)
   { u=i*n+k; a[u]=(a[u]-a[u]-a[u])*a[l];}
 }
 for (k=n-1; k>=0; k--)      //恢复行列交换
 {
  if (js[k]!=k)
   for (j=0; j<=n-1; j++)
   {
    u=k*n+j; v=js[k]*n+j;
    p=a[u]; a[u]=a[v]; a[v]=p;
   }
  if (is[k]!=k)
   for (i=0; i<=n-1; i++)
   {
    u=i*n+k; v=i*n+is[k];
    p=a[u]; a[u]=a[v]; a[v]=p;
   }
 }
 delete[] is; delete[] js;
 return(1);

}






#endif //GAUSSJORDANMATRIXINV_H
