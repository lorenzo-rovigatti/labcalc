#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#define PRINT_MESH
int main(int argc, char** argv)
{
  int i, N=100, nzeri=0;
  double xbest, xerr, s,fxL, fxR, xL, xR, dx, xmin=-15.0, xmax=15.0;
  xL=xmin;
  dx = (xmax-xmin)/N;
  for (i=0; i < N; i++)
    {
      xR = xL + dx;
      if (xL==0.0)
        fxL=1.0;
      else
        fxL=sin(xL)/xL;
      if (xR==0.0)
        fxR=1.0;
      else
        fxR=sin(xR)/xR;
      s = fxL * fxR;
      xbest=(xL+xR)/2.0;
      xerr=(xR-xL)/2.0;
#ifdef PRINT_MESH
      printf("%f 0.0\n", xR);
#endif
      if (s <= 0)
        {
#ifndef PRINT_MESH
          printf("Trovato uno zero x=%12.7f +- %9.7f\n", (xL+xR)/2.0, xerr);
#endif
          nzeri += 1.0;
        }
      xL+=dx;
    }
#ifndef PRINT_MESH
  printf("Numero zeri trovati=%d\n", nzeri);
#endif
  return 0;
}
