//
// Created by one on 2024/10/15.
//

#ifndef KALMAN_FILTERING_H
#define KALMAN_FILTERING_H
#include <cmath>
#include <iostream>
#include "GaussJordanMatrixInv.h"
using namespace std;
//n          动态系统的维数。
//m          观测系统的维数
//k          观测序列长度。
//f[n][n]    系统状态转移矩阵
//q[n][n]    模型噪声W的协方差阵。
//r[m][m]    观测噪声V的协方差阵。
//h[m][n]    观测矩阵
//y[k][m]    观测向量序列。
//x[k][n]    x[0][j]存放初值。其余各行返回状态向量估值序列。
//p[n][n]    存放初值。返回最后时刻的估计误差协方差阵。
//g[n][m]    返回最后时刻的稳定增益矩阵。
//函数返回标志值。若=0表示求逆失败，若不为0表示正常。
int kalman_filtering(int n, int m, int k, double f[], double q[], double r[],
             double h[], double y[], double x[], double p[], double g[]) {
     int i,j,kk,ii,l,jj,js;
      double *e,*a,*b;
      e=new double[m*m];
      l=m;
      if (l<n) l=n;
      a=new double[l*l];
      b=new double[l*l];
      for (i=0; i<=n-1; i++)
      for (j=0; j<=n-1; j++)
      {
		  ii=i*l+j; a[ii]=0.0;
          for (kk=0; kk<=n-1; kk++)
            a[ii]=a[ii]+p[i*n+kk]*f[j*n+kk];
      }
      for (i=0; i<=n-1; i++)
      for (j=0; j<=n-1; j++)
      {
		  ii=i*n+j; p[ii]=q[ii];
          for (kk=0; kk<=n-1; kk++)
            p[ii]=p[ii]+f[i*n+kk]*a[kk*l+j];
      }
      for (ii=2; ii<=k; ii++)
      {
		  for (i=0; i<=n-1; i++)
          for (j=0; j<=m-1; j++)
          {
			  jj=i*l+j; a[jj]=0.0;
              for (kk=0; kk<=n-1; kk++)
                  a[jj]=a[jj]+p[i*n+kk]*h[j*n+kk];
          }
          for (i=0; i<=m-1; i++)
          for (j=0; j<=m-1; j++)
          {
			  jj=i*m+j; e[jj]=r[jj];
              for (kk=0; kk<=n-1; kk++)
                 e[jj]=e[jj]+h[i*n+kk]*a[kk*l+j];
          }
          js=guass_jordan_matrix_inv(e,m);
          if (js==0)
          {
			  delete[] e; delete[] a; delete[] b; return(js);
		  }
          for (i=0; i<=n-1; i++)
          for (j=0; j<=m-1; j++)
          {
			  jj=i*m+j; g[jj]=0.0;
              for (kk=0; kk<=m-1; kk++)
                  g[jj]=g[jj]+a[i*l+kk]*e[j*m+kk];
          }
          for (i=0; i<=n-1; i++)
          {
			  jj=(ii-1)*n+i; x[jj]=0.0;
              for (j=0; j<=n-1; j++)
                 x[jj]=x[jj]+f[i*n+j]*x[(ii-2)*n+j];
          }
          for (i=0; i<=m-1; i++)
          {
			  jj=i*l; b[jj]=y[(ii-1)*m+i];
              for (j=0; j<=n-1; j++)
                 b[jj]=b[jj]-h[i*n+j]*x[(ii-1)*n+j];
          }
          for (i=0; i<=n-1; i++)
          {
			  jj=(ii-1)*n+i;
              for (j=0; j<=m-1; j++)
                 x[jj]=x[jj]+g[i*m+j]*b[j*l];
          }
          if (ii<k)
          {
			  for (i=0; i<=n-1; i++)
              for (j=0; j<=n-1; j++)
              {
				  jj=i*l+j; a[jj]=0.0;
                  for (kk=0; kk<=m-1; kk++)
                     a[jj]=a[jj]-g[i*m+kk]*h[kk*n+j];
                  if (i==j) a[jj]=1.0+a[jj];
              }
              for (i=0; i<=n-1; i++)
              for (j=0; j<=n-1; j++)
              {
				  jj=i*l+j; b[jj]=0.0;
                  for (kk=0; kk<=n-1; kk++)
                     b[jj]=b[jj]+a[i*l+kk]*p[kk*n+j];
              }
              for (i=0; i<=n-1; i++)
              for (j=0; j<=n-1; j++)
              {
				  jj=i*l+j; a[jj]=0.0;
                  for (kk=0; kk<=n-1; kk++)
                     a[jj]=a[jj]+b[i*l+kk]*f[j*n+kk];
              }
              for (i=0; i<=n-1; i++)
              for (j=0; j<=n-1; j++)
              {
				  jj=i*n+j; p[jj]=q[jj];
                  for (kk=0; kk<=n-1; kk++)
                     p[jj]=p[jj]+f[i*n+kk]*a[j*l+kk];
              }
          }
      }
      delete[] e; delete[] a; delete[] b;
      return(js);
}


#endif //KALMAN_FILTERING_H
