#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<time.h>


/************************************************************/
/************************MAIN*******************************/
int main()
{
  const int nmax=36; 
  int n,i;

  srand48(time(NULL));

  fprintf(stdout,"\n");
  fprintf(stdout,"****************************************************************\n");
  fprintf(stdout,"QUESTO PROGRAMMA ESTRAE UN NUMERO RANDOM TRA [1,36] E SCRIVE \n");
  fprintf(stdout,"SU SCHERMO SE IL NUMERO E' PARI (E) , DISPARI (O), MINORE DI 18 \n");
  fprintf(stdout,"o MAGGIORE DI 18 (P) \n");
  fprintf(stdout,"****************************************************************\n");
  fprintf(stdout,"\n");
  
    
    n=(int)(drand48()*nmax) + 1; //drand48() -->(0,1]
    printf("%2i ",n);
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
/************************************************************/
