//
// Created by one on 2024/11/1.
//
#include "symmetric_matrices_householder_transformation.h"
int main(int argc,char *argv[]) {
    int i,j;
    double b[5],c[5],q[5][5];
    double a[5][5]={ {10.0,1.0,2.0,3.0,4.0},
      {1.0,9.0,-1.0,2.0,-3.0},
    {2.0,-1.0,7.0,3.0,-5.0},
      {3.0,2.0,3.0,12.0,-1.0},
    {4.0,-3.0,-5.0,-1.0,15.0}};
    i=symmetric_matrices_householder_transformation(&a[0][0],5,&q[0][0],b,c);
    if (i==0) return 0;
    cout <<"对称矩阵 A :\n";
    for (i=0; i<=4; i++)
    {
        for (j=0; j<=4; j++)  cout <<a[i][j] <<"    ";
        cout <<endl;
    }
    cout <<"返回的乘积矩阵 Q :\n";
    for (i=0; i<=4; i++)
    {
        for (j=0; j<=4; j++)  cout <<q[i][j] <<"    ";
        cout <<endl;
    }
    cout <<"返回的主对角线元素 B :\n";
    for (i=0; i<=4; i++)  cout <<b[i] <<"    ";
    cout <<endl;
    cout <<"返回的次对角线元素 C :\n";
    for (i=0; i<=4; i++)  cout <<c[i] <<"    ";
    cout <<endl;
    return 0;

}