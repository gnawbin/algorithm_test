//
// Created by one on 2024/11/4.
//

#ifndef SPECIALFUNCTION_H
#define SPECIALFUNCTION_H
#include  <iostream>
#include  <cmath>
using namespace std;
class SpecialFunction {
private:
public:
    double gamma(double x);                //Gamma函数
    double ingamma(double a, double x);    //不完全Gamma函数
    double errf(double x);                 //误差函数
    double bessel_1(int n, double x);      //第一类整数阶Bessel函数
   double bessel_2(int n, double x);      //第二类整数阶Bessel函数
    double b_bessel_1(int n, double x);    //变型第一类整数阶Bessel函数
   /*  double b_bessel_2(int n, double x);    //变型第二类整数阶Bessel函数
    double inbeta(double a, double b, double x);//不完全Beta函数
    double bt(double,double,double);
    double gass(double a, double d, double x);//正态分布函数
    double student(double t, int n);       //t_分布函数
    double chii(double x, int n);          //X平方分布函数
    double ffff(double f, int n1, int n2); //F_分布函数
    double sinn(double x);                 //正弦积分
    double coss(double x);                 //余弦积分
    double expp(double x);                 //指数积分
    double elp1(double k, double f);       //第一类椭圆积分
    double fk(double,double);
    double elp2(double k, double f);       //第二类椭圆积分
    double ek(double,double);*/

};

/**
 * 变形第一类整数阶Bassel函数
 * @param n 阶数
 * @param x 自变量
 * @return
 */
inline double SpecialFunction::b_bessel_1(int n, double x) {
	int i,m;
	double t,y,p,b0,b1,q;
	double a[7]={ 1.0,3.5156229,3.0899424,1.2067492,
					   0.2659732,0.0360768,0.0045813};
	double b[7]={ 0.5,0.87890594,0.51498869,
				  0.15084934,0.02658773,0.00301532,0.00032411};
	double c[9]={ 0.39894228,0.01328592,0.00225319,
				  -0.00157565,0.00916281,-0.02057706,
				   0.02635537,-0.01647633,0.00392377};
	double d[9]={ 0.39894228,-0.03988024,-0.00362018,
				  0.00163801,-0.01031555,0.02282967,
				  -0.02895312,0.01787654,-0.00420059};
	if (n<0) n=-n;
	t=fabs(x);
	if (n!=1)
	{
		if (t<3.75)
		{
			y=(x/3.75)*(x/3.75); p=a[6];
			for (i=5; i>=0; i--) p=p*y+a[i];
		}
		else
		{
			y=3.75/t; p=c[8];
			for (i=7; i>=0; i--) p=p*y+c[i];
			p=p*exp(t)/sqrt(t);
		}
	}
	if (n==0) return(p);
	q=p;
	if (t<3.75)
	{
		y=(x/3.75)*(x/3.75); p=b[6];
		for (i=5; i>=0; i--) p=p*y+b[i];
		p=p*t;
	}
	else
	{
		y=3.75/t; p=d[8];
		for (i=7; i>=0; i--) p=p*y+d[i];
		p=p*exp(t)/sqrt(t);
	}
	if (x<0.0) p=-p;
	if (n==1) return(p);
	if (x==0.0) return(0.0);
	y=2.0/t; t=0.0; b1=1.0; b0=0.0;
	m=n+(int)sqrt(40.0*n);
	m=2*m;
	for (i=m; i>0; i--)
	{
		p=b0+i*y*b1; b0=b1; b1=p;
		if (fabs(b1)>1.0e+10)
		{
			t=t*1.0e-10; b0=b0*1.0e-10;
			b1=b1*1.0e-10;
		}
		if (i==n) t=b0;
	}
	p=t*q/b1;
	if ((x<0.0)&&(n%2==1)) p=-p;
	return(p);

}


/**
 * 
 * @param n 阶数，要求n>0
 * @param x 自变量值
 * @return 
 */
