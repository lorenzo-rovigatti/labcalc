#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#define NMAX 36
#define N 10000000


/************************************************************/
/************************MAIN*******************************/
int main()
{
 
  int nocc[36];
  int i, n, nE=0, nM=0;
  srand(384274384);

   fprintf(stdout,"\n");
  fprintf(stdout,"**********************************************************************\n");
  fprintf(stdout,"QUESTO PROGRAMMA ESTRAE N NUMERI RANDOM TRA [1,36] E STAMPA\n");
  fprintf(stdout,"SU SCHERMO LA FREQUENZA CON CUI E' USCITO UN NUMERO PARI (E),\n");
  fprintf(stdout,"DISPARI (O),MINORE DI 18 (M) o MAGGIORE DI 18 (P).\n");
  fprintf(stdout,"STAMPA INOTRE LE OCCORRENZE E LE FREQUENZE DI TUTTI I NUMERI ESTRATTI\n");
  fprintf(stdout,"***********************************************************************\n");
  fprintf(stdout,"\n");

  for (i = 0; i < 36; i++) {
    nocc[i]=0;
  }
  for (i = 0; i < N; ++i) {
    n=(int)(drand48()*NMAX)+ 1;
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
  //-----PUNTO 1
  fprintf(stderr,"frequenza E=%.5lf; frequenza M=%.5lf\n", 
         ((double)nE)/N, ((double)nM)/N);
  fprintf(stderr,"frequenza O=%.5lf; frequenza P=%.5lf\n", 
         ((double)(N-nE))/N, ((double)(N-nM))/N);
  //-----PUNTO 2 e 3
  for (int i = 0; i < 36; i++) {
    printf("%2i %8i %9.7f\n", i+1, nocc[i],((double)nocc[i])/N);//numero occorrenza frequenza
  }
  return 0;
}
