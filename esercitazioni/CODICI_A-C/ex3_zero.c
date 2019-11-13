#include<stdio.h>
#include<math.h>

#define THRESHOLD 1.0E-12

int main(void)
{
  int i,j, Np=100,N, nzeri=0;
  double xbest, xerr, s,fxL, fxR, xL, xR, dx, xmin=-15.0, xmax=15.0;
  xL=xmin;
  N=Np-1;
  dx = (xmax-xmin)/N;
  for (i=0; i < N; i++)
    {
      xR = xL + dx;
      fprintf(stderr,"xL--> %lf xR-->%lf\n",xL,xR);
      if (fabs(xL)<THRESHOLD)
        fxL=1.0;
      else
        fxL=sin(xL)/xL;
      if (fabs(xR)<THRESHOLD)
	fxR=1.0;
      else
	fxR=sin(xR)/xR;
      s = fxL * fxR;
      
      if (s < 0)
        {
	  xbest=(xL+xR)/2.0;
	  xerr=(xR-xL)/2.0;
          printf("Trovato uno zero x=%12.7f +- %9.7f\n",xbest, xerr);
          nzeri += 1.0;
        }
      xL+=dx;
    }
  printf("Numero zeri trovati=%d\n", nzeri);
  return 0;
  }

