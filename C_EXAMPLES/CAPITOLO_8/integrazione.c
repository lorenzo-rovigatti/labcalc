#include<stdlib.h>
#include<stdio.h>
#include<math.h>

double func(double x)
{
  return 1.0/x;
}
#ifdef KSUM
double kahan_sum(double x, double sum, double* corr)
{
  double tmp, y;
  y = *corr + x;           
  tmp = sum + y;          
  *corr = (sum - tmp) + y; 
  sum = tmp;
  return sum;
} 
#endif
int main(int argc, char *argv[])
{
#ifdef KSUM
  double corr=0.0;
#endif
  double term, sum, x1, h, xmin, xmax;
#ifdef TRAPEZI
  double x2;
#endif
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
  printf("Uso il metodo ");
#if defined(MIDPOINT)
  printf("del punto di mezzo ");
#elif defined(TRAPEZI)
  printf("dei trapezi ");
#else
  printf("dei rettangoli ");
#endif
  printf("con N=%lld intervalli\n", N);
#ifdef KSUM
  printf("Le somme verranno effettuate usando l'algoritmo di Kahan\n");
#endif
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
#ifdef KSUM
      sum= kahan_sum(term, sum, &corr); 
#else 
      sum += term;
#endif
    }
  sum *= h;
  printf("L'integrale di 1/x tra %.1f e %.1f è: %.16f\n", xmin, xmax, sum);
  printf("L'errore è pari a: %.16f\n", fabs(sum-sumex));
}
