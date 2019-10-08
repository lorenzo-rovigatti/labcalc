#include <stdlib.h>
#include <stdio.h>
#define N 5
#define M 7
int main()
{
  int i, j;
  int data2d[N][M];
  int data1d[N*M];
  
  // inizializzazione con ciclo
  for (i=0; i < N; i++)
    for (j=0; j < M; j++)
      data2d[i][j] = j; 
  printf("\n data[]=\n");

  // stampo l'arry 2d appena inizializzato
  for (i=0; i < N; i++)
    {
      for (j=0; j < M; j++)
	printf(" %4d", data2d[i][j]);
      printf("\n");
    }
  printf("\n");	

  //inizializzazione con ciclo dell'array 1d equivalente al precendete
  for (i=0; i < N; i++)
    for (j=0; j < M; j++)
      data1d[i*M+j] = j; 
  
  // stampo l'array 1d 
  printf("\n data2[]=\n");
  for (i=0; i < N; i++)
    {
      for (j=0; j < M; j++)
	printf(" %4d", data1d[i*M+j]);
      printf("\n");
    }
  printf("\n");

  return 0;
}
