#include <stdio.h>
#include <stdlib.h>
/* compilare con -D FORMOUT per discutere formati di output */
/* compilare con -D LOCERR per mostrare la prima occorrenza dell'errore */
#define N 10000000
int main(int argc, char **argv) {
  float S = 0., x = 7.;
  unsigned int i, iS = 0, ix = 7;
#ifdef LOCERR
  unsigned int cS, pS;
#endif
  for (i = 0; i < N; i++) 
    {
      S += x;
      iS += ix;
#ifdef LOCERR
      cS = (unsigned int) S;// converto il float S ad un intero
      // se il valore convertito a intero è diverso dal valore 
      // esatto allora stampe ed esci
      if (cS != iS)  
        {
          pS = iS - ix; // valore si S prima dell'errore di arrotondamento
          printf("i=%u errore S=%.1f è diverso da iS=%u!\n", i, S, iS);
          printf("Il motivo è che in virgola mobile: %.1f + %.1f = %.1f\n", (float) pS , x, (float) pS + x);
          exit(0);
        }
#endif
  }

  /* FORMATTAZIONE: 
   * printf("%m.nf") dove m e n sono interi
   * m = numero caratteri totali incluso il . (eventualmente aggiunge spazi a sinistra)
   * n = numero cifre dopo virgola 
   * */
  printf("Usando float  : %12.1f x %12d = %12.1f\n", x, N, S); 
  printf("Usando interi : %12u x %12d = %12u\n", ix, N, iS);
#ifdef FORMOUT
  printf("                123456789012 x 123456789012 = 123456789012\n"); 
  printf("formato float:       %%12.1f x       %%12d =       %%12.1f\n"); // %% stampa un % 
  printf("formato interi:        %%12u x       %%12d   =       %%12u\n");
  /* per maggiori dettagli dal terminale impartire il comando:
   * man printf
   */
  return 0;
#endif
}
