//
// Created by one on 2024/10/12.
//

#ifndef FAST_FOURIER_TRANS_H
#define FAST_FOURIER_TRANS_H
/**
 *快速沃什变换
*int n 采样点数
*int k 满足 n=2的k次阶乘
*double pr[n] 当flag=0时,存放n个采样输入的实部,返回离散傅里叶变换的模;当flag=1时，
*存放傅里叶变换的n个虚部，返回逆傅里叶变换的幅角。其中，俯角的单位为度
*double pi[n] 当flag=0时,存放n个采样输入的虚部，返回离散傅里叶变换的幅角;
* 当flag=1时，存放傅里叶变换的n个虚部，返回逆傅里叶变换的俯角。其中，俯角的单位为度。
*double fr[n] 当flag=0时，返回傅里叶变换的n个实部；当flag=1时,返回逆傅里叶变换的n个实部
*double fi[n] 当flag=0时，返回傅里叶变换的n个虚部;当flag=1时，返回逆傅里叶变换的n个虚部
*int flag 当flag=0时，表示要求本函数计算傅里叶变换；当flag=1时，表示要求本函数计算逆傅里叶变换
*
*
**/
void fast_fourier_trans(int n,int k,double pr[],double pi[],double fr[],double fi[],int flag){
  int it,m,is,i,j,nv,kk;
  double p,q,s,vr,vi,poddr,poddi;
  for(it=0;it<=n-1;it++){
      m=it;
      is=0;
      for(i=0;i<=k-1;i++) {
         j=m/2;
          is=2*is+(m-2*j);
          m=j;
      }
      fr[it]=pr[is];
      fi[it]=pi[is];
  }
    pr[0]=1.0;
    pi[0]=0.0;
    p=6.283185306/(1.0*n);
    pr[1]=cos(p);
    pi[1]=-sin(p);
    if(flag!=0){pi[1]=-pi[1];}
    for(i=2;i<=n-1;i++) {
        p=pr[i-1]*pr[1];
        q=pi[i-1]*pi[1];
        s=(pr[i-1]+pi[i-1])*(pr[1]+pi[1]);
        pr[i]=p-q;
        pi[i]=s-p-q;
    }
    for(it=0;it<=n-2;it=it+2) {
        vr=fr[it];
        vi=fi[it];
        fr[it]=vr+fr[it+1];
        fi[it]=vi+fi[it+1];
        fr[it+1]=vr-fr[it+1];
        fi[it+1]=vi-fi[it+1];
    }
    m=n/2;nv=2;
    for(kk=k-2;kk>=0;kk--) {
        m=m/2;
        nv=2*nv;
        for(it=0;it<=(m-1)*nv;it=it+nv)
            for(j=0;j<=(nv/2)-1;j++) {
                p=pr[m*j]*fr[it+j+nv/2];
                q=pi[m*j]*fi[it+j+nv/2];
                s=pr[m*j]+pi[m*j];
                s=s*(fr[it+j+nv/2]+fi[it+j+nv/2]);
                poddr=p-q;
                poddi=s-p-q;
                fr[it+j+nv/2]=fr[it+j]-poddr;
                fi[it+j+nv/2]=fi[it+j]-poddi;
                fr[it+j]=fr[it+j]+poddr;
                fi[it+j]=fi[it+j]+poddi;
            }
    }
    if(flag!=0) {
        //逆变换
        for(i=0;i<=n-1;i++) {
            fr[i]=fr[i]/(1.0*n);
            fi[i]=fi[i]/(1.0*n);
        }


    }
    for(i=0;i<=n-1;i++) {
        //计算交换的模与幅角
        pr[i]=sqrt(fr[i]*fr[i]+fi[i]*fi[i]);
        if(fabs(fr[i]<0.000001*fabs(fi[i]))) {
            if((fi[i]*fr[i])>0) {
                pi[i]=90.0;
            }else {
                pi[i]=-90.0;
            }
        }else {
            pi[i]=atan(fi[i]/fr[i])*360.0/6.283185306;
        }
    }

}
#endif //FAST_FOURIER_TRANS_H
