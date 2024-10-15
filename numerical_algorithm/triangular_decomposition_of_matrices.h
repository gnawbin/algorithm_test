//
// Created by one on 2024/10/15.
//

#ifndef TRIANGULAR_DECOMPOSITION_OF_MATRICES_H
#define TRIANGULAR_DECOMPOSITION_OF_MATRICES_H
/**
* 矩阵的三角分解
*/
#include <cmath>
#include <iostream>
using namespace std;
//a[n][n] 存放n阶矩阵A,返回存放Q矩阵
//l[n][n] 返回时存放下三角矩阵
//u[n][n] 返回是存放上三角矩阵U
int triangular_decomposition_of_matrices(double a[],int n,double l[],double u[]) {
    int i,j,k,w,v,ll;
    for (k=0; k<=n-2; k++)
    {
        ll=k*n+k;
        if (fabs(a[ll])+1.0==1.0)   //右下角子阵中a[k][k]=0
        {
            cout <<"程序失败！\n"; return 0;
        }
        for (i=k+1; i<=n-1; i++)
        {
            w=i*n+k; a[w]=a[w]/a[ll];
        }
        for (i=k+1; i<=n-1; i++)
        {
            w=i*n+k;
            for (j=k+1; j<=n-1; j++)
            {
                v=i*n+j; a[v]=a[v]-a[w]*a[k*n+j];
            }
        }
    }
    for (i=0; i<=n-1; i++)
    {
        for (j=0; j<i; j++)      //L-I
        {
            w=i*n+j; l[w]=a[w]; u[w]=0.0;
        }
        w=i*n+i;
        l[w]=1.0; u[w]=a[w];
        for (j=i+1; j<=n-1; j++)    //U
        {
            w=i*n+j; l[w]=0.0; u[w]=a[w];
        }
    }
    return 1;

}
#endif //TRIANGULAR_DECOMPOSITION_OF_MATRICES_H
