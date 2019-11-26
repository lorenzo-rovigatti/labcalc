#include <stdio.h>
#define NC 10 

int main(void)
{
  int i,j,dumb, dati[NC][2]; // colonna 0 vendite; colonna 1 ore
  double media[NC];
  FILE *fpr;

  for (i=0; i < NC; i++)
    {
      media[i] = 0.0;
    }

  fpr=fopen("tri1.dat","r");
  for (i=0;i<NC;i++)
    {
      fscanf(fpr,"%i %i %i",&dumb,&dati[i][0],&dati[i][1]);
      media[i]=((double)dati[i][0])/dati[i][1];
    }  
  fclose(fpr);
  // stampo i commessi con i voti
  for (j=0;j<NC;j++)
    {
      printf("commesso n. %3i # Ore %3i # Vendite in euro %5i # Media= %7.2f\n",j+1,dati[j][0],dati[j][1],media[j]);
    }

}
