#include<stdio.h>
#include<math.h>
int main(void)
{
  const double g = 9.82; /* m/s^2 */ 
  double alpha, G, y, L, v0;
  printf("Immetti v0: ");
  scanf("%lf", &v0);
  printf("Immetti alpha: ");
  scanf("%lf", &alpha);
  printf("Hai immesso:\n   v0=%12.7f\nalpha=%12.7f\n", v0, alpha);
#ifndef PARTE_II 
  printf("Immetti L: ");
  scanf("%lf", &L);
  y = L*tan(alpha) - g*L*L / (2.0*v0*v0*cos(alpha)*cos(alpha));
#endif 
  G = 2.0*v0*v0*sin(alpha)*cos(alpha)/g;
#ifdef PARTE_II
  printf("%.5f %.5f\n", alpha, G);
#else
  printf("La quota a x=%12.7f è %12.7f\n", L, y);
  printf("La gittata del lancio è: %12.7f\n", G);
#endif
  return 0;
}
