#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<float.h>
#include<curses.h>
#define flt(x) ((float) x) 
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
int main(int argc, char**argv)
{
  init_press_key();
  printf("Numeri in singola precisione (float), nel seguito ^ = elevamento a potenza:\n");
  // 23 sono i bit della mantissa e 8 quelli dell'esponente 
  printf("massimo esponente=%d\n", (int)(pow(2,8-1)-1));
  printf("minimno esponente=%d\n", (int)(-(pow(2,8-1)-2)));
  printf("epsilon (ovvero differenza minima)=\t%.7G (=2^(-23))\n", FLT_EPSILON);
  printf("massimo numero rappresentabile=\t\t%.7G (=1+1/2+1/4+...+ 1/2^(23))*2^(127)\n", FLT_MAX);
  printf("minimo  numero rappresentabile=\t\t%.7G (=1/2^(23))*2^(-126)\n", FLT_MIN*FLT_EPSILON);
  
  printf("\nNumeri in doppia precisione (double):\n");
  // 52 sono i bit della mantissa e 11 quelli dell'esponente 
  printf("massimo esponente=%d\n", (int)(pow(2,11-1)-1));
  printf("minimno esponente=%d\n", (int)(-(pow(2,11-1)-2)));
  printf("epsilon (ovvero differenza minima)=\t%.7G (= 2^(-52))\n", DBL_EPSILON);
  printf("massimo numero rappresentabile=\t\t%.7G (= 1+1/2+1/4+...+1/2^(52))*2^(1023)\n", DBL_MAX);
  printf("minimo  numero rappresentabile=\t\t%.7G (=1/2^(52))*2^(-1022))\n", DBL_MIN*DBL_EPSILON);
    
  press_key();
  printf("ERRORE DI ARROTONDAMENTO\n\n");
  double a, b, c;
  a = 100000000;
  b = 1;
  c = 100000000;
  printf("a,b e c sono numeri in singola precisione\n");
  printf("a=%.0f\n", a);
  printf("b=%.0f\n", b);
  printf("c=%.0f\n", c);

  press_key();
  printf("1/(a+b-c)= %G\n", 1/(flt(a)+flt(b)-flt(c)));

  press_key();
  printf("1/(a-c+b)= %G\n", 1/(flt(a) - flt(c) + flt(b)));

  press_key();
  printf("\nOVERFLOW\n\n");
  a = 2E38;
  b = 2E38;
  c = 1E20;
  printf("a=%.0e\n", flt(a));
  printf("b=%.0e\n", flt(b));
  printf("c=%.0e\n", flt(c));
  press_key();
  printf("(a+b)/c= %G\n", (flt(a)+flt(b))/flt(c));

  press_key();
  printf("a/c+b/c= %G\n", flt(a)/flt(c)+flt(b)/flt(c));

  press_key();
  printf("\nUNDERFLOW\n\n");
  a = 5*FLT_MIN*FLT_EPSILON;
  b = 5*FLT_MIN*FLT_EPSILON;
  c = 10.0;
  printf("a=%G\n", flt(a));
  printf("b=%G\n", flt(b));
  printf("c=%G\n", flt(c));
  press_key();
  printf("a/c+b/c= %G\n", flt(a)/flt(c)+flt(b)/flt(c));

  press_key();
  printf("(a+b)/c= %G\n", (flt(a)+flt(b))/flt(c));

  return 0;
}
