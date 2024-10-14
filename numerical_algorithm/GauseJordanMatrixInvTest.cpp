//
// Created by one on 2024/10/12.
//
#include <iostream>
#include <cmath>
#include <iostream>
#include "GaussJordanMatrixInv.h"
using namespace std;
int main(int argc,char *argv[])
{
     int i,j;
     double a[4][4]={
         {0.2368,0.2471,0.2568,1.2671},
         {1.1161,0.1254,0.1397,0.1490},
         {0.1582,1.1675,0.1768,0.1871},
         {0.1968,0.2071,1.2168,0.2271}
     };
    double b[4][4];
    for(i=0;i<4;i++) {
        for(j=0;j<4;j++) {
            b[i][j]=a[i][j];
        }
    }
   i=guass_jordan_matrix_inv(&b[0][0],4);
   if(i!=0) {
        cout<<"Êµ¾ØÕó A:"<<endl;
        for(i=0;i<4;i++) {
            for(j=0;j<4;j++){
                cout<<a[i][j]<<" ";
            }
            cout<<endl;
        }
       cout<<"Äæ¾ØÕóA-:"<<endl;
       for(i=0;i<4;i++) {
           for(j=0;j<4;j++){
               cout<<b[i][j]<<" ";
           }
           cout<<endl;
       }
  }
    Complex bb[4][4];
    Complex aa[4][4]={
        {Complex(0.2368,0.1345),Complex(0.2471,0.1678),Complex(0.2568,0.1875),Complex(1.2671,1.1161)},
        {Complex(1.1161,1.2671),Complex(0.1254,0.2017),Complex(0.1397,0.7024),Complex(0.1490,0.2721)},
        {Complex(0.1582,-0.2836),Complex(1.1675,-1.1967),Complex(0.1768,0.3556),Complex(0.1871,-0.2078)},
        {Complex(0.1968,0.3576),Complex(0.2071,-1.2345),Complex(1.2168,2.1185),Complex(0.2271,0.4773)}
    };
    for(i=0;i<4;i++) {
        for(j=0;j<4;j++) {
            bb[i][j]=aa[i][j];
        }
    }
    i=guass_jordan_matrix_inv(&bb[0][0],4);

    if(i!=0) {
        cout<<"¸´¾ØÕó A"<<endl;
        for(i=0;i<4;i++) {
            for(j=0;j<4;j++) {

                 aa[i][j].prt();
            }
            cout<<endl;
        }
        cout<<"Äæ¾ØÕó A-"<<endl;
        for(i=0;i<4;i++){
            for(j=0;j<4;j++) {

                bb[i][j].prt();
            }
            cout<<endl;
      }
    }

 //   std::cout << "Hello, World!" << std::endl;
    return 0;
}
