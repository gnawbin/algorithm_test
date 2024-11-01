//
// Created by one on 2024/11/1.
//
#include "symmetric_matrices_householder_transformation_eigenvalue.h"
#include "symmetric_matrices_householder_transformation.h"
int main(int argc,char *argv[]) {
    int i,j,k;
    double q[5][5],b[5],c[5];
    double a[5][5]={ {10.0,1.0,2.0,3.0,4.0},
     {1.0,9.0,-1.0,2.0,-3.0},
    {2.0,-1.0,7.0,3.0,-5.0},
     {3.0,2.0,3.0,12.0,-1.0},
    {4.0,-3.0,-5.0,-1.0,15.0}};
    double eps=0.000001;
    i=symmetric_matrices_householder_transformation(&a[0][0],5,&q[0][0],b,c);   //Լ���Գƾ���AΪ���Խ���
    if (i==0)  return 0;
    cout <<"ԭ�Գƾ��� A:\n";
    for (i=0; i<=4; i++)
    {
        for (j=0; j<=4; j++)  cout <<a[i][j] <<"    ";
        cout <<endl;
    }
    cout <<"�˻����� Q:\n";
    for (i=0; i<=4; i++)
    {
        for (j=0; j<=4; j++)  cout <<q[i][j] <<"    ";
        cout <<endl;
    }
    cout <<"�Գ����Խ������Խ���Ԫ��:\n";
    for (i=0; i<=4; i++)  cout <<b[i] <<"    ";
    cout <<endl;
    cout <<"�Գ����Խ���ζԽ���Ԫ��:\n";
    for (i=0; i<=4; i++)  cout <<c[i] <<"    ";
    cout <<endl;
    k=symmetric_matrices_householder_transformation_eigenvalue(5,b,c,&q[0][0],eps);    //��Գƾ���A������ֵ
    cout <<"��������= " <<k <<endl;
    cout <<"�Գƾ���A������ֵ:\n";
    for (i=0; i<=4; i++)  cout <<b[i] <<"    ";
    cout <<endl;
    cout <<"�Գƾ���A������������:\n";
    for (i=0; i<=4; i++)
    {
        for (j=0; j<=4; j++)  cout <<q[i][j] <<"    ";
        cout <<endl;
    }
    return 0;
}