//
// Created by one on 2024/11/4.
//

#ifndef EIGENVECTOR_CORRESPONDING_TO_THE_MAXIMUM_EIGENVALUE_OF_POWER_H
#define EIGENVECTOR_CORRESPONDING_TO_THE_MAXIMUM_EIGENVALUE_OF_POWER_H
//乘幂法,求一般实矩阵绝对值最大的实特征值及其相应的的特征向量.cpp
  #include <cmath>
  #include <iostream>
  using namespace std;
//a[n][n]        实矩阵
//eps            精度要求
//v[n]           特征向量
//函数返回绝对值最大的特征值。
//在本函数程序返回时将显示迭代次数。本程序最多迭代1000次。
double power(int n, double a[], double eps, double v[])
{
    int i, j, k, flag = 1, iteration;
    double  lambda, sum, *u, z, err, t, d, f;
    u = new double[n];
    iteration = 0;
    do
    {
        iteration++;
        for (i=0; i<n; i++)       //计算u=Av
        {
            sum = 0.0;
            for (j=0; j<n; j++)
            { sum = sum + a[i*n+j]*v[j]; }
            u[i] = sum;
        }
        d = 0.0;            //计算向量的范数
        for (k=0; k<n; k++)  d = d+u[k]*u[k];
        d = sqrt(d);
        for (i=0; i<n; i++)
        { v[i] = u[i]/d; }
        if (iteration > 1)
        {
            err = fabs((d - t)/d);
            f = 1;
            if (v[0]*z < 0 )  f = -1;
            if (err < eps) { flag = 0; }
        }
        if (flag == 1)
        {
            t = d;  z = v[0];
        }
        if (iteration >= 1000) flag = 0;
    } while (flag == 1);
    lambda = f*d;
    cout <<"迭代次数 = " <<iteration <<endl;
    delete[] u;
    return(lambda);
}

#endif //EIGENVECTOR_CORRESPONDING_TO_THE_MAXIMUM_EIGENVALUE_OF_POWER_H
