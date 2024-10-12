//
// Created by one on 2024/10/11.
//

#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>
#include <cmath>
using namespace std;
class Complex {
private:
    double R;
    double I;
public:
    Complex(double real=0,double imag=0):R(real),I(imag) {}
    //复数输出
    void prt() {
        cout<<"("<<R<<","<<I<<")";
    }
    double cfabs() {
        //复数根
        double y;
        y=sqrt(R*R+I*I);
        return y;
    }
    //复数幅角
    double angle() {
        double y;
        y=atan2(I,R);
        return y;
    }
    //复数加法
    Complex operator+(Complex& c2) {
        Complex c;
        c.R=R+c2.R;
        c.I=I+c2.I;
        return c;
    }
    Complex operator-(Complex& c2) {
        Complex c;
        c.R=R-c2.R;
        c.I=I-c2.I;
        return c;
    }
    Complex operator*(Complex& c2) {
        Complex c;
        double p,q,s;
        p=R*c2.R;q=I*c2.I;
        s=(R+I)*(c2.R+c2.I);
        c.R=p-q;
        c.I=s-p-q;
        return c;
    }
    Complex operator/(Complex c2) {
        Complex c;
        double p,q,s,w;
        p=R*c2.R;
        q=-I*c2.I;
        s=(R+I)*(c2.R-c2.I);
        w=(c2.R)*(c2.R)+(c2.I)*(c2.I);
        if(w+1.0!=1.0) {
            c.R=(p-q)/w;
            c.I=(s-p-q)/w;
        }
        else {
            c.R=1e+300;
            c.I=1e+300;
        }
        return c;
    }
    Complex cpower(int n) {
        //复数乘幂
        Complex c;
        double r,q;
        q=atan2(I,R);
        r=sqrt(R*R+I*I);
        if(r+1.0!=1.0) {
            r=n*log(r);
            r=exp(r);
        }
        c.R=r*cos(n*q);
        c.I=r*sin(n*q);
        return c;
    }
    void croot(int n,Complex *p) {
        //复数的n次方根
        Complex c;
        int k;
        double r,q,t;
        if(n<1) return;
        q=atan2(I,R);
        r=sqrt(R*R+I*I);
        if(r+1.0!=1.0) {
            r=(1.0/n)*log(r);
            r=exp(r);
        }
        for(k=0;k<n;k++) {
            t=(2.0*k*3.1415926+q)/n;
            c.R=r*cos(t);
            c.I=r*sin(t);
            p[k]=c;
        }

    }
    Complex cexp() {
        //复数指数
        Complex c;
        double p;
        p=exp(R);
        c.R=p*cos(I);
        c.I=p*sin(I);
        return c;
    }
    //复数对数
    Complex clog() {
        Complex c;
        double p;
        p=R*R+I*I;
        p=log(sqrt(p));
        c.R=p;
        c.I=atan2(I,R);
        return c;
    }
    Complex csin() {
        Complex c;
        double p,q;
        p=exp(I);
        q=exp(-I);
        c.R=sin(R)*(p+q)/2;
        c.I=cos(R)*(p-q)/2;
        return c;
    }
    Complex ccos() {
        Complex c;
        double p,q;
        p=exp(I);
        q=exp(-I);
        c.R=cos(R)*(p+q)/2;
        c.I=-sin(R)*(p-q)/2;
        return c;
    }

};
#endif //COMPLEX_H
