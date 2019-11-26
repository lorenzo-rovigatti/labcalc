#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define NMAX 20

/************************************************************/
/****************DICHIARAZIONE DI FUNZIONI*******************/
/*tipo nome_funzione (TIPI DEI VALORI IN IN INPUT);*/

void PrintInitMessage(void);
void inserimento(char *message, char *format, void *var);
void Init_punteggio(int vittoria[][NMAX]);
int getto(void);
void morra(int vittoria[][NMAX],int mano);
void Scrivi_punteggio(int vittoria[][NMAX], int n_getti);
char convert_into_string(int value);

/************************************************************/
/************************MAIN*******************************/

int main(void){
  int i,n,check=0;
  int points[2][NMAX];
  srand48(time(NULL));

  //********** STAMPA MESSAGGIO INIZIALE E LETTURA DATI ***********
  PrintInitMessage();
  do{
    inserimento("Inserisci il numero di getti (massimo n. consentito e' 20): ", "%i", &n);
    if(n>0 && n<=NMAX){
      check=1;
    }else{
      fprintf(stderr,"Attenzione! Il n. di getti non puo' essere negativo o maggiore di %i\n",NMAX);
    }
  }while(!check);


  //************** SIMULAZIONE DELLA MORRA CINESE ***************  
  Init_punteggio(points);
    for(i=0;i<n;i++){
      morra(points,i);
    }
  

  //**************** STAMPA PUNTEGGIO SU FILE *******************
  Scrivi_punteggio(points, n);
  

  return(0);
}

/************************************************************/
/**************DEFINIZIONE DI FUNZIONE***********************/
/****************(PROTOTIPI DI FUNZIONI)*********************/

/*tipo nome_funzione (tipo var1, tipo var2,....){
  
  blocco del codice
}*/



void PrintInitMessage(void){
  
  fprintf(stdout,"\n");
  fprintf(stdout,"************************************************************\n");
  fprintf(stdout,"QUESTO PROGRAMMA SIMULA IL GIOCO DELLA MORRA CINESE\n");
  fprintf(stdout,"RICHIEDENDO IN INPUT IL NUMERO DI GETTI DA SIMULARE\n");
  fprintf(stdout,"************************************************************\n");
  fprintf(stdout,"\n");
  fprintf(stdout,"------------------------------------------------------------\n");
  fprintf(stdout,"***************************LEGENDA:*************************\n");
  fprintf(stdout,"C=CARTA\nF=FORBICI\nS=SASSO\n");
  fprintf(stdout,"------------------------------------------------------------\n");
  fprintf(stdout,"\n");
}

//Questa funzione legge un solo dato il cui tipo e' un parametro di
//input della funzione (viene passato attraverso la stringa format) e controlla
//che la lettura sia andata a buon fine e che non ci siano
//cose rimaste nel buffer. Da notare che sto usando un puntatore
//di tipo void perche' a priori non so qual'e' il tipo
//della variabile che devo leggere.
void inserimento(char *message, char *format, void *var){
  int fine, res=0, c;
  fine=0;
  char junk[80];
  //finche' res non restituisce 1
  while (!fine){
    fprintf(stdout,"%s",message);
    fine=1;
    res=fscanf(stdin,format,var);
    
    if(res!=1){
      fprintf(stderr,"Problema nella lettura da schermo\n");
      fine=0;
    }
    if(fgets(junk, 80, stdin) != NULL && (junk[0] !='\n')){//se e' rimasto qualcosa nel buffer che non e' il carattere di ritorno
      
      fprintf(stderr,"c'e' qualcosa che e' rimasto nel buffer: ");
      fprintf(stderr,"%s\n", junk);
      fine=0;
    }
  }
}

void Init_punteggio(int vittoria[][NMAX]){
  int i;
  
  for(i=0;i<NMAX;i++){
    vittoria[0][i]=0;
    vittoria[1][i]=0;
  }
  
}
//funzione che restituisce un n. intero tra [1,3] )
int getto(void){
  return((int)(drand48()*3)+1);
}

