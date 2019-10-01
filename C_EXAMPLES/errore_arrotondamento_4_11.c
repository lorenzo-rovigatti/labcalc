#include <stdio.h>
/* compilare con -D FORMOUT per discutere formati di output */
#define N 10000000

int main(int argc, char **argv) {
  float S = 0., x = 7.;
  unsigned int i, iS = 0, ix = 7;
  for (i = 0; i < N; i++) {
    S += x;
    iS += ix;
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
  printf("formato float:       %%12.1d x       %%12.1d =       %%12.1d\n"); // %% stampa un % 
  printf("formato interi:        %%12d x       %%12d   =       %%12d\n");
  return 0;
#endif
}
