//
// Created by one on 2024/10/16.
//
#include "Poly.h"
#include <iostream>
int main(int argc,char *argv[]) {
    int k;
    double x[6] = { 0.9, 1.1, 1.3, -0.9, -1.1, -1.3 };
    double p1[7] = { -20.0,7.0,-7.0,1.0,3.0,-5.0,2.0 };
    double p2[6] = { 4.0,-6.0,5.0,2.0,-1.0,3.0 };
    double q2[4] = { 2.0,3.0,-6.0,2.0 };
    double p3[5] = { 8.0,-5.0,-3.0,6.0,3.0 };
    double q3[3] = { 1.0,-1.0,2.0 };
    double s2[9], s3[3], r3[2];

   Poly  p = Poly(6,p1);
    cout <<"多项式求值: " <<endl;
    for (k=0; k<6; k++)
        cout <<"p(" <<x[k] <<") = " <<p.poly_value(x[k]) <<endl;

    p = Poly(5,p2);
    Poly  q = Poly(3,q2);
    Poly  s = Poly(8,s2);
    p.poly_mul (q, s);    //多项式相乘 s2 = p2*q2
    cout <<"乘积多项式s2 = p2*q2 :" <<endl;
    for (k=0; k<=8; k++)       //输出乘积多项式s2的系数
    {
        cout <<"s2(" <<k <<") = " <<s2[k] <<endl;
    }
    p=Poly(4,p3);
    q=Poly(2,q3);
    s=Poly(2,s3);
   Poly   r=Poly(1,r3);
    p.poly_div(q, s, r);  //多项式相除 s3 = p3/q3 余 r3
    cout <<"p3/q3商多项式s3:" <<endl;
    for (k=0; k<=2; k++)      //输出商多项式s3的系数
    {
        cout <<"s3(" <<k <<") = " <<s3[k] <<endl;
    }
    cout <<"p3/q3余多项式r3:" <<endl;
    for (k=0; k<=1; k++)      //输出余多项式r3的系数
    {
        cout <<"r3(" <<k <<") = " <<r3[k] <<endl;
    }

    int i;
    double aa, bb;
    Complex  pp1[4]={Complex(2,1),Complex(2,1),Complex(1,1),Complex(2,2)};
    Complex  pp2[6]={Complex(4,2),Complex(-6,3),Complex(5,-4),
                    Complex(2,1),Complex(-1,-1),Complex(3,2)};
    Complex  qq2[4]={Complex(2,1),Complex(3,2),Complex(-6,-4),Complex(2,1)};
    Complex  pp3[5]={Complex(8,3),Complex(-5,4),Complex(-3,4),
                   Complex(6,-5),Complex(3,-1)};
   Complex  qq3[3]={Complex(1,2),Complex(-1,-3),Complex(2,2)};
  Complex  xx, yy, ss2[9], ss3[3], rr3[2];

    cout <<"输入x = ";
    cin >>aa >>bb;
     xx=Complex(aa,bb);
    Poly pp=Poly(3,pp1);
    cout <<"多项式求值: " <<endl;
    cout <<"x = "; xx.prt(); cout <<endl;
    cout <<"p(x) = "; yy = pp.poly_value(xx); yy.prt();  cout <<endl;
    pp=Poly(5,pp2);
    Poly qq=Poly(3,qq2);
   Poly  ss=Poly(8,ss2);
    pp.poly_mul (qq, ss);    //多项式相乘 s2 = p2*q2
    cout <<"乘积多项式ss2 = pp2*qq2 :" <<endl;
    for (i=0; i<=8; i++)       //输出乘积多项式s2的系数
    {
        cout <<"ss2(" <<i <<") = ";  ss2[i].prt();  cout <<endl;
    }
    pp=Poly(4,pp3);
    qq=Poly(2,qq3);
    ss=Poly(2,ss3);
   Poly rr=Poly(1,rr3);
    pp.poly_div (qq, ss, rr);  //多项式相除 s3 = p3/q3 余 r3
    cout <<"p3/q3商多项式s3:" <<endl;
    for (i=0; i<=2; i++)      //输出商多项式s3的系数
    {
        cout <<"s3(" <<i <<") = ";  ss3[i].prt();  cout <<endl;
    }
    cout <<"pp3/qq3余多项式r3:" <<endl;
    for (i=0; i<=1; i++)      //输出余多项式r3的系数
    {
        cout <<"rr3(" <<i <<") = ";  rr3[i].prt();  cout <<endl;
    }

    return 0;
}