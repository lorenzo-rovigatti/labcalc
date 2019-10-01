/* non mostrare questo programma ma compilarlo soltanto */
#include <stdio.h>
#include <stdlib.h>
#define N 10000000
#define NM  100
#define ES  50
int errori[NM];

int main(int argc, char **argv) {
  float S = 0., x = 7.;
  unsigned int toterr=0, i, iS = 0, ix = 7, cS, err, sume, dS, pS;
  int first=1;
  for (i = 0; i < NM; i++)
   errori[i] = 0;
  for (i = 0; i < N; i++) 
    {
      pS = (unsigned int) S;
      S += x;
      iS += ix;
      cS = (unsigned int) S;// converto il float S ad un intero
      dS = cS - pS;
      // se il valore convertito a intero è diverso dal valore 
      // esatto allora stampe ed esci
      if (dS != ix)  
        {
          err = dS - ix;
          if (err+ES >= NM)
            {
              printf("err=%d >= NM=%d\n", err, NM);
              printf("aumentare la dimensione dell'array NM!\n");
              exit(1); 
            }
          errori[err+ES]++;
        }
    }

  /* stampa riepilogo errori */
  sume = 0; 
  printf("errore totale (volte x errore) = ");
  for (i = 1; i < NM; i++)
    {
      if (errori[i]!=0)
        {
          if (!first)
            {
              if (i < ES)
                printf(" - ");
              else
                printf(" + ");
            }
          sume += errori[i]*(i-ES);
          printf("%d x %d", errori[i], abs(((int)i)-ES));
          first=0;
        }
    } 
  printf(" = %u\n", sume); 
  printf("\nsomma (volte x differenza) = ");
  first=1;
  for (i = 1; i < NM; i++)
    {
      if (errori[i]!=0)
        {
          if (!first)
            {
              printf(" + ");
            }
          sume += errori[i]*(i-ES);
          printf("%d x %d", errori[i], (((int)i)-ES) + ix);
          first=0;
          toterr += errori[i];
        }
    } 
  printf(" + %u x 7", N - toterr);
  printf(" = %.0f\n\n", S);
  printf("Usando float  : %12.1f x %12.1d = %12.1f\n", x, N, S); 
  printf("Usando interi : %12d x %12d = %12d\n", ix, N, iS);
  printf("Differenza:   : %12d\n", ((unsigned int) S)-iS);
}
