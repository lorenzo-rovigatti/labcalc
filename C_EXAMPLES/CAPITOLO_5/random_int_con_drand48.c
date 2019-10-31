#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#define FIXED_SEED 0
#define N 30
#define MODO 1
int main(int arcg, char**argv)
{
  unsigned int seed;
  int i, ir;
#if FIXED_SEED==1
  seed = 200;
#else
  seed = time(0); // restituisce il tempo dal 01/01/1970 00:00:00 UTC in secondi
                  // UTC=coordinated universal time 
#endif
  srand48(seed);
  printf("sequenza di 10 numeri interi casuali tra 1 e %d:\n", N);
  for (i = 0; i < 10; ++i) 
    {
      ir=drand48() * N + 1; 
      printf("Ho generato il numero %10d\n", ir);
    }
  return 0;
}
