//
// Created by one on 2024/10/16.
//

#ifndef POLY_H
#define POLY_H
#include <iostream>
#include <fstream>
#include <cmath>
#include "Complex.h"

using namespace std;
void  init(double p) {
    p= 0.0;
}
void  init(Complex p) {
   p= Complex(0.0,0.0);
}
double ffabs(double p)        //����ʵ���ľ���ֵ
{
    double q;

    return(q);
}
double ffabs(Complex p)      //���㸴����ģ
{
  double q;
    q = p.cfabs();
    return(q);
}
template<typename T>
class Poly {
private:
    int N; //����ʽ����
    T* p;//����ʽϵ��
public:
    Poly(int nn,T *pp=nullptr):N(nn),p(pp){}
    void input() {
        int  i;
        cout <<"����ʽϵ��:" <<endl;
        for (i=0; i<N+1; i++)              //�������ʽϵ��
        {
            cout <<"p(" <<i <<") = ";
            cin >>p[i];
        }
    }//�ɼ����������ʽϵ��
    void complex_input() {
        int  i;
        double a,b;
        cout <<"����ʽ��ϵ��:" <<endl;
        for (i=0; i<N+1; i++)              //�������ʽ��ϵ��
        {
            cout <<"p(" <<i <<") = ";
            cin >>a >>b;  p[i]=Complex(a, b);
        }
    }//�ɼ����������ʽϵ��
    T poly_value(T x) {
        int k;
        T u;
        u = p[N];
        for (k=N-1; k>=0; k--)  u = u*x + p[k];
        return u;

    }  //����ʽ��ֵ
    void poly_mul(Poly& q,Poly& s) {
        int i,j;
        for (i=0; i<=s.N; i++)  init(s.p[i]);
        for (i=0; i<=N; i++)
            for (j=0; j<=q.N; j++) {
                T t1=p[i];
                T t2=q.p[j];
                T t=t1*t2;
                s.p[i+j]=s.p[i+j] + t;
            }


    }
    //����ʽ���
    void poly_div(Poly& q,Poly& s,Poly& r) {
        int i,j,mm,ll;
        for (i=0; i<=s.N; i++) init(s.p[i]);
        if ( ffabs(q.p[q.N])+1.0==1.0)  return;
        ll=N;
        for (i=(s.N)+1; i>=1; i--)
        {
            s.p[i-1]=p[ll]/(q.p[q.N]);
            mm=ll;
            for (j=1; j<=q.N; j++)
            {
                T t1=s.p[i-1];
                T t2=q.p[(q.N)-j];
                T t=t1*t2;
                p[mm-1]=p[mm-1]-t;
                mm=mm-1;
            }
            ll=ll-1;
        }
        for (i=0; i<=r.N; i++) r.p[i]=p[i];


    }//����ʽ���
};

//�ɼ����������ʽϵ��

#endif //POLY_H
