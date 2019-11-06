#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#define FIXED_SEED 0
int main(int arcg, char**argv)
{
  int seed;
  int i;
  double r;
#if FIXED_SEED==1
  seed = 200;
#else
  seed = time(0); // restituisce il tempo dal 01/01/1970 00:00:00 UTC in secondi
                  // UTC=coordinated universal time 
#endif
  srand48(seed);
  printf("sequenza di 10 numeri casuali double tra 0 (incluso) e 1 (escluso):\n");
  for (i = 0; i < 10; ++i) 
    {
      r=drand48(); 
      printf("Ho generato il numero %18.16f\n", r);
    }
  return 0;
}
