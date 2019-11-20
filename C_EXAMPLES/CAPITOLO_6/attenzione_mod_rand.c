#include<stdlib.h>
#include<stdio.h>
#include<time.h>
int main(int argc, char *argv[])
{
  unsigned int nmax=RAND_MAX*2.0/3.0, N=100000000; 
  int i, nE=0, nM=0;
  unsigned int n; 
  int nocc[2];
  srand(0);
  for (int i = 0; i < 2; i++) {
    nocc[i]=0;
  }
  printf("Genero numero casuali tra 1 e %u\n", nmax); 
  printf("e verifico che le probabilità di ottenere\n");
  printf("un numero minore o maggiore di %u/2=%u siano uguali\n", 
         nmax, nmax/2);
  for (i = 0; i < N; ++i) {
#ifdef NO_USE_MOD
    n=nmax*((double)rand()/(RAND_MAX+1.0))+1; 
#else
    n=rand()%nmax + 1;
#endif
    if (n <= nmax/2.0)
      nocc[0] += 1;
    else 
      nocc[1] += 1;
    if (n%2==0)
      {
        nE++;
      }
    if (n <= 18)
      {
        nM++;
      }
  } 
  for (int i = 0; i < 2; i++) {
    printf("%d %.16G\n", i+1, ((double)nocc[i])/N);
  }
  return 0;
}
