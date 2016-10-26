#include<stdlib.h>
#include<stdio.h>

double dfx(double a,double b,double x,double y){
  return a - b*x + x*x*y - x;
}

double dfy(double b,double x,double y){
  return b*x - x*x*y;
}

void euler(double startx,double starty,double invaltime,double endtime,double a,double b){
  double x=startx,y=starty,t=0,x2,y2;
  FILE *f;
  if ((f = fopen("plot5-4.txt", "w")) == NULL) {
    printf("file open error!!\n");
  }
  while(1){
    if(endtime <= t){
      break;
    }
    x2 = x + invaltime*dfx(a,b,x,y);
    y2 = y + invaltime*dfy(b,x,y);
    t += invaltime;
    x = x2;
    y = y2;
    fprintf(f,"%f\t%f\t%f\n",t,x2,y2);
  }
}

int main(void){
  double a=2,b=10,x=0,y=0,invaltime=0.01,endtime=30;
  euler(x,y,invaltime,endtime,a,b);
  return 0;
}
