//
// Created by one on 2024/10/14.
//
#include "fast_walsh_series.h"
#include <iostream>
#include "fast_walsh_series.h"
int main(int argc,char *argv[])
{
    int i;
    double p[8],x[8];
    for(i=0;i<=7;i++) p[i]=i+1;
    fast_walsh_series(8,3,p,x);
    for(i=0;i<=7;i++)
      cout<<"x("<<i<<")="<<x[i]<<endl;
    return 0;
}
