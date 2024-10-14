//
// Created by one on 2024/10/14.
//
#include <iostream>
#include "trench_toeplitz_inv.h"
int main(int argc,char **argv[])
{
    int n,i,j,k;
    double t[6]={10.0,5.0,4.0,3.0,2.0,1.0};
    double tt[6]={0.0,-1.0,-2.0,-3.0,-4.0,-5.0};
    double b[6][6],a[6][6];
    n=6;
    i=trench_toeplitz_inv(t,tt,n,&b[0][0]);
    if(i>0) {
        cout <<"B=inv(T):\n";
        for (i=0; i<=5; i++)
        {
            for (j=0; j<=5; j++)  cout <<b[i][j] <<"  ";
            cout <<endl;
        }
        cout <<"A=T*B:\n";
        for (i=1; i<=6; i++)
            for (j=1; j<=6; j++)
            {
                a[i-1][j-1]=0.0;
                for (k=1; k<=j-1; k++)
                    a[i-1][j-1]=a[i-1][j-1]+b[i-1][k-1]*t[j-k];
                a[i-1][j-1]=a[i-1][j-1]+b[i-1][j-1]*t[0];
                for (k=j+1; k<=6; k++)
                    a[i-1][j-1]=a[i-1][j-1]+b[i-1][k-1]*tt[k-j];
            }
        for (i=0; i<=5; i++)
        {
            for (j=0; j<=5; j++)  cout <<a[i][j] <<"  ";
            cout <<endl;
        }


    }

    return 0;
}
