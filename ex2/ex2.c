#include<stdio.h>
#include<stdlib.h>

double df(double x){
  return -x;
}

void euler(double startx,double invaltime,double endtime){
  double x=startx,t=0;
  while(1){
    if(endtime <= t){
      break;
    }
    x = x + invaltime*df(x);
    t += invaltime;
    printf("%f\t%f\n",t,x);
  }
}

void runge_kutta(double startx,double invaltime,double endtime){
  double s1,s2,s3,s4,t=0,x=startx;
  while(1){
    if(endtime <= t){
      break;
    }
    s1 = df(x);
    s2 = df(x + invaltime*s1/2);
    s3 = df(x + invaltime*s2/2);
    s4 = df(x + invaltime*s3);
    x = x + invaltime*(s1 + 2*s2 + 2*s3 +s4)/6;
    t += invaltime;
    printf("%f\t%f\n",t,x);
  }
}


int main(void){
  double startx=10,invaltime=0.2,endtime=10;
  //euler(startx,invaltime,endtime);
  runge_kutta(startx,invaltime,endtime);
  return 0;
}
