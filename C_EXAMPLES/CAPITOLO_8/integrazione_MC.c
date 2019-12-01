#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<time.h>
double func(double x)
{
  return 1.0/x;
}
int main(int argc, char *argv[])
{
  double sum, x, xmin, xmax;
  double sumex;
  long long int N, i;
  xmin=1.0;
  xmax=10.0;
  if (argc > 1)
    xmin=atof(argv[1]);
  if (argc > 2)
    xmax=atof(argv[2]);
  if (argc > 3)
    N=atoll(argv[3]);
  else
    N=pow(2,26);
  sumex=log(xmax/xmin);
  printf("Uso il metodo Monte Carlo ");
  printf("generando N=%lld punti casuali\n", N);
  sum=0.0;
  srand48(time(NULL));
  for (i=0; i < N; i++)
    {
      x=xmin+drand48()*(xmax-xmin);
      sum+=func(x);
    }
  sum *= (xmax-xmin)/N;
  printf("L'integrale di 1/x tra %.1f e %.1f è: %.16f\n", xmin, xmax, sum);
  printf("L'errore è pari a: %.16f\n", fabs(sum-sumex));
}
