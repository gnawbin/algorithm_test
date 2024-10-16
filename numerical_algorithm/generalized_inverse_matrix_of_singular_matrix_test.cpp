//
// Created by one on 2024/10/16.
//
#include "generalized_inverse_matrix_of_singular_matrix.h"
int main(int argc,char *argv) {
    int m,n,ka,i,j;
    double a[5][4]={ {1.0,2.0,3.0,4.0},
                {6.0,7.0,8.0,9.0},{1.0,2.0,13.0,0.0},
                {16.0,17.0,8.0,9.0},{2.0,4.0,3.0,4.0}};
    double aa[4][5],c[5][4],u[5][5],v[4][4];
    double eps;
    m=5; n=4; ka=6; eps=0.000001;
    cout <<"MAT A IS:\n";
    for (i=0; i<=4; i++)
    {
        for (j=0; j<=3; j++)  cout <<a[i][j] <<"    ";
        cout <<endl;
    }
    i=ginv(&a[0][0],m,n,&aa[0][0],eps,&u[0][0],&v[0][0],ka);
    if (i<0)  return 0;
    cout <<"MAT A+ IS:\n";
    for (i=0; i<=3; i++)
    {
        for (j=0; j<=4; j++)  cout <<aa[i][j] <<"    ";
        cout <<endl;
    }
    i=ginv(&aa[0][0],n,m,&c[0][0],eps,&v[0][0],&u[0][0],ka);
    if (i<0)  return 0;
    cout <<"MAT A++ IS:\n";
    for (i=0; i<=4; i++)
    {
        for (j=0; j<=3; j++)  cout <<c[i][j] <<"    ";
        cout <<endl;
    }
    return 0;

}