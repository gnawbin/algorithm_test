//
// Created by one on 2024/10/15.
//
#include "ingamma.h"
int main(int argc,char *argv[]) {
	int i,j;
	double y,s,t;
	double a[3]={0.5,5.0,50.0};
	double x[3]={0.1,1.0,10.0};
	for (i=0; i<=2; i++)
		for (j=0; j<=2; j++)
		{
			s=a[i]; t=x[j];
			y = ingamma(s,t);
			cout <<"ingamma(" <<a[i] <<", " <<x[j] <<") = " <<y <<endl;
		}
	return 0;


}