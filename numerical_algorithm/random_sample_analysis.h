//
// Created by one on 2024/10/13.
//

#ifndef RANDOM_SAMPLE_ANALYSIS_H
#define RANDOM_SAMPLE_ANALYSIS_H
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
//n 随机样本点数
//x[n] 存放随机变量的n个样本点值
//m 直方图中区间总数
//x0 直方图中随机变量的起始值
//h 直方图中随机变量等区间长度值
//g[m] 返回m个区间的按高斯分布所应有的近似理论样本点数
//q[m] 返回落在m个区间中每一个区间上的随机样本实际点数
//dt[3] dt[0] 返回随机样本的算数平均值
//      dt[1] 返回随机样本的方差
//      dt[2] 返回随机样本的标准差
//k   k=0表述不需要输出直方图； k=1 表示需要输出直方图
void random_sample_analysis(int n,double x[],int m,double x0,double h, int g[],int q[],double dt[3],int k) {
    int i,j,kk,z;
    double s;
    char a[50];
    dt[0]=0.0;
    for(i=0;i<=n-1;i++)  //随机样本的算术平均值
        dt[0]=dt[0]+x[i]/n;
    dt[1]=0.0;
    for(i=0;i<=n-1;i++)
        dt[1]=dt[1]+(x[i]-dt[0])*(x[i]-dt[0]);
    dt[1]=dt[1]/n;//随机样本的方差
    dt[2]=sqrt(dt[1]);//随机样本的标准差
    for(i=0;i<=m-1;i++) {//按高斯分布所应有的近似理论样本点数
        q[i]=0;
        s=x0+(i+0.5)*h-dt[0];
        s=exp(-s*s/(2.0*dt[1]));
        g[i]=static_cast<int>(n*s*h/(dt[2]*2.5066));
    }
    s=x0+m*h;
    for(i=0;i<=n-1;i++) //落在每一个区间上的随机样本实际点数
        if((x[i]-x0)>=0.0) {
            if((s-x[i])>=0.0) {
                j=static_cast<int>((x[i]-x0)/h);
                q[j]=q[j]+1;
            }
        }
    if(k==0) return;
    cout<<"n="<<n<<endl;
    cout<<"随机变量起始值 x0="<<x0<<endl;
    cout<<"随机变量区间长度 h="<<h<<endl;
    cout<<"直方图区间总数 m="<<m<<endl;
    cout<<"样本算术平均值="<<dt[0]<<endl;
    cout<<"样本的方差="<<dt[1]<<endl;
    cout<<"样本的标准差="<<dt[2]<<endl;
    kk=1;z=0;
    for(i=0;i<=m-1;i++)
        if(q[i]>z) z=q[i];
    while (z>50) {
        z=z/2;
        kk=2*kk;//kk为比例系数
    }
    cout<<"区间中点  实际点数   直方图"<<endl;
    for(i=0;i<=m-1;i++) {
        s=x0+(i+0.5)*h;//区间中间点
        for(j=0;j<=49;j++) {
            a[j] =' ';
        }
        j=q[i]/kk;
        for(z=0;z<=j-1;z++) a[z]='X';//实际点位置符号
        j=g[i]/kk;
        if(j>0&&j<50) a[j]='*';//理论点数位置符号
        cout<<setw(8)<<s<<setw(10)<<q[i]<<"  ";
        for(j=0;j<=49;j++) cout<<a[j];
        cout<<endl;



    }

  cout<<"比例 1:" <<kk<<endl;

}
#endif //RANDOM_SAMPLE_ANALYSIS_H
