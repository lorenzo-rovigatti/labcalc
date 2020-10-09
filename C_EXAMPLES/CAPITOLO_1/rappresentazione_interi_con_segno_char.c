#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<float.h>
#include<curses.h>
#include <termios.h>

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
          //if (addsp && c==1) 
          //  printf(" ");
          c++;
        }
    }
}
void printBits(size_t const size, void*ptr)
{
  printBitsnm(size, ptr, 1, size*8);
}
void print_sep(void)
{
  printf("\n=========================================== \n");
}
void immetti_intero(char *a, char *s)
{
  int fine, res, c;
  fine=0;
  short int u;
  while (!fine)
    {
      printf("%s", s);
      fine=1;
      res=scanf("%hd", &u);
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
  *a = (char) u;
}

int main(int argc, char **argv)
{
  char ia;
  immetti_intero(&ia, "Immetti un intero a 16 bit con segno (ossia compreso tra -32768 e 32767):");
  printf("il numero intero inserito è così rappresentato in binario (complemento a 2):\n");
  printBits(1, (void*)&ia);
  printf("\n");
  return 0;
}