//funzione principale della simulazione
void morra(int vittoria[][NMAX],int mano){
  int value_A;
  int value_B;
  int PUNTOA=0,PUNTOB=0;
  int diff=0;
  
  do{
    value_A=getto();
    value_B=getto();
    diff=value_A-value_B;
  }while(!diff);
  
  /*per cercare il vicitore ho pensato alla seguente strategia: assegno a
    CARTA(C)   il n. 1
    FORBICI(F) il n. 2
    SASSO(S)   il n. 3
    (quindi estraggo un numero intero tra 1 e 3)
    Se sottraggo il valore estratto del giocatore B a quello del giocatore A trovo che
    
    A   B   diff      RISULTATO
    ----------------------------------
    C   S   1-3=-2    VITTORIA di A
    C   F   1-2=-1    PERDITA  di A
    S   C   3-1= 2    PERDITA  di A
    S   F   3-1= 1    VITTORIA di A   
    F   C   2-1= 1    VITTORIA di A
    F   S   2-3= -1   PERDITA  di A
    
    quindi significa che ogni volta che diff=-2 o 1 allora ha vinto il giocatore A
    se invece diff=2 o -1 ha vinto il giocatore B
    SE I SEGNI DI A e B SONO UGUALI (es. CARTA-CARTA, FORBICI-FORBICI,SASSO-SASSO)
    si effettua di nuovo un getto senza considerare la condizione di parita' 
  */
  
  if((diff==-2) || (diff==1)){//VITTORIA DI A
    PUNTOA=1;
    PUNTOB=0;
    if(mano>0){
      vittoria[0][mano]=vittoria[0][mano-1]+PUNTOA;
      vittoria[1][mano]=vittoria[1][mano-1]+PUNTOB;
    }else{
      vittoria[0][mano]=PUNTOA;
      vittoria[1][mano]=PUNTOB;
    }
    
  }
  
  if((diff==-1) || (diff==2)){//VITTORIA DI B
    PUNTOA=0;
    PUNTOB=1;
    if(mano>0){
    vittoria[0][mano]=vittoria[0][mano-1]+PUNTOA;
    vittoria[1][mano]=vittoria[1][mano-1]+PUNTOB;
    }else{
      vittoria[0][mano]=PUNTOA;
      vittoria[1][mano]=PUNTOB;
    }
  }
  //volendo posso farmi stampare i risultati di ogni getto (si puo' commentare questa parte)
  fprintf(stdout,"GETTO N. %i\tSEGNI %c %c\tPUNTI %i %i\tPUNTEGGIO PARZIALE %i %i\n",mano,convert_into_string(value_A),convert_into_string(value_B),PUNTOA,PUNTOB,vittoria[0][mano],vittoria[1][mano]);
}

/*stampa la serie temporale dei punteggi ottenuti in un file*/
void Scrivi_punteggio(int vittoria[][NMAX], int n_getti){
  FILE *fp;
  int i;
  int TotalA=vittoria[0][n_getti-1],TotalB=vittoria[1][n_getti-1];
  fp=fopen("punteggio.dat","w");
  
  for(i=0;i<n_getti;i++){
    fprintf(fp,"%i %i %i\n",i+1,vittoria[0][i],vittoria[1][i]);    
  }
  fclose(fp);


  
  if(TotalA>TotalB){
    fprintf(stdout,"\n");
    fprintf(stdout,"******************************************************************\n");
    fprintf(stdout,"IL VINCITORE DELLA PARTIRA E' IL GIOCATORE A con %i VITTORIE SU %i\n",TotalA,n_getti);
    fprintf(stdout,"******************************************************************\n");
    fprintf(stdout,"\n");
  }else{
   if(TotalA==TotalB){
     fprintf(stdout,"\n");
     fprintf(stdout,"***********************************************************************\n");
     fprintf(stdout,"I DUE GIOCATORI HANNO OTTENUTO LO STESSO PUNTEGGIO DI %i VITTORIE su %i\n",TotalA,n_getti);
     fprintf(stdout,"**********************************************************************\n");
    fprintf(stdout,"\n");
   }else{
     fprintf(stdout,"\n");
     fprintf(stdout,"******************************************************************\n");
     fprintf(stdout,"IL VINCITORE DELLA PARTIRA E' IL GIOCATORE B con %i VITTORIE SU %i\n",TotalB,n_getti);
     fprintf(stdout,"******************************************************************\n");
     fprintf(stdout,"\n");
   }
  }
  fprintf(stdout,"La serie temporale dei punteggi e' stata scritta nel file punteggio.dat\n");
}

/*nel caso volessi stampare i risultati di ogni getto (non solo il punteggio
ma anche i simboli estratti dai due giocatori) uso questa funzione
per convertire il numero estratto in maniera casuale in un carattere che indica

C= CARTA
F=FORBICI
S=SASSO

*/
char convert_into_string(int value){
  char sign;
  
  if(value==1)
    sign='C';
  
  if(value==2)
    sign='F';
  
  
  if(value==3)
   sign='S';

  return(sign);
}
