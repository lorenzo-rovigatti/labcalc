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
  srand(seed);
#ifdef MODO==1
  printf("sequenza di 10 numeri interi casuali tra 1 e %d:\n", N);
#else
  printf("sequenza di 10 numeri interi casuali tra 0 e %d:\n", N);
#endif
  for (i = 0; i < 10; ++i) 
    {
#if MODO==1
      ir=rand() % N + 1; 
#else
      ir = ((double) rand() /RAND_MAX) * N;
#endif
      printf("Ho generato il numero %10d\n", ir);
    }
  return 0;
}
