#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<float.h>
#include<termios.h>
void init_press_key()
{
  struct termios info;
  tcgetattr(0, &info);          /* get current terminal attirbutes; 0 is the file descriptor for stdin */
  info.c_lflag &= ~ICANON;      /* disable canonical mode */
  info.c_cc[VMIN] = 1;          /* wait until at least one keystroke available */
  info.c_cc[VTIME] = 0;         /* no timeout */
  tcsetattr(0, TCSANOW, &info); /* set immediately */
}
void press_key()
{
  printf("\nPremi un tasto per continuare...\n");
  getchar();
}

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
void print_sep(void)
{
  printf("\n=========================================== \n");
}
int main(int argc, char **argv)
{
  float fmin=FLT_MIN*FLT_EPSILON, fmax=FLT_MAX, //feps=FLT_EPSILON, 
        fzero=0, finf=1./0.0, fnan=sqrt(-1.0); 
  init_press_key();

  printf("Minimo numero float rappresentabile:%.7G\n", fmin); 
  printf("che in notazione binaria si rappresenta così:\n");
  printBits(4,(void*)&fmin);
  printf("   (l'esponente 0 vuol dire -126)\n");
  press_key();

  printf("Massimo numero float rappresentabile:%.7G\n", fmax); 
  printf("che in notazione binaria si rappresenta così:\n");
  printBits(4,(void*)&fmax);
  printf("\n");
  press_key();

#if 0
  printf("epsilon float:%.7G\n", feps); 
  printf("che in notazione binaria si rappresenta così:\n");
  printBits(4,(void*)&feps);
  printf("\n");
  press_key();
#endif
  printf("Numero 0 float:%f\n", fzero); 
  printf("che in notazione binaria si rappresenta così:\n");
  printBits(4,(void*)&fzero);
  printf("\n");
  press_key();

  printf("inf float:%f\n", finf); 
  printf("che in notazione binaria si rappresenta così:\n");
  printBits(4,(void*)&finf);
  printf("  (esponente con tutti 1 e mantissa uguale a 0)\n");
  press_key();

  printf("NaN float:%f\n", fnan); 
  printf("che in notazione binaria si rappresenta così:\n");
  printBits(4,(void*)&fnan);
  printf("   (esponente con tutti 1 e mantissa diversa a 0)\n");
  press_key();
}
