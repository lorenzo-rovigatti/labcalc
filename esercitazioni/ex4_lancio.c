#include<stdlib.h>
#include<stdio.h>
#include<time.h>
int main(int argc, char *argv[])
{
  const int nmax=36; 
  int n;

#ifdef USE_RAND
  srand(0);
  n=nmax*((double)rand()/(RAND_MAX+1.0))+1;
#else
  srand48(0);
  n=drand48()*nmax + 1;
#endif
  printf("%2d ",n);
  if (n%2==0)
    {
      printf("E ");
    }
  else
    {
      printf("O ");
    }
  if (n <= 18)
    {
      printf("M\n");
    }
  else 
    {
      printf("P\n");
    }
  return 0;
}
