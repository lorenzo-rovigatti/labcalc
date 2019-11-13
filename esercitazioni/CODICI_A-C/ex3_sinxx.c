//#include<stdlib.h>
#include<stdio.h>
#include<math.h>

#define THRESHOLD 1.0E-12

int main(void)
{
  int i, Np=6;
  double fx, x, dx, sum=0.0, xmin=-15.0, xmax=15.0;
  x=xmin;
  fprintf(stderr,"0/0=%.15lf\n", sin(0.0)/0.0);
  fprintf(stderr,"1/0=%.15lf\n", 1.0/0.0);
  dx = (xmax-xmin)/(Np-1);// poiché ho 3 punti e due intervalli
  for (i=0; i < Np; i++)
    {
      if (fabs(x)<THRESHOLD)
        fx=1.0;
      else
        fx=sin(x)/x;
      printf("%.7lf %.7lf\n", x, fx);
      x+=dx;
    }
  return 0;
}
