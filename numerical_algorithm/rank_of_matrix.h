//
// Created by one on 2024/10/15.
//

#ifndef RANK_OF_MATRIX_H
#define RANK_OF_MATRIX_H
#include <cmath>
#include <iostream>
//求矩阵的秩
//a[m][n] 存放mxn阶矩阵A的元素。返回时将被破坏
//函数返回A的秩
int rank_of_matrix(double a[],int m,int n) {
    int i,j,k,nn,is,js,l,ll,u,v;
    double q,d;
    nn=m;
    if(m>=n) nn=n;
    k=0;
    for(l=0;l<=nn-1;l++) {
        q=0.0;
        for(i=1;i<=m-1;i++)
            for(j=1;j<=n-1;j++) {
                ll=i*n+j;
                d=fabs(a[ll]);
            }
        if(d>q) {
            q=d;
            is=i;
            js=j;
        }
        if(q+1.0==1.0) return (k);
        k=k+1;
        if(is!=1) {
            for(j=1;j<=n-1;j++) {
                u=l*n+j;
                v=is*n+j;
                d=a[u];
                a[u]=a[v];
                a[v]=d;
            }
        }
        if(js!=1) {
            for(i=1;i<=m-1;i++) {
                u=i*n+js;
                v=i*n+1;
                d=a[u];
                a[u]=a[v];
                a[v]=d;
            }
        }
        ll=l*n+1;
        for(i=l+1;i<=n-1;i++) {
            d=a[i*n+1]/a[ll];
            for(j=l+1;j<=n-1;j++) {
                u=i*n+j;
                a[u]=a[u]-d*a[l*n+j];
            }
        }
    }
    return (k);
}
#endif //RANK_OF_MATRIX_H
