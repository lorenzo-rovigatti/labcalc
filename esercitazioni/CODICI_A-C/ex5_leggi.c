#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define NC 10 

int main()
{
  int i,j,dumb,voto[NC],dati[NC][2];
  double media[NC];
  FILE *fpr;

  fprintf(stdout,"********************************************************************************\n");
  fprintf(stdout,"QUESTO PROGRAMMA PRENDE IN INPUT I DATI DI VENDITA DEL PRIMO TRIMESTRE \n");
  fprintf(stdout,"E LI STAMPA SU SCHERMO ASSIEME ALLA MEDIA INCASSI\n");
  fprintf(stdout,"********************************************************************************\n");
  fprintf(stdout,"\n");

  /*********************INIZIALIZZAZIONE DI ARRAY E MATRICI **********************************/
  
  for (i=0; i < NC; i++)
    {
      media[i] = 0.0;
      dati[0][i] =0.0;
      dati[1][i] =0.0;
    }

  /*******************************************************************************************/
  /*********************************APERTURA E LETTURA FILE INPUT*****************************/
  
  fpr=fopen("trimestre.dat","r");
  if(fpr==NULL){
    fprintf(stderr,"Problemi nell'apertura del file trimestre.dat. Exiting...\n");
    exit(1);
  }
  for (i=0;i<NC;i++)
    {
      fscanf(fpr,"%i %i %i",&dumb,&dati[i][0],&dati[i][1]);//in dati[i][0] metto gli incassi in dati[i][1] le ore
      media[i]=((double)dati[i][0])/dati[i][1];        
    }  
  fclose(fpr);
  
/*******************************************************************************************/
 /************************************STAMPA*************************************************/
  fprintf(stdout,"I dati vendite sono per ciascun commmesso:\n");
  fprintf(stdout,"\t\tINCASSI\t ORE LAVORATE\t MEDIA INCASSI\n");
  
  for (i=0;i<NC;i++){
    fprintf(stdout,"COMMESSO:%2i\t%2i\t\t%2i\t%12.5lf\n",i+1,dati[i][0],dati[i][1],media[i]);
  }
}
