#include<stdlib.h>
#include<stdio.h>
#include<math.h>

#define NMAX 36

int main(int argc, char *argv[])
{
  int N=20,select=0; 
  double ptot,pocket=0.0, puntata;
  char giocata;
  int c, fine, vinto, res, ngioc;
  int i, n;
  char junk[80];
  srand(0);
  pocket=100.0;
  fine=0;

  /************************************************************************************************************/
  /************************************************************************************************************/

  /**************************PARTE DEL PROGRAMMA CHE LEGGE IL NUMERO DI GIOCATE********************************/

  /************************************************************************************************************/
  /************************************************************************************************************/
  printf("Benvenuti al gioco della roulette.\n");
  
  do{	
    printf("PREMI: \n");
    printf("1- Per giocare 10 mani\n");
    printf("2- Per giocare 20 mani\n");
    printf("3- Per terminare il programma\n");
    scanf("%i", &select);
    fgets(junk,80,stdin);//acchiappa tutti i caratteri extra rimasti nel buffer
    //fputs(junk,stdout);
  }while(select!=1 && select!=2 && select !=3);
  
  if(select==1)
    N=10;
  if(select==2)
    N=20;
  if(select==3){
    printf("programma terminato...\n");
    return(0);
  }
  
  printf("hai deciso di partecipare a %i giocate. Il tuo credito iniziale e' %lf\n",N,pocket);
  
  ptot=0.0;
  /************************************************************************************************************/
  /************************************************************************************************************/
  
  /**************************************CICLO SUL NUMERO DI GIOCATE*******************************************/
  
  /************************************************************************************************************/
  /************************************************************************************************************/
  for (i = 0; i < N; ++i) 
    {
      puntata=-1.0;
      
      /************************************************************************************************************/
      /************************************************************************************************************/
      
      /*******************************PARTE DEL PROGRAMMA CHE LEGGE LA PUNTATA*************************************/
      
      /************************************************************************************************************/
      /************************************************************************************************************/
      
      printf("\nMano N. %i\n", i+1);
      printf("Quanto vuoi puntare (Hai %4.2lf euro)? ", pocket);
      printf("PREMI: \n");
      printf("1- Per puntare 1.0 euro\n");
      printf("2- Per puntare 2.0 euro\n");
      printf("3- Per puntare 5.0 euro\n");
      printf("4- Per puntare 10.0 euro\n");
      printf("5- Per puntare 50.0 euro\n");
      printf("6- Per puntare 100.0 euro\n");
      printf("7- Per 'ALL IN'\n");
      scanf("%i", &select);
      fgets(junk,80,stdin);

      if(select==1)
	puntata=1.0;

      if(select==2)
	puntata=2.0;

      if(select==3)
	puntata=5.0;

      if(select==4)
	puntata=10.0;

      if(select==5)
	puntata=50.0;

      if(select==6)
	puntata=100.0;

      if(select==7)
	puntata=pocket;

      if(puntata>pocket)
	select=0;
      
      if (select < 1 || select > 7){
	do{
	  printf("PUNTATA NON VALIDA!\n");
	  printf("Quanto vuoi puntare (Hai %4.2lf euro)? ", pocket);
	  printf("PREMI: \n");
	  printf("1- Per puntare 1.0 euro\n");
	  printf("2- Per puntare 2.0 euro\n");
	  printf("3- Per puntare 5.0 euro\n");
	  printf("4- Per puntare 10.0 euro\n");
	  printf("5- Per puntare 50.0 euro\n");
	  printf("6- Per puntare 100.0 euro\n");
	  printf("7- Per 'ALL IN'\n");
	  scanf("%i", &select);
	  fgets(junk,80,stdin);
	  
	  if(select==1)
	    puntata=1.0;
	  
	  if(select==2)
	    puntata=2.0;

	  if(select==3)
	    puntata=5.0;
	  
	  if(select==4)
	    puntata=10.0;

	  if(select==5)
	    puntata=50.0;

	  if(select==6)
	    puntata=100.0;

	  if(select==7)
	    puntata=pocket;
	  
	  if(puntata>pocket)
	    select=0;
	}while(select<1 || select > 7);
      }
      
     
      ptot+=puntata;
      pocket -= puntata;//scala il valore della puntata al budget totale
      
      /************************************************************************************************************/
      /************************************************************************************************************/
      
      /****************************PARTE DEL PROGRAMMA CHE LEGGE IL TIPO DI GIOCATA********************************/
      
      /************************************************************************************************************/
      /************************************************************************************************************/
      
      printf("Scegli il tipo di giocata (E/O/M/P): ");
      // il precedente carriage return rimane nel buffer per quello va messo lo spazio
      scanf(" %c", &giocata);
      fgets(junk,80,stdin);
      if(giocata!='E' && giocata !='O' && giocata !='M' && giocata !='P'){
	do{
	  printf("Giocata non valida!\n");
	  printf("Scegli il tipo di giocata (E/O/M/P): ");
	  scanf(" %c", &giocata);
	}while(giocata!='E' && giocata !='O' && giocata !='M' && giocata !='P');
      }
      printf("\n");
      printf("HAI SELEZIONATO %c\n",giocata);
      printf("\n");
      if (giocata=='E')
	{
	  ngioc=0;
	}
      else if (giocata=='O')
	{
	  ngioc=1;
	}
      else if (giocata=='M')
	{
	  ngioc=2;
	}
      else if (giocata=='P')
	{
	  ngioc=3;
	}
      /************************************************************************************************************/
      /************************************************************************************************************/
      
      /****************************ESTRAZIONE DEL NUMERO RANDOM E RISULTATO GIOCATA********************************/
      
      /************************************************************************************************************/
      /************************************************************************************************************/
      
      n=(int)(drand48()*NMAX + 1);
      vinto=0;
      if (n%2==0 && ngioc==0)//se si e' puntato su  'E' (pari) e il numero estratto e' pari
        vinto=1;             //vittoria!
      if (n%2==1 && ngioc==1)//se si e' puntato su  'O' (dispari) e il numero estratto e' pari
        vinto=1;
      if (n <= 18 && ngioc==2)//se si e' puntato su  'M' (<18) e il numero estratto e' tale
        vinto=1;              //vittoria!
      if (n > 18 && ngioc==3)//se si e' puntato su  'P' (>18) e il numero estratto e' tale
        vinto=1;             //vittoria!
      if (vinto)
        {
          pocket+=2.0*puntata;
	  printf("**************************************\n");
	  printf("**************************************\n");
          printf("Il numero uscito e' %i...HAI VINTO!\n",n);
	  printf("\n");
          printf("Hai %4.2lf euro nel portafoglio\n", pocket);
	  printf("**************************************\n");
	  printf("**************************************\n");
        } 
      else
        {
	  printf("***********************************************************\n");
	  printf("***********************************************************\n");
          printf("Il numero uscito e' %i...Peccato, non hai vinto...\n",n);
	  printf("\n");
          printf("Il gioco puo' provocare dipendenza, gioca responsabilmente!\n");
	  printf("***********************************************************\n");
	  printf("***********************************************************\n");
          if (pocket <= 0)
            {
              printf("Hai effettuato N. %d mani\n", i);
              printf("Hai terminato i soldi, il gioco è finito\n");
              exit(0);
            }
        }
    }
  printf("\nHai effettuato N. %d mani\n", i+1);
  printf("Ammontare totale puntate: %4.2f\n", ptot);
  printf("Euro nel portafoglio: %4.2f\n", pocket);
  return 0;
}
