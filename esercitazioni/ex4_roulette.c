#include<stdlib.h>
#include<stdio.h>
#include<time.h>
int main(int argc, char *argv[])
{
  const int nmax=36, N=1000000000; 
  int nocc[36];
  int i, n, nE=0, nM=0;
#ifdef USE_RAND
  srand(0);
#else
  srand48(0);
#endif
  for (int i = 0; i < 36; i++) {
    nocc[i]=0;
  }
  for (i = 0; i < N; ++i) {
    // numero casuale tra 1 e nmax
#ifdef USE_RAND
    n=nmax*((double)rand()/(RAND_MAX+1.0))+1; 
#else
    n=drand48()*nmax+1;
#endif
    nocc[n-1] += 1;
    if (n%2==0)
      {
        nE++;
      }
    if (n <= 18)
      {
        nM++;
      }
  } 
#ifdef SHOW_FREQ_EMOP
  printf("frequenza E=%.7f; frequenza M=%.7f\n", 
         ((double)nE)/N, ((double)nM)/N);
  printf("frequenza O=%.7f; frequenza P=%.7f\n", 
         ((double)(N-nE))/N, ((double)(N-nM))/N);
#else
  for (int i = 0; i < 36; i++) {
    printf("%d %.7f\n", i+1, ((double)nocc[i])/N);
#endif
  }
  return 0;
}
