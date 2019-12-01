#include<stdlib.h>
#include<stdio.h>
#include<math.h>

double func(double x)
{
  return 1.0/x;
}
double kahan_sum(double x, double sum, double* corr)
{
  double tmp, y;
  y = *corr + x;           
  tmp = sum + y;          
  *corr = (sum - tmp) + y; 
  sum = tmp;
  return sum;
} 
int main(int argc, char *argv[])
{
#ifdef KAHAN_SUM
  double corr=0.0;
#endif
  double term, sum, x1, h, xmin, xmax;
#ifdef TRAPEZI
  double x2;
#endif
  double sumex = log(10.0);
  int N, i;
  xmin=1.0;
  xmax=10.0;

  if (argc > 1)
    N=atoi(argv[1]);
  else
    N=pow(2,16);
  printf("Uso N=%d intervalli\n", N);
  sum=0.0;
  h = (xmax-xmin)/N;
  for (i=0; i < N; i++)
    {
#if defined(MIDPOINT)
      x1 = h*(i+0.5)+xmin;
      term = func(x1);
#elif defined(TRAPEZI)
      x1 = h*i+xmin;
      x2 = h*(i+1)+xmin;
      term = 0.5*(func(x1)+func(x2));
#else
      x1 = h*i+xmin;
      term = func(x1);
#endif
#ifdef KAHAN_SUM
      sum=kahan_sum(term, sum, &corr); 
#else 
      sum+=term;
#endif
    }
  sum *= h;
  
  printf("L'integrale di 1/x tra 1 e 10 è: %.16f\n", sum);
  printf("L'errore è pari a: %.16f\n", fabs(sum-sumex));
}
