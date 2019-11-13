#include<stdlib.h>
#include<stdio.h>
#include<math.h>
int main(int argc, char** argv)
{
  int i, Np=100;// Np qui è il numero di punti a cui calculare la funzione
  double fx, x, dx, xmin=-15.0, xmax=15.0;
  x=xmin;
  if (Np==1)
    dx=0.0;
  else
    dx = (xmax-xmin)/(Np-1);
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
