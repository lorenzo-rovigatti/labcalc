#include<stdio.h>
#include<float.h>

int main(int argc, char**argv)
{
  printf("Numeri in singola precisione (float), nel seguito ^ = elevamento a potenza:\n");
  // 23 sono i bit della mantissa e 8 quelli dell'esponente 
  printf("epsilon (ovvero differenza minima)=\t%.7G (=2^(-23))\n", FLT_EPSILON);
  printf("massimo numero rappresentabile=\t\t%.7G (=1+1/2+1/4+...+ 1/2^(23))*2^(127)\n", FLT_MAX);
  printf("minimo  numero rappresentabile=\t\t%.7G (=1/2^(23))*2^(-126)\n", FLT_MIN*FLT_EPSILON);
  
  printf("\nNumeri in doppia precisione (double):\n");
  // 52 sono i bit della mantissa e 11 quelli dell'esponente 
  printf("epsilon (ovvero differenza minima)=\t%.7G (= 2^(-52))\n", DBL_EPSILON);
  printf("massimo numero rappresentabile=\t\t%.7G (= 1+1/2+1/4+...+1/2^(52))*2^(1023)\n", DBL_MAX);
  printf("minimo  numero rappresentabile=\t\t%.7G (=1/2^(52))*2^(-1022))\n", DBL_MIN*DBL_EPSILON);
}
