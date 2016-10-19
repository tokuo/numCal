#include<stdio.h>
#include<stdlib.h>


double df(double s){
  return -s/(1.1 + s);
}

/*
double dff(double s,double e){
  if(s < e){
    return s/10;
  }else{
    return e/10;
  }
}
*/

double dfe(double s,double e,double es){
  return es/10 - s*e + es;
}

double dfes(double s,double e,double es){
  return s*e - es/10 - es;
}

/*
double dfs(double s,double e,double es){
  return es/10 - s*e;
}

double dfp(double es){
  return es;
}
*/

void euler(double starts,double invaltime,double endtime){
  double s=starts,t=0,e=1,es=0,p=0,e2,es2;
  FILE *fp;
  if ((fp = fopen("plot3.txt", "w")) == NULL) {
    printf("file open error!!\n");
  }
  while(1){
    if(endtime <= t){
      break;
    }
    s = s + invaltime*df(s);
    es2 = es + invaltime*dfes(s,e,es);
    e2 = e + invaltime*dfe(s,e,es);
    e = e2;
    es = es2;
    p = p + -invaltime*df(s);
    t += invaltime;
    fprintf(fp,"%f\t%f\t%f\t%f\t%f\n",t,s,e,es,p);
  }
  fclose(fp);
}

/*
void euler(double starts,double invaltime,double endtime){
  double s=starts,t=0,e=1,es=0,p=0,ee;
  ee = e;
  es = dff(s,e);
  s = s - es;
  e = e - es;
  FILE *fp;
  if ((fp = fopen("plot3.txt", "w")) == NULL) {
    printf("file open error!!\n");
  }
  while(1){
    if(endtime <= t){
      break;
    }
    s = s + invaltime*df(s);
    if(s < es){
      es = s;
      e = ee - es;
    }
    p = p + -invaltime*df(s);
    t += invaltime;
    fprintf(fp,"%f\t%f\t%f\t%f\t%f\n",t,s,e,es,p);
  }
  fclose(fp);
}
*/


/*
void runge_kutta(double startx,double invaltime,double endtime){
  double s1,s2,s3,s4,t=0,x=startx;
  FILE *fp;
  if ((fp = fopen("plot3-p.txt", "w")) == NULL) {
    printf("file open error!!\n");
  }
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
    fprintf(fp,"%f\t%f\n",t,x);
  }
  fclose(fp);
}
*/

int main(void){
  double startx=20,invaltime=0.01,endtime=50;
  euler(startx,invaltime,endtime);
  //runge_kutta(startx,invaltime,endtime);
  return 0;
}
