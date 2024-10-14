//
// Created by one on 2024/10/14.
//

#ifndef FAST_WALSH_SERIES_H
#define FAST_WALSH_SERIES_H
/**
* 计算沃什变换序列
*/
//int n 输入序列的长度
//int k 满足n=2的k阶次方的给定输入序列
//double p[n] 存放长度为n
#include <cmath>
#include <iostream>
using namespace std;
void fast_walsh_series(int n,int k,double p[],double x[]){
   int m,l,it,ii,i,j,is;
   double q;
   m =1; l=n; it=2;
   x[0]=1; ii=n/2; x[ii]=2;
   for (i=1; i<=k-1; i++)
   {
      m=m+m; l=l/2; it=it+it;
      for (j=0; j<=m-1; j++) x[j*l+l/2]=it+1-x[j*l];
   }
   for (i=0; i<=n-1; i++)
   {
      ii=(int)(x[i]-1); x[i]=p[ii];
   }
   l=1;
   for (i=1; i<=k; i++)
   {
      m=n/(2*l)-1;
      for (j=0; j<=m; j++)
      {
         it=2*l*j;
         for (is=0; is<=l-1; is++)
         {
            q=x[it+is]+x[it+is+l];
            x[it+is+l]=x[it+is]-x[it+is+l];
            x[it+is]=q;
         }
      }
      l=2*l;
   }

}
#endif //FAST_WALSH_SERIES_H
