#include <stdio.h>
#include <stdlib.h>
/* compilare con -D FORMOUT per discutere formati di output */
/* compilare con -D LOCERR per mostrare la prima occorrenza dell'errore */
#define N 10000000

int main(int argc, char **argv) {
  float S = 0., x = 7.;
  unsigned int i, iS = 0, ix = 7;


  for (i = 0; i < N; i++) {
    S += x;
   iS += ix;
#ifdef LOCERR
   if (S != iS)
     {
       printf("i=%d errore S=%.1f è diverso da iS=%d!\n", i, S, iS);
       printf("%.1f + %.1f = %.1f\n", (float)(iS-x), x, (float)(iS-x) + x);
       printf("16777222.0+7.0=%.1f\n", 16777222.0+7.0);
       exit(0);
     }
#endif
  }

  /* FORMATTAZIONE: 
   * printf("%m.nf") dove m e n sono interi
   * m = numero caratteri totali incluso il . (eventualmente aggiunge spazi a sinistra)
   * n = numero cifre dopo virgola 
   * */
  printf("Usando float  : %12.1f x %12.1d = %12.1f\n", x, N, S); 
  printf("Usando interi : %12d x %12d = %12d\n", ix, N, iS);
#ifdef FORMOUT
  printf("                123456789012 x 123456789012 = 123456789012\n"); 
  printf("formato float:       %%12.1f x       %%12.1d =       %%12.1f\n"); // %% stampa un % 
  printf("formato interi:        %%12d x       %%12d   =       %%12d\n");
  /* per maggiori dettagli dal terminale impartire il comando:
   * man printf
   */
  return 0;
#endif
}
