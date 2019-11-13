#include<stdlib.h>
#include<stdio.h>
#include<math.h>
int main(int argc, char** argv)
{
  int i, N, nzeri;
#ifdef PRINT_BEST
  double xbest, xerr;
#endif
  double s,fxL, fxR, xL, xR, dx, xmin=-15.0, xmax=15.0;
  for (N=1; N < 20; N++)
    {
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
#ifdef PRINT_BEST
              xbest=(xL+xR)/2.0;
              xerr=(xR-xL)/2.0;
              printf("Trovato lo zero N. %d: %.15G errore: %.15G\n", xbest, xerr);
#endif
              nzeri += 1.0;
            }
          xL+=dx;
        }
      printf("%d %d\n", N, nzeri);
    }
  return 0;
}
