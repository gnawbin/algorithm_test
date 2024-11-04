//
// Created by one on 2024/11/4.
//
#include <iostream>
#include <cmath>
#include "Jacobian_method_for_eigenvalues_and_eigenvectors_of_real_symmetric_matrices.h"
int main(int argc,char *argv[]) {
    int i,j;
    double eps,v[3][3];
    double a[3][3]={
       {2.0,-1.0,0.0},
        {-1.0,2.0,-1.0},
        {0.0,-1.0,2.0}
    };
    eps=0.000001;
    i=Jacobian_method_for_eigenvalues_and_eigenvectors_of_real_symmetric_matrices(&a[0][0],3,&v[0][0],eps);
    cout<<"迭代次数="<<i<<endl;
     if(i>0) {
         cout<<"特征值: "<<endl;
         for(i=0;i<=2;i++) cout<<a[i][i]<<"   ";
         cout<<endl;
         cout<<"特征向量:"<<endl;
         for(i=0;i<=2;i++) {
             for(j=0;j<=2;j++) {
                 cout<<v[i][j]<<"     ";
             }
             cout<<endl;
         }
     }
    return 0;
}