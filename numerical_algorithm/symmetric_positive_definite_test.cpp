//
// Created by one on 2024/10/14.
//
#include <iostream>
#include "symmetric_positive_definite.h"
#include "MatrixMulti.h"
using namespace std;
int main(int argc,char **argv)
{
    int i,j;
    double a[4][4]={ {5.0,7.0,6.0,5.0},
                         {7.0,10.0,8.0,7.0},
                         {6.0,8.0,10.0,9.0},
                         {5.0,7.0,9.0,10.0}};
    double b[4][4],c[4][4];
    for (i=0; i<=3; i++) {
        for (j=0; j<=3; j++) { b[i][j]=a[i][j];}
    }
    i=symmetric_positive_definite(&b[0][0],4);
    if(i>0) {
        cout<<"¾ØÕó A"<<endl;
        for(i=0;i<=3;i++) {
            for(j=0;j<=3;j++) {
                cout<<a[i][j]<<"  ";
            }
            cout<<endl;
        }
        cout<<"Äæ¾ØÕó A-"<<endl;
        for(i=0;i<=3;i++) {
            for(j=0;j<=3;j++) {
                cout<<b[i][j]<<"  ";
            }
            cout<<endl;
        }
        matrix_mul(&a[0][0],4,4,&b[0][0],4,4,&c[0][0]);
        cout<<"Ð£Ñé¾ØÕóAA-:"<<endl;
        for(i=0;i<=3;i++) {
            for(j=0;j<=3;j++) {
                cout<<c[i][j]<<" ";
            }
            cout<<endl;
        }
    }

    return 0;
}
