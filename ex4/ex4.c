#include<stdio.h>
#include<stdlib.h>

int main(void){
  int i,j;
  double m[102][102],x[102],x2[102],t=0,inval_t=0.1,inval=0.25,end_t=1;
  FILE *f;

  if ((f = fopen("plot4.txt", "w")) == NULL) {
    printf("file open error!!\n");
  }
  for(i=0;i<102;i++){
    for(j=0;j<102;j++){
      m[i][j] = 0;
    }
    x[i] = 0;
    x2[i] = 0;
  }
  x[50] = 1;
  for(i=1;i<101;i++){
    m[i][i-1] = inval;
    m[i][i] = 1 - 2*inval;
    m[i][i+1] = inval;
  }
  while(1){
    if(end_t <= t){
      break;
    }
    fprintf(f,"%f\n\n",t);
    for(i=0;i<102;i++){
      for(j=0;j<102;j++){
	x2[i] += m[i][j]*x[j];
      }
      fprintf(f,"%f\n",x2[i]);
    }
    fprintf(f,"\n");
    t += inval_t;
    for(i=0;i<102;i++){
      x[i] = x2[i];
      x2[i] = 0;
    }    
  }

  return 0;
}
