#include<stdlib.h>
#include<stdio.h>
#include<math.h>
int main(int argc, char** argv)
{
  int i, Np=100;
  double fx, x, dx, sum=0.0, xmin=-15.0, xmax=15.0;
  x=xmin;
  dx = (xmax-xmin)/Np;
  for (i=0; i < Np; i++)
    {
      if (x==0.0)
        fx=1.0;
      else
        fx=sin(x)/x;
      printf("%.7f %.7f\n", x, fx);
      x+=dx;
    }
  return 0;
}
