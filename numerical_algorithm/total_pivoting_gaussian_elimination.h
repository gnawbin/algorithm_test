//
// Created by one on 2024/10/14.
//

#ifndef TOTAL_PIVOTING_GAUSSIAN_ELIMINATION_H
#define TOTAL_PIVOTING_GAUSSIAN_ELIMINATION_H
/**
* ȫѡ��Ԫ��˹��ȥ��
*/
#include "Complex.h"
#include <cmath>
#include <iostream>
using namespace std;
double init(double p){
  p=0.0;
  return (p);
}
Complex init(Complex p){
 p=Complex(0.0,0.0);
 return (p);
}
double ffabs(double p) {
    double q;
    q=fabs(p);
    return q;
}
double ffabs(Complex p) {
    double q;
    q=p.cfabs();
    return q;
}
//a[n][n] ϵ�����󣬷���ʱ���ƻ�
//b[n] �������������ؽ���������ϵ���������죬�򷵻�0����
//n ���������
template<typename T>
//��ϵ���������죬�������ʾ�����£� ��������0��־λ
int total_pivoting_gaussian_elimination(T *a,T *b,int n) {
    int *js,k,i,j,is,p,q;
    double d,t;
    T s;
    js=new int[n];
    for (k=0;k<=n-2;k++)             //��Ԫ����
    {
        d=0.0;                       //ȫѡ��Ԫ
        for (i=k;i<=n-1;i++)
            for (j=k;j<=n-1;j++)
            {
                t=ffabs(a[i*n+j]);
                if (t>d) { d=t; js[k]=j; is=i;}

            }

        if (d+1.0==1.0)               //ϵ���������죬���ʧ�ܣ�
        {
            for (i=0; i<n; i++)  b[i] = init(s);
            cout <<"ϵ���������죬���ʧ�ܣ�\n";
            delete[]js;
            return 0;
        }
        if (js[k]!=k)                 //�н���
        {
            for (i=0;i<=n-1;i++)
            {
                p=i*n+k; q=i*n+js[k];
                s=a[p]; a[p]=a[q]; a[q]=s;
            }
        }
        if (is!=k)                    //�н���
        {
            for (j=k;j<=n-1;j++)
            {
                p=k*n+j; q=is*n+j;
                s=a[p]; a[p]=a[q]; a[q]=s;
            }
            s=b[k]; b[k]=b[is]; b[is]=s;
        }
        s=a[k*n+k];
        for (j=k+1;j<=n-1;j++)        //��һ��
        {
            p=k*n+j; a[p]=a[p]/s;
        }
        b[k]=b[k]/s;
        for (i=k+1;i<=n-1;i++)        //��Ԫ
        {
            for (j=k+1;j<=n-1;j++)
            {
                p=i*n+j;
                T t1=a[i*n+k];
                T t2=a[k*n+j];
                T t=t1*t2;
                a[p]=a[p]-t;
            }
            T aa=a[i*n+k];
            T bb=b[k];
            T aabb=aa*bb;
            b[i]=b[i]-aabb;
        }
    }
    s=a[(n-1)*n+n-1];
    if (ffabs(s)+1.0==1.0)        //ϵ���������죬���ʧ�ܣ�
    {
        for (i=0; i<n; i++)  b[i] = init(s);
        cout <<"ϵ���������죬���ʧ�ܣ�\n";
        delete[] js;
        return 0;
    }
    b[n-1]=b[n-1]/s;                //�ش�����
    for (i=n-2;i>=0;i--)
    {
        s=init(s);
        for (j=i+1;j<=n-1;j++) {
            T aa=a[i*n+j];
            T bb=b[j];
            T aabb=aa*bb;
            s=s+aabb;
        }
        b[i]=b[i]-s;
    }
    js[n-1]=n-1;
    for (k=n-1;k>=0;k--) {
        //�ָ�
        if (js[k]!=k)
        {
            s=b[k]; b[k]=b[js[k]]; b[js[k]]=s;
        }
    }
    delete[] js;
    return 1;

}
#endif //TOTAL_PIVOTING_GAUSSIAN_ELIMINATION_H
