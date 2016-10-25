#include<stdio.h>
#include<stdlib.h>

double f(double x){
  return x*x*x - x*x - x;
}

double df(double x){
  return 3*x*x - 2*x - 1;
}

/*
double df2(double x){
  return 6*x - 2;
}
*/

//絶対値
double check(double num){
  if(num < 0){
    return -num;
  }
  return num;
}

//ニュートン法
void newton(double startx,double dif){
  double x=startx,flag;
  while(1){
    flag = f(x)/df(x);
    x = x - flag;
    printf("%f\n",x);
    if(check(flag) < dif){
      break;
    }
  }
}

//二分探索法
void bidis(double startx,double endx,double dif){
  double x1,x2,xmid,y1,y2,ymid;
  x1 = startx;
  x2 = endx;
  while(1){
    y1 = df(x1);
    y2 = df(x2);
    xmid = (x1+x2)/2;
    ymid = df(xmid);
    printf("%f\n",xmid);
    if(check(x2 - x1) < dif){
      break;
    }
    if(y1*ymid < 0){
      x2 = xmid;
    }else{
      x1 = xmid;
    }
  }
}


int main(void){
  double startx=-4;
//探索初期値
  //double endx=10;　2分探索法用の２つ目の探索初期値
  double dif=0.000001;
//終了条件
  newton(startx,dif);
  //bidis(startx,endx,dif);
  return 0;
}