inline double SpecialFunction::bessel_2(int n, double x) {
      int i;
      double y,z,p,q,s,b0,b1;
      double a[6]={ -2.957821389e+9,7.062834065e+9,-5.123598036e+8,
		            1.087988129e+7,-8.632792757e+4,2.284622733e+2};
      double b[6]={ 4.0076544269e+10,7.452499648e+8,7.189466438e+6,
		            4.74472647e+4,2.261030244e+2,1.0};
      double c[6]={ -4.900604943e+12,1.27527439e+12,-5.153438139e+10,
		            7.349264551e+8,-4.237922726e+6,8.511937935e+3};
      double d[7]={ 2.49958057e+13,4.244419664e+11,3.733650367e+9,
		            2.245904002e+7,1.02042605e+5,3.549632885e+2,1.0};
      double e[5]={ 1.0,-0.1098628627e-02,0.2734510407e-04,
		            -0.2073370639e-05,0.2093887211e-06};
      double f[5]={ -0.1562499995e-01,0.1430488765e-03,-0.6911147651e-05,
                     0.7621095161e-06,-0.934935152e-07};
      double g[5]={ 1.0,0.183105e-02,-0.3516396496e-04,0.2457520174e-05,
                    -0.240337019e-06};
      double h[5]={ 0.4687499995e-01, -0.2002690873e-03,0.8449199096e-05,
                    -0.88228987e-06,0.105787412e-06};
      if (n<0) n=-n;
      if (x<0.0) x=-x;
      if (x==0.0) return(-1.0e+70);
      if (n!=1)
      {
		  if (x<8.0)
          {
			  y=x*x; p=a[5]; q=b[5];
	          for (i=4; i>=0; i--)
              {
				  p=p*y+a[i]; q=q*y+b[i];
			  }
              p=p/q+0.636619772*bessel_1(0,x)*log(x);
          }
          else
          {
			  z=8.0/x; y=z*z;
              p=e[4]; q=f[4];
              for (i=3; i>=0; i--)
              {
				  p=p*y+e[i]; q=q*y+f[i];
			  }
              s=x-0.785398164;
              p=p*sin(s)+z*q*cos(s);
              p=p*sqrt(0.636619772/x);
          }
      }
      if (n==0) return(p);
      b0=p;
      if (x<8.0)
      {
		  y=x*x; p=c[5]; q=d[6];
          for (i=4; i>=0; i--)
          {
			  p=p*y+c[i]; q=q*y+d[i+1];
		  }
          q=q*y+d[0];
          p=x*p/q+0.636619772*(bessel_1(1,x)*log(x)-1.0/x);;
      }
      else
      {
		  z=8.0/x; y=z*z;
          p=g[4]; q=h[4];
          for (i=3; i>=0; i--)
          {
			  p=p*y+g[i]; q=q*y+h[i];
		  }
          s=x-2.356194491;
          p=p*sin(s)+z*q*cos(s);
          p=p*sqrt(0.636619772/x);
      }
      if (n==1) return(p);
      b1=p;
      s=2.0/x;
      for (i=1; i<=n-1; i++)
      {
		  p=s*i*b1-b0; b0=b1; b1=p;
	  }
      return(p);

}


/**
 * 第一类整数阶贝塞尔函数值
 * @param n  第1类整数阶贝塞尔函数的阶数，要求n>=0,当n<0时,本函数按|n|计算
 * @param x 自变量
 * @return
 */
inline double SpecialFunction::bessel_1(int n, double x) {
   int i,m;
      double t,y,z,p,q,s,b0,b1;
      double a[6]={ 57568490574.0,-13362590354.0,651619640.7,
		           -11214424.18,77392.33017,-184.9052456};
      double b[6]={ 57568490411.0,1029532985.0,9494680.718,
		            59272.64853,267.8532712,1.0};
      double c[6]={ 72362614232.0,-7895059235.0,242396853.1,
		           -2972611.439,15704.4826,-30.16036606};
      double d[6]={ 144725228443.0,2300535178.0,18583304.74,
		            99447.43394,376.9991397,1.0};
      double e[5]={ 1.0,-0.1098628627e-02,0.2734510407e-04,
		            -0.2073370639e-05,0.2093887211e-06};
      double f[5]={ -0.1562499995e-01,0.1430488765e-03,-0.6911147651e-05,
                     0.7621095161e-06,-0.934935152e-07};
      double g[5]={ 1.0,0.183105e-02,-0.3516396496e-04,
		            0.2457520174e-05,-0.240337019e-06};
      double h[5]={ 0.4687499995e-01,-0.2002690873e-03,0.8449199096e-05,
                    -0.88228987e-06,0.105787412e-06};
      t=fabs(x);
      if (n<0) n=-n;
      if (n!=1)
      {
		  if (t<8.0)
          {
			  y=t*t; p=a[5]; q=b[5];
	          for (i=4; i>=0; i--)
              {
				  p=p*y+a[i]; q=q*y+b[i];
			  }
              p=p/q;
          }
          else
          {
			  z=8.0/t; y=z*z;
              p=e[4]; q=f[4];
              for (i=3; i>=0; i--)
              {
				  p=p*y+e[i]; q=q*y+f[i];
			  }
              s=t-0.785398164;
              p=p*cos(s)-z*q*sin(s);
              p=p*sqrt(0.636619772/t);
          }
      }
      if (n==0) return(p);
      b0=p;
      if (t<8.0)
      {
		  y=t*t; p=c[5]; q=d[5];
          for (i=4; i>=0; i--)
          {
			  p=p*y+c[i]; q=q*y+d[i];
		  }
          p=x*p/q;
      }
      else
      {
		  z=8.0/t; y=z*z;
          p=g[4]; q=h[4];
          for (i=3; i>=0; i--)
          {
			  p=p*y+g[i]; q=q*y+h[i];
		  }
          s=t-2.356194491;
          p=p*cos(s)-z*q*sin(s);
          p=p*x*sqrt(0.636619772/t)/t;
      }
      if (n==1) return(p);
      b1=p;
      if (x==0.0) return(0.0);
      s=2.0/t;
      if (t>1.0*n)
      {
		  if (x<0.0) b1=-b1;
          for (i=1; i<=n-1; i++)
          {
			  p=s*i*b1-b0; b0=b1; b1=p;
		  }
      }
      else
      {
		  m=(n+(int)sqrt(40.0*n))/2;
          m=2*m;
          p=0.0; q=0.0; b0=1.0; b1=0.0;
          for (i=m-1; i>=0; i--)
          {
			  t=s*(i+1)*b0-b1;
              b1=b0; b0=t;
              if (fabs(b0)>1.0e+10)
              {
				  b0=b0*1.0e-10; b1=b1*1.0e-10;
                  p=p*1.0e-10; q=q*1.0e-10;
              }
              if ((i+2)%2==0) q=q+b0;
              if ((i+1)==n) p=b1;
          }
          q=2.0*q-b0; p=p/q;
      }
      if ((x<0.0)&&(n%2==1)) p=-p;
      return(p);
}

