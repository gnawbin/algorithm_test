//
// Created by one on 2024/10/11.
//
#include <iostream>
#include "Complex.h"
#include <cmath>
using namespace std;
int main()
{
     int i;
    double a,b;
    Complex c1,c2,c3,c,p[5];
    cin>>a>>b;//输入复数c1的实部与虚部
    c1=Complex(a,b);
    cout<<"c1=";
    c1.prt();
    cout<<endl;
    cin>>a>>b;//输入复数c2的实部和虚部
    c2=Complex(a,b);
    cout<<"c2=";
    c2.prt();
    cout<<endl;
    cin>>a>>b;
    c3=Complex(a,b);
    cout<<"c3=";
    c3.prt();
    cout<<endl;
    c=c1+c2;
    cout<<"c1+c2=";
    c.prt();
    cout<<endl;
    c=c1-c2;
    cout<<"c1-c2=";
    c.prt();
    cout<<endl;
    c=c1*c2;
    cout<<"c1*c2=";
    c.prt();
    cout<<endl;
    c=c1/c2;
    cout<<"c1/c2=";
    c.prt();
    cout<<endl;
    c=c3.cpower(-3);
    cout<<"c3 power=";
    c.prt();
    cout<<endl;
    cout<<"c5 5 time root:"<<endl;
    c3.croot(5,p);
    for(i=0;i<5;i++) {
        p[i].prt();
        cout<<endl;
    }
    c=c3.cexp();
    cout<<"cexp(c3)=";
    c.prt();
    cout<<endl;
    c=c3.clog();
    cout<<"clog(c3)=";
    c.prt();
    cout<<endl;
    c=c3.csin();
    cout<<"csin(c3)=";
    c.prt();
    cout<<endl;
    c=c3.ccos();
    cout<<"ccos(c3)=";
    c.prt();
    cout<<endl;
    return 0;




  //  std::cout << "Hello, World!" << std::endl;
    return 0;
}
