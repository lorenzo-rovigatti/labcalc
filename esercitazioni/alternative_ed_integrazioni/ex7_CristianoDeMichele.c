#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define NMAX 20

// dichiarazioni di funzioni
void inserimento(char *msg, char *fmt, void *v);
int singolo_getto(void);
void morra(void);

int storico[NMAX][2];
/************************MAIN*******************************/
int main(void)
{
  int punteggi[2], s,i,n,fine, Ngetti;
  FILE *f;
  /* inzializzazione sequenza di numeri pseudo-casuali */
  srand48(time(NULL));

  //********** STAMPA MESSAGGIO INIZIALE E LETTURA DATI ***********
  printf("Simulazione del gioco della morra cinese (giocatore A vs giocatore B)\n");
  do
    {
      inserimento("Inserisci il numero di getti (massimo n. consentito e' 20): ", "%i", &Ngetti);
      if(Ngetti>0 && Ngetti<=NMAX)
        {
          fine =1;
        }
      else
        {
          fine = 0;
          printf("[ERRORE] Il n. di getti deve essere positivo e minore o uguale a %i\n",NMAX);
        }
    }
  while(!fine);

  //************** SIMULAZIONE DELLA MORRA CINESE ***************  
  for (i=0; i < Ngetti; i++)
    {
      for (n = 0; n < 2; n++) 
        {
          storico[i][n] = 0;
        }
    }
  punteggi[0]=punteggi[1]=0;

  for (i=0; i < Ngetti; i++)
    {
      if ((s=singolo_getto()) >= 0)
        (punteggi[s])++;
      storico[i][0] = punteggi[0];
      storico[i][1] = punteggi[1];
      printf("Getto #%d punteggio di A:%d...punteggio di B:%d\n", i, punteggi[0], punteggi[1]);
    }


  //**************** STAMPA PUNTEGGIO SU FILE *******************
  printf("A ha totalizzato %d punti\n", punteggi[0]);
  printf("B ha totalizzato %d punti\n", punteggi[1]);
  if (punteggi[0] > punteggi[1])
    printf("Ha vinto il giocatore A\n");
  else if (punteggi[0] < punteggi[1])
    printf("Ha vinto il giocatore B\n");
  else
    printf("E' finita in parità\n");
  f=fopen("punteggio.dat","w"); 
  for (i=0; i < Ngetti; i++)
    {
      fprintf(f,"%d %d %d\n", i, storico[i][0], storico[i][1]);
    }
  fclose(f);
  return 0;
}

/* 1 = CARTA; 2 = SASSO; 3 = FORBICI */ 
int genera_segno(void)
{
  return drand48()*3+1;
}
int singolo_getto(void)
{
  char segni[3]={'C','S','F'};
  int segno0, segno1, vincitore;
  segno0 = genera_segno();
  segno1 = genera_segno();
  printf("Giocatore A: %c Giocatore B: %c\n", segni[segno0-1], segni[segno1-1]);
  if (segno0==1 && segno1==2)      // carta vince su sasso
    vincitore=0;
  else if (segno0==2 && segno1==1)
    vincitore=1;
  else if (segno0==3 && segno1==1) // forbici vincono su carta
    vincitore=0;
  else if (segno0==1 && segno1==3)
    vincitore=1;
  else if (segno0==2 && segno1==3)  //sasso vince su forbici
    vincitore=0;
  else if (segno0==3 && segno1==2)
    vincitore=1;
  else 
    vincitore=-1; // pari
  return vincitore;
}
void inserimento(char *msg, char *fmt, void *v)
{
  int fine, res, c;
  fine=0;
  while (!fine)
    {
      printf("%s", msg);
      fine=1;
      res=scanf(fmt, v);
      if (ferror(stdin)||feof(stdin))
        {
          // qui ci arriva se si preme CTRL-D = EOF
          printf("\n");
          clearerr(stdin);
          fine=0;
          continue;
        }
          
      if (res < 1)
        {
          printf("Problema nella conversione\n");
          fine=0;
        }
      while ((c=getchar())!='\n'); // svuota il buffer di tutti i caratteri e termina con '\n'=newline
    }
}
