//
// Created by one on 2024/10/16.
//
#include "singular_value_decomposition.h"
#include "MatrixMulti.h"
int main(int argc,char *argv[]) {
  int i,j;
      double a[4][3]={ {1.0,1.0,-1.0},{2.0,1.0,0.0},
                           {1.0,-1.0,0.0},{-1.0,2.0,1.0}};
      double b[3][4]={ {1.0,1.0,-1.0,-1.0},{2.0,1.0,
                            0.0,2.0},{1.0,-1.0,0.0,1.0}};
      static double u[4][4],v[3][3],c[4][3],d[3][4];
      double eps;
      eps=0.000001;
	  cout <<"矩阵 A" <<endl;
      i=singular_value_decomposition(&a[0][0],4,3,&u[0][0],&v[0][0],eps,5);
      if (i>0)
	  {
		  cout <<"MAT U IS:" <<endl;
          for (i=0; i<=3; i++)
		  {
			  for (j=0; j<=3; j++)  cout <<u[i][j] <<"    ";
              cout <<endl;
		  }
          cout <<"MAT V IS:" <<endl;
          for (i=0; i<=2; i++)
		  {
			  for (j=0; j<=2; j++)  cout <<v[i][j] <<"    ";
              cout <<endl;
		  }
          cout <<"MAT A IS:" <<endl;
          for (i=0; i<=3; i++)
		  {
			  for (j=0; j<=2; j++)  cout <<a[i][j] <<"    ";
              cout <<endl;
		  }
          cout <<"MAT UAV IS:" <<endl;
        matrix_mul(&u[0][0],4,4,&a[0][0],4,3,&c[0][0]);
        matrix_mul(&c[0][0],4,3,&v[0][0],3,3,&a[0][0]);
          for (i=0; i<=3; i++)
		  {
			  for (j=0; j<=2; j++)  cout <<a[i][j] <<"    ";
              cout <<endl;
		  }
	  }
      cout <<endl;
	  cout <<"矩阵 B" <<endl;
      i=singular_value_decomposition(&b[0][0],3,4,&v[0][0],&u[0][0],eps,5);
      if (i>0)
	  {
		  cout <<"MAT U IS:" <<endl;
          for (i=0; i<=2; i++)
		  {
			  for (j=0; j<=2; j++)  cout <<v[i][j] <<"    ";
              cout <<endl;
		  }
          cout <<"MAT V IS:" <<endl;
          for (i=0; i<=3; i++)
		  {
			  for (j=0; j<=3; j++)  cout <<u[i][j] <<"    ";
              cout <<endl;
		  }
          cout <<"MAT B IS:" <<endl;
          for (i=0; i<=2; i++)
		  {
			  for (j=0; j<=3; j++)  cout <<b[i][j] <<"    ";
              cout <<endl;
		  }
          cout <<"MAT UBV IS:" <<endl;
          matrix_mul(&v[0][0],3,3,&b[0][0],3,4,&d[0][0]);
         matrix_mul(&d[0][0],3,4,&u[0][0],4,4,&b[0][0]);
          for (i=0; i<=2; i++)
		  {
			  for (j=0; j<=3; j++)  cout <<b[i][j] <<"    ";
              cout <<endl;
		  }
	  }
	  return 0;

}