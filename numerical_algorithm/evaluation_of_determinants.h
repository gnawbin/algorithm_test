//
// Created by one on 2024/10/15.
//

#ifndef EVALUATION_OF_DETERMINANTS_H
#define EVALUATION_OF_DETERMINANTS_H
//行列式求值
#include <cmath>
#include <iostream>
using namespace std;
//a[n][n] 存放方阵A的元素，返回时被破坏
//函数返回行列式值
double evaluation_of_determinants(double a[],int n){
    int i,j,k,is,js,l,u,v;
    double f,det,q,d;
    f=1.0; det=1.0;
    for (k=0; k<=n-2; k++)
    { q=0.0;
        for (i=k; i<=n-1; i++)
            for (j=k; j<=n-1; j++)
            { l=i*n+j; d=fabs(a[l]);
                if (d>q) { q=d; is=i; js=j;}
            }
        if (q+1.0==1.0)
        { det=0.0; return(det);}
        if (is!=k)
        { f=-f;
            for (j=k; j<=n-1; j++)
            { u=k*n+j; v=is*n+j;
                d=a[u]; a[u]=a[v]; a[v]=d;
            }
        }
        if (js!=k)
        { f=-f;
            for (i=k; i<=n-1; i++)
            { u=i*n+js; v=i*n+k;
                d=a[u]; a[u]=a[v]; a[v]=d;
            }
        }
        l=k*n+k;
        det=det*a[l];
        for (i=k+1; i<=n-1; i++)
        { d=a[i*n+k]/a[l];
            for (j=k+1; j<=n-1; j++)
            { u=i*n+j;
                a[u]=a[u]-d*a[k*n+j];
            }
        }
    }
    det=f*det*a[n*n-1];
    return(det);

}
#endif //EVALUATION_OF_DETERMINANTS_H
