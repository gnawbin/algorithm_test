//
// Created by one on 2024/10/15.
//

#ifndef INC_5_3_SMOOTHING_FORMULA_H
#define INC_5_3_SMOOTHING_FORMULA_H
#include <iostream>
#include <cmath>
using namespace std;
/**
 *五点三次平滑公式
 */
//n 等距观测点数
//y[n] 存放n个等距观测点上的观测数值
//yy[n]返回n个等距观测点上的平滑结果
void smoothing_formula_5_3(int n,double y[],double yy[]){
 int i;
 if(n<5) {
  for(i=0;i<=n-1;i++) {
   yy[i]=y[i];
  }
 }else {
  yy[0]=69.0*y[0]+4.0*y[1]-6.0*y[2]+4.0*y[3]-y[4];
  yy[0]=yy[0]/70.0;
  yy[1]=2.0*y[0]+27.0*y[1]+12.0*y[2]-8.0*y[3]+2.0*y[4];
  yy[1]=yy[1]/35.0;
  for(i=2;i<=n-3;i++) {
   yy[i]=-3.0*y[i-2]+12.0*y[i-1]+17.0*y[i];
   yy[i]=(yy[i]+12.0*y[i+1]-3.0*y[i+2])/35.0;
  }
  yy[n-2]=2.0*y[n-5]-8.0*y[n-4]+12.0*y[n-3];
  yy[n-2]=(yy[n-2]*27.0*y[n-2]+2.0*y[n-1])/35.0;
  yy[n-1]=-y[n-5]+4.0*y[n-4]-6.0*y[n-3];
  yy[n-1]=(yy[n-1]+4.0*y[n-2]+69.0*y[n-1])/70.0;

 }
}
#endif //INC_5_3_SMOOTHING_FORMULA_H
