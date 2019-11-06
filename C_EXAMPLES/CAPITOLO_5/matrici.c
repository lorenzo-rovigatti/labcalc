#include<stdio.h>
int main(void)
{
  int k1, k2,k3;
  double M[3][3], A[3][3]={{1,2,3},{3,1,-2},{3,4,5}}, B[3][3]={{1,3,-1},{-2,0,4},{3,-3,6}};
  // effettua la moltiplicazione M=A*B
  // con M, A, B matrici 3x3 
  for (k1 = 0; k1 < 3; k1++)
    {
      if (k1 == 1)
        printf("A = |");
      else
        printf("    |");
      //printf("{");
      for (k2 = 0; k2 < 3; k2++)
	{
	  printf("%4.2G", A[k1][k2]);
	  if (k2 < 2)
	    printf(" ");
	}
      printf(" |");
      if (k1 < 2)
	printf("\n");
    }
  printf("\n\n");
  for (k1 = 0; k1 < 3; k1++)
    {
      if (k1 == 1)
        printf("B = |");
      else
        printf("    |");
      //printf("{");
      for (k2 = 0; k2 < 3; k2++)
	{
	  printf("%4.2G", B[k1][k2]);
	  if (k2 < 2)
	    printf(" ");
	}
      printf(" |");
      if (k1 < 2)
	printf("\n");
    }
  printf("\n\n");
  
  for (k1 = 0; k1 < 3; k1++)
    {
      for (k2 = 0; k2 < 3; k2++)
        {
          M[k1][k2] = 0.0;
          for (k3 = 0; k3 < 3; k3++)
            M[k1][k2] += A[k1][k3]*B[k3][k2];
        }
    }
  for (k1 = 0; k1 < 3; k1++)
    {
      if (k1 == 1)
        printf("M = |");
      else
        printf("    |");
      //printf("{");
      for (k2 = 0; k2 < 3; k2++)
	{
	  printf("%4.2G", M[k1][k2]);
	  if (k2 < 2)
	    printf(" ");
	}
      printf(" |");
      if (k1 < 2)
	printf("\n");
    }
  printf("\n");
  
}
