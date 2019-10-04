#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<float.h>
void printBitsnm(size_t const size, void *ptr, int n, int m)
// stampa i bits dall'n-esimo all'm-esimo (estremi inclusi)
// n e m partono da 1
// size indica il numero di byte puntati da ptr
// notare che il segno è il bit più significativo
{
  // size in bytes
  unsigned char *b = (unsigned char*) ptr;
  unsigned char byte;
  int i, j, addsp;
  int c=1;
  if (n==1 && m==size*8)
    addsp=1;
  else
    addsp=0;
  for (i=size-1;i>=0;i--)
    {
      for (j=7;j>=0;j--)
        {
          if ((c < n) || (c > m))
            {
              c++;
              continue;
            }
          byte = (b[i] >> j) & 1;
          printf("%u", byte);
          if (addsp && c==1) 
            printf(" ");
          else if (addsp && c==9)
            printf(" ");
          c++;
        }
    }
}
void printBits(size_t const size, void*ptr)
{
  printBitsnm(size, ptr, 1, size*8);
}
void printBitsEsponente(float* a)
{
  void *ptr;
  ptr = (void*)a;
  printBitsnm(sizeof(float), ptr, 2, 9);
}
void printBitSegno(float *a)
{
  void *ptr;
  ptr = (void*)a;
  printBitsnm(sizeof(float), ptr, 1, 1);
}
void printBitsMantissa(float* a)
{
  void *ptr;
  ptr = (void*)a;
  printBitsnm(sizeof(float), ptr, 10, 32);
}
void printBitsMantissaShifted(float *a, int s)
{
  void *ptr;
  unsigned int *pi;
  pi = (unsigned int*)a;
  *pi = *pi & 0x007FFFFF; // il segno è il bit più significativo
  *pi = *pi | (1 << 23); // imposta il bit meno significativo dell'esponente 
                         // (per poterlo shiftarre nella mantissa)
  *pi = *pi >> s;        // shift a destra pari a s
  // porta un 1 come nono bit e poi shifta di s 
  ptr = (void*) pi;
  printBitsnm(sizeof(float), ptr, 10, 32);
}
unsigned int getexponent(float *ptr)
{
  unsigned int *i, ui;
  i = (unsigned int*)ptr;
  const int N = 127; // bias dell'esponente = 2^(8-1) - 1
  ui = *i << 1; // il bit del segno è il più significativo quindi moltiplicando per 2 (<<1) lo elimino
  // dopo la precendente operazione ho 23+1 bit prima dell'esponente da eliminare 
  ui = ui >> (32-8); // elimino i 24 bit meno significativi dividendo per 2^24 (>> 32-8)
  ui = ui - N;   // l'esponente è rappresentato in eccesso a N, con N=2^(8-1)-1=127 
  return ui; 
}
void printBitsDenormalized(float *b, float *a)
{
  unsigned char ea, eb;
  if (*a < *b)
    {
      printf("[printBitsDenormalized] assumo il secondo argomento maggiore del primo\n");
      exit(1);
    }
  printBitSegno(b); 
  printf(" ");
  printBitsEsponente(a);
  printf(" ");
  // shift la mantissa riportando l'1 che è implicito nella rappresentazione floating point
  // dove ogni numero è assunto del tipo C.XXXXX (dove C=1). Nel numero risultante si assume quindi C=0.
  ea = getexponent(a);
  eb = getexponent(b);
  printBitsMantissaShifted(b,ea-eb);
}
void print_sep(void)
{
  printf("\n=========================================== \n");
}
int main(int argc, char **argv)
{
  float a=22.75, b=4.5, c, d=1.327, e=100000000.0, f=1.0, g;
  int ea, eb, ec;
  printf("Algoritmo di conversione:\n");
  printf("1) convertire il numero prima della virgola in binario e poi la parte frazionaria (moltiplicando per 2)\n");
  printf("22.75 = 10110.11 \n");
  printf("  4.5 =   100.1\n");
  printf("2) spostare la virgola fino ad avere la forma 1.XXX\n\n");
  printf("10110.11 -> 1.01101100000000000000000 x 2^4\n");
  printf("   100.1 -> 1.00100000000000000000000 x 2^2\n");

  print_sep();
  printf("\nEsempio di conversione di 1.327 in binario è:\n\n");
  printBits(4, (void*)&d);
  printf("\n");

  print_sep();
  printf("Esempio di somma di numeri in virgola mobile:\n");

  c=a+b;
  printf("\n%5.2f + %5.2f = %5.2f\n\n", a, b, c);
  printf("%5.2f -> ", a); 
  printBits(4,(void*)&a);
  ea = getexponent(&a);
  eb = getexponent(&b);
  printf(" (0 = +, %d-N=%d dove N=2^7-1=127, mantissa)\n", ea+127, ea);
  printf("%5.2f -> ", b);
  printBits(4,(void*)&b);
  printf(" (0 = +, %d-N=%d dove N=2^7-1=127, mantissa)\n\n", eb+127, eb);

  printf("Rappresentazione in virgola mobile in binario degli addendi (4 byte=32 bit).\n");
  printf("Notare che l'addendo con esponente minore viene portato ad avere lo stesso\n");
  printf("esponente spostando la virgola verso sinistra prima di fare la somma.\n");
  printf("\novvero in binario\n");
  printf("(bit del segno + 8 bit esponente + 23 bit mantissa)\n\n");
  printBits(4,(void*)&a);
  printf(" + \n");
  printBitsDenormalized(&b, &a);
  printf("%s", ea == eb ? "    (C=1)" : "   (C=0)");
  printf("\n----------------------------------\n");
  printBits(4,(void*)&c);
  ec = getexponent(&c);
  printf("   (0 = +, %d-127=%d, mantissa)", ec+127,ec);
  printf("\n");

  print_sep();
  printf("\nesempio di errore di arrotondamento\n");
  g=e+f;
  printf("\n%11.1f + %3.1f = %2.1f\n\n", e, f, g);
  ea = getexponent(&e);
  eb = getexponent(&f);
  printf("%11.1f -> ", e); 
  printBits(4,(void*)&e);
  printf(" (0 = +, %d-N=%d dove N=2^7-1=127, mantissa)\n", ea+127, ea);
  printf("\n%11.1f -> ", f);
  printBits(4,(void*)&f);
  printf(" (0 = +, %d-N=%d dove N=2^7-1=127, mantissa)\n", eb+127, eb);
  printf("\n\n");
  printBits(4,(void*)&e);
  printf(" + \n");
  printBitsDenormalized(&f, &e);
  printf("%s", ea == eb ? "    (C=1)" : "   (C=0)");
  printf("\n----------------------------------\n");
  printBits(4,(void*)&g);
  ec = getexponent(&g);
  printf("   (0 = +, %d-127=%d, mantissa)", ec+127,ec);
  printf("\n");
  return 0;
}
