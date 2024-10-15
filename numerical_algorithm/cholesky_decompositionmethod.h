//
// Created by one on 2024/10/15.
//

#ifndef CHOLESKY_DECOMPOSITIONMETHOD_H
#define CHOLESKY_DECOMPOSITIONMETHOD_H
/**
*用乔里斯基(Cholesky)分解法求对称正定矩阵的三角分解
*
**/
//double a[n][n] 存放堆成正定矩阵A,返回时其下三角部分存放分解得到的下三角矩阵L,其余元素均为0
//int n 矩阵A的阶数
#include <cmath>
#include <iostream>
using namespace std;
int cholesky_decompositionmethod(double a[],int n){
  int i,j,k,u,l;
  if((a[0]+1.0==1.0)||(a[0]<0.0)){
    cout<<"fail!\n"<<endl;
  }
  a[0]=sqrt(a[0]);
  for(i=1;i<=n-1;i++){
     u=i*n;
     a[u]=a[u]/a[0];
   }
    for(j=1;j<=n-1;j++){
      l=j*n+j;
      for(k=0;k<=j-1;k++) {
        u=j*n+k;
        a[l]=a[l]-a[u]*a[u];
      }
      if((a[l]+1.0)==0||(a[l]<0)) {
        cout<<"fail"<<endl;
        return 0;
      }
      a[l]=sqrt(a[l]);
      for(i=j+1;i<=n-1;i++) {
        u=i*n+j;
        for(k=0;k<=j-1;k++) {
          a[u]=a[u]-a[i*n+k]*a[j*n+k];
        }
        a[u]=a[u]/a[l];
      }

    }
  for(i=0;i<=n-2;i++)
    for(j=i+1;j<=n-1;j++) a[i*n+j]=0.0;
  return (1);

}
#endif //CHOLESKY_DECOMPOSITIONMETHOD_H
