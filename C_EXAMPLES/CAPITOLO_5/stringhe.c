#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#define NUMMSG 6
#define MAXCHARS 128
int main(int arcg, char**argv)
{
  // immetti una stringa
  int fine, res, c, wrongchar=0;
  char testo0[] = "Benvenuto!";
  char testo[NUMMSG][MAXCHARS] = {
    "Immetti una stringa non vuota composta da sole lettere o spazi", 
    "Problema nella conversione",
    "ERRORE: La stringa non è composta di solo lettere minuscole, maiuscole o spazi!",
    "Immissione corretta, hai immesso:",
    {'c','i','a','o','!','\0'}, // una stringa è un array di char che termina con '\0'
    {99,105,97,111,33,'\0'}     // ...un char è un intero con segno a 8 bit
  };
  
  char a[256];
  fine=0;
  printf("%s\n", testo0);
  while (!fine)
    {
      printf("%s\n", testo[0]);
      fine=1;
      res=scanf("%255[^\n]", a); // massimo 255 caratteri, il 256-esimo carattere è per il null di fine stringa('\0')
        
      // e se avessimo usato: 
      // res=scanf("%s",a); // ? 
      // se il valore restituito da scanf è minore di 1 vuol dire che non è 
      // stata acquisita la stringa
      if (res < 1)
        {
          printf("%s\n", testo[1]);
          fine=0;
        }
      // controlla che i caratteri immessi siano validi, cioè che 
      // siano lettere maiuscole o minuscole o spazi
      wrongchar = 0;
      for (int i = 0; a[i]!=0 && wrongchar==0 && res == 1; ++i) 
        {
          if (!(a[i] == 32 || (a[i] >= 97 && a[i] <= 122) || 
              (a[i] >= 65 && a[i] <= 90)))
            {
              wrongchar=1;
              printf("%s\n", testo[2]);
              fine=0;
              break;
            }
        }
      // svuota il buffer di tutti i caratteri e termina quando incontra un newline ('\n')
      // se non si facesse questo resterebbe uno '\n', la conversione nella scanf non avrebbe
      // successo e si avrebbe un ciclo infinito.  
      while ((c=getchar())!='\n'); 
      // e se tolgo questa riga?
    }
  printf("%s %s\n%s, %s\n", testo[3], a, testo[4], testo[5]); 
}
