#include<stdio.h>
#include<stdlib.h>



int main(void){
  int i;
  double x[102],x2[102],y[102],y2[102],t=0,end_t=50,inval_t=0.002,dx=0.05,Dx=0.01,Dy=0.05,a=2,b=4;
  FILE *f;

  if ((f = fopen("plot6-4.txt", "w")) == NULL) {
    printf("file open error!!\n");
  }

  for(i=0;i<102;i++){
    x[i] = (double)rand()/RAND_MAX*10.0;
    y[i] = (double)rand()/RAND_MAX*10.0;
  }
  x2[0] = x2[1];
  x2[101] = x2[100];
  y2[0] = y2[1];
  y2[101] = y2[100];
  while(1){
    if(end_t <= t){
      break;
    }
    for(i=1;i<101;i++){
      x2[i] = a - b*x[i] + x[i]*x[i]*y[i] - x[i] + Dx*(x[i-1] -2*x[i] + x[i+1])/(dx*dx);
      y2[i] = b*x[i] - x[i]*x[i]*y[i] + Dy*(y[i-1] -2*y[i] + y[i+1])/(dx*dx);
    }
    x2[0] = x2[1];
    x2[101] = x2[100];
    y2[0] = y2[1];
    y2[101] = y2[100];
    //euler
    for(i=0;i<102;i++){
      x[i] = x[i] + inval_t*x2[i];
      y[i] = y[i] + inval_t*y2[i];
    }
    t += inval_t;
  }

  for(i=0;i<102;i++){
    fprintf(f,"%d\t%f\t%f\n",i,x[i],y[i]);
  }

  return 0;
}
