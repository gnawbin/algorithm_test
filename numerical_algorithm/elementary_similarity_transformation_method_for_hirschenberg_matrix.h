//
// Created by one on 2024/11/1.
//

#ifndef ELEMENTARY_SIMILARITY_TRANSFORMATION_METHOD_FOR_HIRSCHENBERG_MATRIX_H
#define ELEMENTARY_SIMILARITY_TRANSFORMATION_METHOD_FOR_HIRSCHENBERG_MATRIX_H
/**
 * 赫申伯格(Hessenberg)矩阵用初等相似变换将一般实矩阵约化为上H矩阵
 * double a[n][n] 存放一般实矩阵，返回上H矩阵
 * int n 矩阵的阶数
 *
 */
#include <cmath>
#include <iostream>
void  elementary_similarity_transformation_method_for_hirschenberg_matrix(
 double a[],int n
) {
 int i,j,k,u,v;
 double d,t;
 for (k=1; k<=n-2; k++)
 {
  d=0.0;
  for (j=k; j<=n-1; j++)
  {
   u=j*n+k-1; t=a[u];
   if (fabs(t)>fabs(d))  { d=t; i=j;}
  }
  if (fabs(d)+1.0!=1.0)
  {
   if (i!=k)
   {
    for (j=k-1; j<=n-1; j++)
    {
     u=i*n+j; v=k*n+j;
     t=a[u]; a[u]=a[v]; a[v]=t;
    }
    for (j=0; j<=n-1; j++)
    {
     u=j*n+i; v=j*n+k;
     t=a[u]; a[u]=a[v]; a[v]=t;
    }
   }
   for (i=k+1; i<=n-1; i++)
   {
    u=i*n+k-1; t=a[u]/d; a[u]=0.0;
    for (j=k; j<=n-1; j++)
    {
     v=i*n+j;   a[v]=a[v]-t*a[k*n+j];
    }
    for (j=0; j<=n-1; j++)
    {
     v=j*n+k;  a[v]=a[v]+t*a[j*n+i];
    }
   }
  }
 }


}
#endif //ELEMENTARY_SIMILARITY_TRANSFORMATION_METHOD_FOR_HIRSCHENBERG_MATRIX_H
