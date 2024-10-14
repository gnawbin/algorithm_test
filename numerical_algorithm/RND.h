//
// Created by one on 2024/10/14.
//

#ifndef RND_H
#define RND_H
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
class RND{
  private:
     int R;
  public:
     RND(int r=1){
       R=r;
     }
     //产生0-1均匀分布的一个随机数
     double rnd1(){
        int m;
        double s,u,v,p;
        s=65536.0;
        u=2053.0;
        v=13849.0;
        m=static_cast<int>(R/s);
        R=R-m*s;
        R=u*R+v;
       m=static_cast<int>(R/s);
        R=static_cast<int>(R-m*s);
        p=R/s;
        return (p);
     }
     //产生给定区间[a,b]内均匀分布的一个随机整数
     int rndab(int a,int b){
       int k,j,m,i,p;
       k=b-a+1;
       j=2;
       while(j<k) j=j+j;
       m=4*j;
       k=R;
       i=1;
       while(i<=1){
        k=k+k+k+k+k;
        k=k%m;
        j=k/4+a;
        if(j<=b){
           p=j;i=i+1;
         }
       }
       R=k;
       return (p);
     }
     //产生给定均值u与方差的正态分布的一个随机数
     double rndg(double u,double g){
     int  i,m;
       double s,w,v,t;
       s=65536.0;w=2053.0;v=13849.0;
       t=0.0;
       for(i=1;i<=12;i++){
         R=R*w+v;
         m=static_cast<int>(R/s);
         R=R-m*s;
         t=t+R/s;
       }
       t=u+g*(t-6.0);
       return (t);
     }

};

#endif //RND_H
