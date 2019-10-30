#include <stdio.h>
#include <math.h>

int main(void)
{
#ifdef QUARTA_PARTE
  double vx, vy;
#endif
  double R, w, t, x, y;
  R = 6.2; /* m */
  w = 0.1; /* rad/s */
#ifndef INTERATTIVO
   t = 0.0; /* s */
  x = R * cos(w*t);
  y = R * sin(w*t);
  printf("t = %.4f x = %.5f y = %.5f\n", t, x, y);
  t = 0.5; /* s */
  x = R * cos(w*t);
  y = R * sin(w*t);
  printf("t = %.4f x = %.5f y = %.5f\n", t, x, y);
  t = 10; /* s */
  x = R * cos(w*t);
  y = R * sin(w*t);
  printf("t = %.4f x = %.5f y = %.5f\n", t, x, y);
  t = 20; /* s */
  x = R * cos(w*t);
  y = R * sin(w*t);
  printf("t = %.4f x = %.5f y = %.5f\n", t, x, y);
#else
  /* blocco interattivo */
  printf("Immetti il tempo t: ");
  scanf("%lf", &t);
  x = R * cos(w*t);
  y = R * sin(w*t);
#ifdef QUARTA_PARTE
  vx = -w*R*sin(w*t);
  vy = w*R*cos(w*t); 
  printf("%.5f %.5f %.5f %.5f %.5f\n", t, x, y, vx, vy);
#else
  printf("%.5f %.5f %.5f\n", t, x, y);
#endif
#endif
}

