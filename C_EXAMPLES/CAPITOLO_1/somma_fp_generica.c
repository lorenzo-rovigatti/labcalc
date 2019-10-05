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
  *pi = *pi | (1 << 23);  // imposta il bit meno significativo dell'esponente 
                          // (per poterlo shiftare nella mantissa)
  *pi = *pi >> s;         // shift a destra pari a s
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
  // shifta la mantissa riportando l'1 che è implicito nella rappresentazione floating point
  // dove ogni numero è assunto del tipo C.XXXXX (dove C=1). Nel numero risultante si assume quindi C=0.
  ea = getexponent(a);
  eb = getexponent(b);
  printBitsMantissaShifted(b,ea-eb);
}
void print_sep(void)
{
  printf("\n=========================================== \n");
}
void immetti_float(float *a, char *s)
{
  int fine, res, c;
  fine=0;
  while (!fine)
    {
      printf("%s", s);
      fine=1;
      res=scanf("%f", a);
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
int main(int argc, char **argv)
{
  float a, b, c; 
  int ea, eb, ec, fine=0;

  while (!fine)
    {
      immetti_float(&a, "Immetti il primo addendo in virgola mobile:\t");
      immetti_float(&b, "Immetti il secondo addendo in virgola mobile:\t");
      if (a < b)
        {
          printf("Il primo float deve essere maggiore del secondo!\n");
          continue;
        }
      fine=1;
    }
  c=a+b;
  printf("\n%18.16G + %18.16G = %18.16G\n", a, b, c);
  printf("\nRappresentazione binaria degli addendi:\n");
  printf("X      XXXXXXXX           XXXXXXXXXXXXXXXXXXXXXXX\n");
  printf("segno  8 bit esponente    23 bit mantissa\n");
  printf("esponente rappresentato in eccesso a N con N=2^7-1=127\n\n");
  printf("%18.16G -> ", a); 
  printBits(4,(void*)&a);
  ea = getexponent(&a);
  eb = getexponent(&b);
  printf(" (0/1=+/-,%d-N=%d,mantissa)\n", ea+127, ea);
  printf("%18.16G -> ", b);
  printBits(4,(void*)&b);
  printf(" (0/1=+/-,%d-N=%d,mantissa)\n\n", eb+127, eb);

  printf("Notare che l'addendo con esponente minore viene portato ad avere lo stesso\n");
  printf("esponente spostando la virgola verso sinistra prima di fare la somma.\n\n");
  printBits(4,(void*)&a);
  printf(" + \n");
  printBitsDenormalized(&b, &a);
  printf("%s", ea == eb ? "    (C=1)" : "   (C=0)");
  printf("\n----------------------------------\n");
  printBits(4,(void*)&c);
  ec = getexponent(&c);
  printf("   (0/1=+/-,%d-N=%d,mantissa)", ec+127,ec);
  printf("\n");
}
