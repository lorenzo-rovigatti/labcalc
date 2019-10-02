#include <stdio.h>

#define N 10000000

int main(int argc, char** argv) {
  float sum=0., corr=0., x = 7.;
  int i;
  /* se S = x_1 + x_2 + ... x_n
   * si può dimostrare che l'errore En di questo algoritmo è:
   * 
   * En <= (2*eps + O(n*eps^2))*(abs(x_1) + .... abs(x_n))
   * 
   * dove eps = 2^(-p) essendo p il numero di bit usati per la mantissa
   * nella rappresentazione floating point.
   * */
  for(i=0; i<N; i++) {
    float tmp, y;
    y = corr + x;           // Se corr=0, y = x = 7 nel caso specifico.
    tmp = sum + y;          // Qui può esserci un errore di arrotondamento ad es. 16777222.0 + 7.0 = 167772228.0
    corr = (sum - tmp) + y; // in tal caso corr = -6 + 7 = 1    
    
    // In generale, se c'è un errore di arrotodamento sum - tmp (dove sum = valore attuale,
    // tmp = nuovo valore della somma) sarà diverso dall'incremento y. 
    // La differenza è la correzione di cui si terrà conto alla successiva
    // iterazione
    
    sum = tmp; // assegna il nuovo valore a sum
  }
  sum += corr;
  printf("Using floats  : %.0f x %d = %.0f\n", x, N, sum);
  return 0;
}
