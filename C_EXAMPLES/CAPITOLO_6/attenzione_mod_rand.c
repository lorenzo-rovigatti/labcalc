#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<time.h>
const unsigned int maxint= RAND_MAX;
int main(int argc, char *argv[])
{
  unsigned int nmax=maxint*2.0/3.0, N=1000000000; 
  int i, nE=0, nM=0;
  unsigned int n; 
  int nocc[2];
  srand(0);
  for (int i = 0; i < 2; i++) {
    nocc[i]=0;
  }
  printf("nmax=%u\n", nmax);
  for (i = 0; i < N; ++i) {
    n=rand()%nmax + 1;
    if (n < nmax/2.0)
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