/**
 * 
 * @param x 自变量值
 * @return 
 */
inline double SpecialFunction::errf(double x) {
    double y;
    if (x>=0.0) y=ingamma(0.5,x*x);
    else y=-ingamma(0.5,x*x);
    return(y);

}

/**
 * 计算不完全伽马函数（Incomplete Gamma Function）
 * @param a 自变量a的值，要求a>0，若a<=0,返回函数值-1.0
 * @param x 自变量x的值，要求a>0,,要求x>0，若x<=0,返回函数值-1.0
 * @return
 */
inline double SpecialFunction::ingamma(double a, double x)
{
    int n, flag;
    double p,q,d,s,s1,p0,q0,p1,q1,qq;
    if ((a<=0.0)||(x<0.0))
    {
        if (a<=0.0) cout <<"err**a<=0!\n";
        if (x<=0.0) cout <<"err**x<0!\n";
        return(-1.0);
    }
    if (x+1.0==1.0) return(0.0);
    if (x>1.0e+35) return(1.0);
    q=log(x); q=a*q; qq=exp(q);
    if (x<1.0+a)
    {
        p=a; d=1.0/a; s=d; n = 0;
        do
        {
            n = n + 1;
            p = p+1.0; d = d*x/p; s = s+d;
            flag = (fabs(d)>=fabs(s)*1.0e-07);
        }
        while ((n<=100)&&(flag));
        if (!flag)
        {
            s = s*exp(-x)*qq/gamma(a);
            return(s);
        }
    }
    else
    {
        s=1.0/x; p0=0.0; p1=1.0; q0=1.0; q1=x;
        for (n=1; n<=100; n++)
        {
            p0=p1+(n-a)*p0; q0=q1+(n-a)*q0;
            p=x*p0+n*p1; q=x*q0+n*q1;
            if (fabs(q)+1.0!=1.0)
            {
                s1=p/q; p1=p; q1=q;
                if (fabs((s1-s)/s1)<1.0e-07)
                {
                    s=s1*exp(-x)*qq/gamma(a);
                    return(1.0-s);
                }
                s=s1;
            }
            p1=p; q1=q;
        }
    }
    cout <<"a too large !\n";
    s=1.0-s*exp(-x)*qq/gamma(a);
    return(s);

}
/**
 * 计算实变量x的伽马(Gamma)函数值
 * @param x
 * @return
 */
inline double SpecialFunction::gamma(double x) {
    int i;
    double y,t,s,u;
    double a[11]={ 0.0000677106,-0.0003442342,
         0.0015397681,-0.0024467480,0.0109736958,
         -0.0002109075,0.0742379071,0.0815782188,
         0.4118402518,0.4227843370,1.0};
    if (x<=0.0)
    {
        cout <<"err**x<=0!\n";
        return(-1.0);
    }
    y=x;
    if (y<=1.0) {  t=1.0/(y*(y+1.0)); y=y+2.0;}
    else if (y<=2.0) {  t=1.0/y; y=y+1.0; }
    else if (y<=3.0) t=1.0;
    else
    {
        t=1.0;
        while (y>3.0) { y=y-1.0; t=t*y;}
    }
    s=a[0]; u=y-2.0;
    for (i=1; i<=10; i++)  s=s*u+a[i];
    s=s*t;
    return(s);
}

#endif //SPECIALFUNCTION_H
