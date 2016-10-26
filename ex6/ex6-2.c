#include<stdio.h>
#include<stdlib.h>



int main(void){
  int i,j;
  double x[102][102],x2[102][102],y[102][102],y2[102][102],t=0,end_t=50,inval_t=0.002,dx=0.05,Dx=0.01,Dy=0.05,a=2,b=4;
  //xの刻み幅とyの刻み幅は同じとするためdyは記述していません
  FILE *f;
  
  if ((f = fopen("plot6_2-4.txt", "w")) == NULL) {
    printf("file open error!!\n");
  }
  
  for(i=0;i<102;i++){
    for(j=0;j<102;j++){
      x[i][j] = (double)rand()/RAND_MAX*10.0;
      y[i][j] = (double)rand()/RAND_MAX*10.0;
    }}
  for(i=0;i<102;i++){
    x[0][i] = x[1][i];
    x[101][i] = x[100][i];
    x[i][0] = x[i][1];
    x[i][101] = x[i][100];
    y[0][i] = y[1][i];
    y[101][i] = y[100][i];
    y[i][0] = y[i][1];
    y[i][101] = y[i][100];
  }
  while(1){
    if(end_t <= t){
      break;
    }
    for(i=1;i<101;i++){
      for(j=1;j<101;j++){
        //dy == dx なので式を省略
	x2[i][j] = a - b*x[i][j] + x[i][j]*x[i][j]*y[i][j] - x[i][j] + Dx*(x[i-1][j] - 2*x[i][j] + x[i+1][j] + x[i][j-1] -2*x[i][j] + x[i][j+1])/(dx*dx);
	y2[i][j] = b*x[i][j] - x[i][j]*x[i][j]*y[i][j] + Dy*(y[i-1][j] -2*y[i][j] + y[i+1][j] + y[i][j-1] -2*y[i][j] + y[i][j+1])/(dx*dx);
      }}
    for(i=0;i<102;i++){
      x2[0][i] = x2[1][i];
      x2[101][i] = x2[100][i];
      x2[i][0] = x2[i][1];
      x2[i][101] = x2[i][101];
      y2[0][i] = y2[1][i];
      y2[101][i] = y2[100][i];
      y2[i][0] = y2[i][1];
      y2[i][101] = y2[i][100];
    }
    //euler
    for(i=0;i<102;i++){
	for(j=0;j<102;j++){
      	  x[i][j] = x[i][j] + inval_t*x2[i][j];
      	  y[i][j] = y[i][j] + inval_t*y2[i][j];
    }}
    t += inval_t;
  }
  
  for(i=0;i<102;i++){
    for(j=0;j<102;j++){
      fprintf(f,"%d\t%d\t%f\t%f\n",i,j,x[i][j],y[i][j]);
    }}
  
  return 0;
}
