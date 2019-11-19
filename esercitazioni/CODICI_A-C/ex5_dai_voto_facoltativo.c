#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define NC 10
#define TRIMESTRE 4

int main()
{
  int i,j,TRIM,dumb,voto[NC][TRIMESTRE],dati[NC][8];//le prime 2 colonne di dati sono i dati relativi al primo trim,, le seconde due sono del secondo trimestre ecc...
  double media[NC][TRIMESTRE],sortmedia[NC][2],temp1,temp2;
  FILE *fpr;
  double val;

  fprintf(stdout,"********************************************************************************\n");
  fprintf(stdout,"QUESTO PROGRAMMA PRENDE IN INPUT I DATI DI VENDITA DI TUTTO L'ANNO \n");
  fprintf(stdout,"(ANNO2016.DAT) E DA UN VOTO AI COMMESSI IN BASE ALLA MEDIA ORARIA\n");
  fprintf(stdout,"********************************************************************************\n");
  fprintf(stdout,"\n");

  /*********************INIZIALIZZAZIONE DI ARRAY E MATRICI **********************************/
  for (i=0; i < NC; i++){
    sortmedia[0][i] = sortmedia[1][i] = 0.0;
    for(j=0;j<TRIMESTRE;j++){
      media[i][j] = 0.0;
      voto[i][j] = 0.0;
    }
    for(j=0;j<2*TRIMESTRE;j++)
      dati[i][j]=0;
    
  }

  /*******************************************************************************************/
  /*********************************APERTURA E LETTURA FILE INPUT*****************************/

  fpr=fopen("anno2016.dat","r");
  if(fpr==NULL){
    fprintf(stderr,"Errore nell'apertura del file trimestre.dat.Exiting...\n");
    exit(1);
  }
  for (i=0;i<NC;i++)
    {
      fscanf(fpr,"%i %i %i",&dumb,&dati[i][0],&dati[i][1]);
      fscanf(fpr,"%i %i",&dati[i][2],&dati[i][3]);
      fscanf(fpr,"%i %i",&dati[i][4],&dati[i][5]);
      fscanf(fpr,"%i %i",&dati[i][6],&dati[i][7]);
    }

  fclose(fpr);
  /*******************************************************************************************/
  /**********************ORDINAMENTO DELLE MEDIE ATTRAVERSO IL BUBBLESORT*********************/
  /* Ordino i commessi in ordine di produttivita'  per i 4 trimestri*/


  
  for(TRIM=0;TRIM<TRIMESTRE;TRIM++){//loop sui trimestri
    
    fprintf(stdout,"\n");
    fprintf(stdout,"Sto ordinando le medie del trimestre %i ...\n",TRIM);
    fprintf(stdout,"\n");
   
    
    for (i=0;i<NC;i++){
      media[i][TRIM]=((double)dati[i][2*TRIM])/dati[i][2*TRIM+1];
      //fprintf(stdout,"%i %lf %i %i %i\n",i,media[i],2*TRIM,dati[i][2*TRIM],dati[i][2*TRIM+1]);
      //sortmedia[i][0] contiene l'indice del commesso
      sortmedia[i][0]=(double)(i+1); // voglio che i commessi vadano da 1 a 10 quindi sommo 1
      //sortmedia[i][1] contiene la media per ciascun commesso
      sortmedia[i][1]=media[i][TRIM];
    }
    
    
    /* BUBBLE SORT...
     * dopo ogni ciclo in i ho nella posizione i-esima l'elemento più grande di tutti
     * Il numero di confronti dunque è 1+2+...+N-2 + N-1 = N*(N-1)/2 = O(N^2/2)  */
    
    for (i = 0; i < NC - 1; i++) {// mi fermo a NC-2 poiché j parte da NC - 1 quindi se i=NC-1 il ciclo in j
      // non verrebbe effettuato
      for(j=0; j<(NC-i-1); j++){    //j=NC-1 è l'elemento più in "basso" 0 quello più in "alto"
	// arrivo fino a i, infatti 
	// 1) dopo il primo ciclo in 0 ho sicuramente l'elemento 
	//    più grande quindi è inutile fari confronti con l'elemento in 0
	// 2) dopo il secondo ciclo in 0 e 1 ho i due elementi più grandi 
	//    e quindi è inutile confrontarsi con loro
	if(sortmedia[j][1]>=sortmedia[j+1][1]){
	  temp1=sortmedia[j+1][0];
	  temp2=sortmedia[j+1][1];
	  sortmedia[j+1][0]=sortmedia[j][0];
	  sortmedia[j+1][1]=sortmedia[j][1];
	  sortmedia[j][0]=temp1;
	  sortmedia[j][1]=temp2;
	}
      }
    }
    
    /*******************************************************************************************/
    /************************************ASSEGNAZIONE VOTO *************************************/
    
    for (i=0;i<NC;i++)
      {
	temp1=sortmedia[i][0];//estraggo il n. del commesso
	j=(int)(temp1-1); // i commessi vanno da 1 a 10 quindi devo sottrarre 1
	voto[j][TRIM]=i+1;//assegno un voto i+1 in quanto sortmedia[i][0] e' ordinato dal piu' scarso al piu' bravo
	//printf("%lf %i\n",sortmedia[i][1],voto[(int)sortmedia[i][0]-1]);
      }
  }
  /*******************************************************************************************/
  /************************************STAMPA**********************************************/

    fpr=fopen("media.dat","w");
    
    for (i=0;i<NC;i++){
      fprintf(fpr,"#COMMESSO%i \t",i+1);
    }
    fprintf(fpr,"\n");
    for(TRIM=0;TRIM<TRIMESTRE;TRIM++){//loop sui trimestri  
    for (i=0;i<NC;i++){
      	fprintf(fpr,"%10lf %4i\t",media[i][TRIM],voto[i][TRIM]);
      }
      fprintf(fpr,"\n");
    }
    fclose(fpr);


    
    /*for (i=0;i<NC;i++){
      val=0;
      for(TRIM=0;TRIM<TRIMESTRE;TRIM++){//loop sui trimestri
	val+=voto[i][TRIM];    	
      }
      fprintf(stdout,"%4i %lf\n",i+1,val/(double)TRIMESTRE);
      }*/
    
}
