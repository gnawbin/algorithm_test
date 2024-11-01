//
// Created by one on 2024/11/1.
//

#ifndef SYMMETRIC_MATRICES_HOUSEHOLDER_TRANSFORMATION_EIGENVALUE_H
#define SYMMETRIC_MATRICES_HOUSEHOLDER_TRANSFORMATION_EIGENVALUE_H
/**
 * 用变形QR方法计算是对称三对角称的全部特征值与相应的特征向量
 * int n 实对称三角阵的阶数
 * double b[n] 存放n阶实对称三角阵的主对角线上的元素，返回时存放全部特征值
 * double c[n] 前n-1个元素存放实对称三角阵的次对角线上的元素
 * double q[n][n] 若存放n阶单位矩阵，则返回实对称三对角阵T的特征向量组
 *
 *
 *
 *
 */
#include <iostream>
#include <cmath>
using namespace std;
int symmetric_matrices_householder_transformation_eigenvalue(int n,double b[],double c[],double q[],double eps) {
 	  int i,j,k,m,it,u,v;
      double d,f,h,g,p,r,e,s;
      c[n-1]=0.0; d=0.0; f=0.0;
      for (j=0; j<=n-1; j++)
      {
		  it=0;
          h=eps*(fabs(b[j])+fabs(c[j]));
          if (h>d) d=h;
          m=j;
          while ((m<=n-1)&&(fabs(c[m])>d)) m=m+1;
          if (m!=j)
          {
			  do
              {
				  if (it==100)
                  {
					  cout <<"迭代了100次！\n";  return(it);
				  }
                  it=it+1;
                  g=b[j];
                  p=(b[j+1]-g)/(2.0*c[j]);
                  r=sqrt(p*p+1.0);
                  if (p>=0.0) b[j]=c[j]/(p+r);
                  else b[j]=c[j]/(p-r);
                  h=g-b[j];
                  for (i=j+1; i<=n-1; i++)  b[i]=b[i]-h;
                  f=f+h; p=b[m]; e=1.0; s=0.0;
                  for (i=m-1; i>=j; i--)
                  {
					  g=e*c[i]; h=e*p;
                      if (fabs(p)>=fabs(c[i]))
                      {
						  e=c[i]/p; r=sqrt(e*e+1.0);
                          c[i+1]=s*p*r; s=e/r; e=1.0/r;
                      }
                      else
					  {
						  e=p/c[i]; r=sqrt(e*e+1.0);
                          c[i+1]=s*c[i]*r;
                          s=1.0/r; e=e/r;
                      }
                      p=e*b[i]-s*g;
                      b[i+1]=h+s*(e*g+s*b[i]);
                      for (k=0; k<=n-1; k++)
                      {
						  u=k*n+i+1; v=u-1;
                          h=q[u]; q[u]=s*q[v]+e*h;
                          q[v]=e*q[v]-s*h;
                      }
				  }
                  c[j]=s*p; b[j]=e*p;
			  }
              while (fabs(c[j])>d);
		  }
          b[j]=b[j]+f;
      }
      for (i=0; i<=n-1; i++)
      {
		  k=i; p=b[i];
          if (i+1<=n-1)
          {
			  j=i+1;
              while ((j<=n-1)&&(b[j]<=p))
              { k=j; p=b[j]; j=j+1;}
          }
          if (k!=i)
          {
			  b[k]=b[i]; b[i]=p;
              for (j=0; j<=n-1; j++)
              {
				  u=j*n+i; v=j*n+k;
                  p=q[u]; q[u]=q[v]; q[v]=p;
              }
          }
      }
      return(it);

}
#endif //SYMMETRIC_MATRICES_HOUSEHOLDER_TRANSFORMATION_H
