//
// Created by one on 2024/10/12.
//
#include <iostream>
#include <cmath>
#include <iomanip>
#include "fast_fourier_trans.h"
using namespace std;
int main(int argc,char *argv[])
{
    int i,j;
    double pr[64],pi[64],fr[64],fi[64];
    for(i=0;i<=63;i++) {
        pr[i]=exp(-0.1*(i+0.5));
        pi[i]=0.0;
    }
    cout<<"������������p:"<<endl;
    for(i=0;i<=15;i++) {
        for(j=0;j<=3;j++) {
            cout<<setw(15)<<pr[4*i+j];

        }
        cout<<endl;
    }


 fast_fourier_trans(64,6,pr,pi,fr,fi,0);
    cout<<"��������p�ı任��ʵ��fr:"<<endl;
    for(i=0;i<=15;i++) {
        for(j=0;j<=3;j++) {
            cout<<setw(15)<<fr[4*i+j];
        }
        cout<<endl;
    }
    cout<<"��������p�ı任���鲿fi:"<<endl;
    for(i=0;i<=15;i++) {
        for(j=0;j<=3;j++) {
            cout<<setw(15)<<fi[4*i+j];
        }
        cout<<endl;
    }
    cout<<"��������p�ı任��ģ: "<<endl;
    for(i=0;i<=15;i++) {
        for(j=0;j<=3;j++) {
            cout<<setw(15)<<pr[4*i+j];
        }
        cout<<endl;
    }
    cout<<"��������p�ı任�ķ���: "<<endl;
    for(i=0;i<=15;i++) {
        for(j=0;j<=3;j++) {
            cout<<setw(15)<<pi[4*i+j];
        }
        cout<<endl;
    }
    fast_fourier_trans(64,6,fr,fi,pr,pi,1);
    cout<<"��任��ʵ��pr:"<<endl;
    for(i=0;i<=15;i++) {
        for(j=0;j<=3;j++) {
            cout<<setw(15)<<pr[4*i+j];
        }
        cout<<endl;
    }
    cout<<"��任���鲿pi:"<<endl;
    for(i=0;i<=15;i++) {
        for(j=0;j<=3;j++) {
            cout<<setw(15)<<pi[4*i+j];
        }
        cout<<endl;
    }
    cout<<"��任��ģ:"<<endl;
    for(i=0;i<=15;i++) {
        for(j=0;j<=3;j++) {
            cout<<setw(15)<<fr[4*i+j];
        }
        cout<<endl;
    }
    cout<<"��任�ķ���:"<<endl;
    for(i=0;i<=15;i++) {
        for(j=0;j<=3;j++) {
            cout<<setw(15)<<fi[4*i+j];
        }
        cout<<endl;
    }
    return 0;
}
