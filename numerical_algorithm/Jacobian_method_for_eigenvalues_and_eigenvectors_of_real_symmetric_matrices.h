//
// Created by one on 2024/11/4.
//

#ifndef JACOBIAN_METHOD_FOR_EIGENVALUES_AND_EIGENVECTORS_OF_REAL_SYMMETRIC_MATRICES_H
#define JACOBIAN_METHOD_FOR_EIGENVALUES_AND_EIGENVECTORS_OF_REAL_SYMMETRIC_MATRICES_H
#include <cmath>
#include <iostream>
using namespace std;
//用雅可比(Jacobi)方法求实对称矩阵的全部特征值与相应的特征向量
//double a[n][n] 存放n阶实对症矩阵A,返回时对角线上存放n个特征值
//int n 实对称矩阵A的阶数
//double v[n][n] 返回特征向量，其中第j列为与第j个特征值对应的特征向量
//double eps 控制精度要求
//若矩阵不对成，则显示错误信息，且返回0标志值；否则返回迭代次数，最多迭代200次
int Jacobian_method_for_eigenvalues_and_eigenvectors_of_real_symmetric_matrices(
  double a[],int n, double v[],double eps
) {
  int i,j,p,q,u,w,t,s,count;
  double fm,cn,sn,omega,x,y,d;
  for (i=0; i<n; i++)
    for (j=i+1; j<n; j++)
      if (a[i*n+j]!=a[j*n+i])
      {
        cout <<"矩阵不对称！" <<endl;  return 0;
      }
  for (i=0; i<=n-1; i++)
  {
    v[i*n+i]=1.0;
    for (j=0; j<=n-1; j++)
      if (i!=j) v[i*n+j]=0.0;
  }
  count=1;
  while (count<=200)
  {
    fm=0.0;
    for (i=1; i<=n-1; i++)
      for (j=0; j<=i-1; j++)
      {
        d=fabs(a[i*n+j]);
        if ((i!=j)&&(d>fm))  { fm=d; p=i; q=j;}
      }
    if (fm<eps)   return(count);
    count=count+1;
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
  return(count);
}
#endif //JACOBIAN_METHOD_FOR_EIGENVALUES_AND_EIGENVECTORS_OF_REAL_SYMMETRIC_MATRICES_H
