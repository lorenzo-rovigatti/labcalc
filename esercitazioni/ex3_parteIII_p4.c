#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#ifndef NINT
#define NINT 100
#endif
int main(int argc, char** argv)
{
  int i, N=NINT, nzeri;
  double xbest, xerr;
  double s,fxL, fxR, xL, xR, dx, xmin=-15.0, xmax=15.0;
  xL=xmin;
  dx = (xmax-xmin)/N;
  nzeri=0;
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
      if (s <= 0)
        {
          nzeri += 1;
          xbest=(xL+xR)/2.0;
          xerr=(xR-xL)/2.0;
          printf(">>> trovato lo zero N. %d: %.15G errore: %.15G\n", nzeri, xbest, xerr);
        }
      xL+=dx;
    }
  return 0;
}
