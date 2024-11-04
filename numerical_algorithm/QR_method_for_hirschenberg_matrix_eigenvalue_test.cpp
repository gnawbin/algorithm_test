//
// Created by one on 2024/11/2.
//
#include "QR_method_for_hirschenberg_matrix_eigenvalue.h"
#include "elementary_similarity_transformation_method_for_hirschenberg_matrix.h"
#include <iostream>
using namespace std;
int main(int argc,char *argv[]){
int i,j;
double eps=0.000001;
double u[5],v[5];
double a[5][5]={ {1.0,6.0,-3.0,-1.0,7.0},
 {8.0,-15.0,18.0,5.0,4.0},
{-2.0,11.0,9.0,15.0,20.0},
 {-13.0,2.0,21.0,30.0,-6.0},
{17.0,22.0,-5.0,3.0,6.0}};
cout <<"原矩阵 A:\n";
for (i=0; i<=4; i++)
{
    for (j=0; j<=4; j++)  cout <<a[i][j] <<"    ";
    cout <<endl;
}
elementary_similarity_transformation_method_for_hirschenberg_matrix(&a[0][0],5);              //约化一般实矩阵为上H阵
cout <<"上H矩阵 A:\n";
for (i=0; i<=4; i++)
{
    for (j=0; j<=4; j++)  cout <<a[i][j] <<"    ";
    cout <<endl;
}
i=QR_method_for_hirschenberg_matrix_eigenvalue(&a[0][0],5,u,v,eps);    //求上H矩阵特征值
if (i==0)  return 0;
cout <<"矩阵A的特征值:" <<endl;
for (i=0; i<=4; i++)
{
    cout <<u[i] ;
    if (v[i]!=0)  cout<<" +J" <<v[i];
    cout <<endl;
}
return 0;

}