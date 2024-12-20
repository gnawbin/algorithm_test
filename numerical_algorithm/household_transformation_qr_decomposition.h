//
// Created by one on 2024/10/15.
//

#ifndef HOUSEHOLD_TRANSFORMATION_QR_DECOMPOSITION_H
#define HOUSEHOLD_TRANSFORMATION_QR_DECOMPOSITION_H
/**
* 用豪斯荷尔德(Householder)变换对一般mxn阶的实矩阵进行QR分解
*/
#include <iostream>
#include <cmath>

using namespace std;
//a[m][n]   存放m×n的实矩阵A。要求 m>=n。
//          返回时其右上三角部分存放QR分解中的上三角阵R。
//q[m][m]   返回QR分解中的正交矩阵Q。
//函数返回标志值。若为0，则表示失败；若不为0，则表示正常。
int household_transformation_qr_decomposition(double a[],int m,int n,double q[]) {
    int i,j,k,l,nn,p,jj;
    double u,alpha,w,t;
    if (m<n)
    {
        cout <<"失败！m<n。\n"; return 0;
    }
    for (i=0; i<=m-1; i++)
        for (j=0; j<=m-1; j++)
        {
            l=i*m+j; q[l]=0.0;
            if (i==j) q[l]=1.0;
        }
    nn=n;
    if (m==n) nn=m-1;
    for (k=0; k<=nn-1; k++)
    {
        u=0.0; l=k*n+k;
        for (i=k; i<=m-1; i++)
        {
            w=fabs(a[i*n+k]);
            if (w>u) u=w;
        }
        alpha=0.0;
        for (i=k; i<=m-1; i++)
        {
            t=a[i*n+k]/u; alpha=alpha+t*t;
        }
        if (a[l]>0.0) u=-u;
        alpha=u*sqrt(alpha);
        if (fabs(alpha)+1.0==1.0)
        {
            cout <<"程序工作失败！\n"; return 0;
        }
        u=sqrt(2.0*alpha*(alpha-a[l]));
        if ((u+1.0)!=1.0)
        {
            a[l]=(a[l]-alpha)/u;
            for (i=k+1; i<=m-1; i++)
            {
                p=i*n+k; a[p]=a[p]/u;
            }
            for (j=0; j<=m-1; j++)
            {
                t=0.0;
                for (jj=k; jj<=m-1; jj++)  t=t+a[jj*n+k]*q[jj*m+j];
                for (i=k; i<=m-1; i++)
                {
                    p=i*m+j; q[p]=q[p]-2.0*t*a[i*n+k];
                }
            }
            for (j=k+1; j<=n-1; j++)
            {
                t=0.0;
                for (jj=k; jj<=m-1; jj++)  t=t+a[jj*n+k]*a[jj*n+j];
                for (i=k; i<=m-1; i++)
                {
                    p=i*n+j; a[p]=a[p]-2.0*t*a[i*n+k];
                }
            }
            a[l]=alpha;
            for (i=k+1; i<=m-1; i++) a[i*n+k]=0.0;
        }
    }
    for (i=0; i<=m-2; i++)
        for (j=i+1; j<=m-1;j++)
        {
            p=i*m+j; l=j*m+i;
            t=q[p]; q[p]=q[l]; q[l]=t;
        }
    return 1;

}
#endif //HOUSEHOLD_TRANSFORMATION_QR_DECOMPOSITION_H
