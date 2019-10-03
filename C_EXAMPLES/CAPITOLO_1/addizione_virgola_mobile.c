#include<stdlib.h>
#include<stdio.h>
void printBits(size_t const size, void *ptr)
{
  // size in bytes
  unsigned char *b = (unsigned char*) ptr;
  unsigned char byte;
  int i, j;
  int c=1;
  for (i=size-1;i>=0;i--)
    {
      for (j=7;j>=0;j--)
        {
          byte = (b[i] >> j) & 1;
          printf("%u", byte);
          if (c==1) 
            printf(" ");
          else if (c==9)
            printf(" ");
          c++;
        }
    }
}
int main(int argc, char **argv)
{
  float a=22.75, b=4.5, c, d=1.327;
  
  printf("Algoritmo di conversione:\n");
  printf("1) convertire il numero prima della virgola in binario e poi la parte frazionaria (moltiplicando per 2)\n");
  printf("22.75 = 10110.11 \n");
  printf("  4.5 =   100.1\n");
  printf("2) spostare la virgola fino ad avere la forma 1.XXX\n\n");
  printf("10110.11 -> 1.01101100000000000000000 x 2^4\n");
  printf("   100.1 -> 1.00100000000000000000000 x 2^2\n");
  printf("Esempio di conversione di 1.327 in binario è:\n\n");
  printBits(4, (void*)&d);
  printf("\n\n");

  printf("-----------------------------------------------\n");
  printf("Esempio di somma di numeri in virgola mobile:\n");

  c=a+b;
  printf("\n%f + %f = %f\n\n", a, b, c);
  
  printf("Rappresentazione in virgola mobile degli addendi (4 byte=32 bit)\n\n");
  printf("\novvero in binario\n");
  printf("(bit del segno + 8 bit esponente + 23 bit mantissa)\n\n");
  printBits(4,(void*)&a);
  printf(" + (0 = +, 131-N=4 dove N=2^7-1=127, mantissa)\n");
  printBits(4,(void*)&b);
  printf("   (0 = +, 129-N=2 dove N=2^7-1=127, mantissa)");
  printf("\n----------------------------------\n");
  printBits(4,(void*)&c);
  printf("   (0 = +, 131-127=4, mantissa)");
  printf("\n");
  return 0;
}
