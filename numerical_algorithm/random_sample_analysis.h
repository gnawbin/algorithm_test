//
// Created by one on 2024/10/13.
//

#ifndef RANDOM_SAMPLE_ANALYSIS_H
#define RANDOM_SAMPLE_ANALYSIS_H
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
//n �����������
//x[n] ������������n��������ֵ
//m ֱ��ͼ����������
//x0 ֱ��ͼ�������������ʼֵ
//h ֱ��ͼ��������������䳤��ֵ
//g[m] ����m������İ���˹�ֲ���Ӧ�еĽ���������������
//q[m] ��������m��������ÿһ�������ϵ��������ʵ�ʵ���
//dt[3] dt[0] �����������������ƽ��ֵ
//      dt[1] ������������ķ���
//      dt[2] ������������ı�׼��
//k   k=0��������Ҫ���ֱ��ͼ�� k=1 ��ʾ��Ҫ���ֱ��ͼ
void random_sample_analysis(int n,double x[],int m,double x0,double h, int g[],int q[],double dt[3],int k) {
    int i,j,kk,z;
    double s;
    char a[50];
    dt[0]=0.0;
    for(i=0;i<=n-1;i++)  //�������������ƽ��ֵ
        dt[0]=dt[0]+x[i]/n;
    dt[1]=0.0;
    for(i=0;i<=n-1;i++)
        dt[1]=dt[1]+(x[i]-dt[0])*(x[i]-dt[0]);
    dt[1]=dt[1]/n;//��������ķ���
    dt[2]=sqrt(dt[1]);//��������ı�׼��
    for(i=0;i<=m-1;i++) {//����˹�ֲ���Ӧ�еĽ���������������
        q[i]=0;
        s=x0+(i+0.5)*h-dt[0];
        s=exp(-s*s/(2.0*dt[1]));
        g[i]=static_cast<int>(n*s*h/(dt[2]*2.5066));
    }
    s=x0+m*h;
    for(i=0;i<=n-1;i++) //����ÿһ�������ϵ��������ʵ�ʵ���
        if((x[i]-x0)>=0.0) {
            if((s-x[i])>=0.0) {
                j=static_cast<int>((x[i]-x0)/h);
                q[j]=q[j]+1;
            }
        }
    if(k==0) return;
    cout<<"n="<<n<<endl;
    cout<<"���������ʼֵ x0="<<x0<<endl;
    cout<<"����������䳤�� h="<<h<<endl;
    cout<<"ֱ��ͼ�������� m="<<m<<endl;
    cout<<"��������ƽ��ֵ="<<dt[0]<<endl;
    cout<<"�����ķ���="<<dt[1]<<endl;
    cout<<"�����ı�׼��="<<dt[2]<<endl;
    kk=1;z=0;
    for(i=0;i<=m-1;i++)
        if(q[i]>z) z=q[i];
    while (z>50) {
        z=z/2;
        kk=2*kk;//kkΪ����ϵ��
    }
    cout<<"�����е�  ʵ�ʵ���   ֱ��ͼ"<<endl;
    for(i=0;i<=m-1;i++) {
        s=x0+(i+0.5)*h;//�����м��
        for(j=0;j<=49;j++) {
            a[j] =' ';
        }
        j=q[i]/kk;
        for(z=0;z<=j-1;z++) a[z]='X';//ʵ�ʵ�λ�÷���
        j=g[i]/kk;
        if(j>0&&j<50) a[j]='*';//���۵���λ�÷���
        cout<<setw(8)<<s<<setw(10)<<q[i]<<"  ";
        for(j=0;j<=49;j++) cout<<a[j];
        cout<<endl;



    }

  cout<<"���� 1:" <<kk<<endl;

}
#endif //RANDOM_SAMPLE_ANALYSIS_H
