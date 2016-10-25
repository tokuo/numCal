#include<stdio.h>
#include<stdlib.h>

int main(void){
  int i,j;
  double xy[102][102], xy2[102][102], t=0, inval_t=0.1, inval=0.25, end_t=50;
  FILE *f;

  if ((f = fopen("plot/plot4.txt", "w")) == NULL) {
    printf("file open error!!\n");
  }
  for(i=0;i<102;i++){
    for(j=0;j<102;j++){
      xy[i][j] = 0;
      xy2[i][j] = 0;
    }
  }
  xy[50][50] = 1;
  while(1){
    if(end_t <= t){
      break;
    }
    for(i=1;i<101;i++){
      for(j=1;j<101;j++){
      xy2[i][j] = inval*(xy[i-1][j] - 2*xy[i][j] + xy[i+1][j]) + inval*(xy[i][j-1] - 2*xy[i][j] + xy[i][j+1]);
      }    
    }
    for(i=0;i<102;i++){
      xy2[0][i] = xy2[1][i];
      xy2[i][0] = xy2[i][1];
      xy2[101][i] = xy2[100][i];
      xy2[i][101] = xy2[i][100];
    }
    for(i=0;i<102;i++){
      for(j=0;j<102;j++){
	xy[i][j] = xy[i][j] + inval_t*xy2[i][j];
	xy2[i][j] = 0;
      }
    }
    t += inval_t; 
  }

  for(i=0;i<102;i++){
    for(j=0;j<102;j++){
      fprintf(f,"%d\t%d\t%f\n",i,j,xy[i][j]);
    }
  }

  return 0;
}
