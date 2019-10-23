#include <math.h>
#include <stdio.h>
#ifndef METODO
#define METODO 0 // 0 = bisezione 1 = newton
#endif
#define EPSILON 1.0E-7

int main(int argc, char** argv) {
  double delta=10.0*EPSILON;
  double c;
#if METODO==0
  double a = 0., b = M_PI;
#else
  double dc;
#endif
  int i = 1;
  printf("Questo programma trova la soluzione "
         "dell'equazione cos(x)=0 in (0, PI)\n");
#if METODO==0
  printf("Con il metodo della bisezione\n");
#else
  printf("Con il metodo di Newton\n");
  c = M_PI/4.0;
#endif
  while (delta > EPSILON) {
#if METODO==0
    double p;
    c = 0.5 * (a + b);
    p = cos(a) * cos(c);
    if (p > 0.) {
      a = c;
    } else if (p < 0.) {
      b = c;
    } else { 
      a = b = c; /* soluzione esatta */
    }
    printf("Iterazione n. %d: x = %f\n", i++, 
	   0.5 * (a + b));
    delta = fabs(a - b);
#else
    dc = -cos(c)/sin(c); // x = x - f(x)/f'(x) dove qui f(x)=cos(x) e f'(x)=df/dx=-sin(x)
    c = c - dc;
    printf("Iterazione n. %d: x = %f\n", i++, c);
    delta = fabs(dc);
#endif
   }
  printf("La soluzione trovata vale: %f\n", c);
  printf("La soluzione vera vale   : %f\n", 0.5 * M_PI);
  printf("La differenza vale       : %e\n", 
         fabs(0.5 * M_PI - c));
  return 0;
}
