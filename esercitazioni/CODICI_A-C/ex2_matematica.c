#include <stdio.h>
#include <math.h>


int main()
{
  char nome[50];
  printf("Introdurre il proprio nome\n");
  scanf("%s",nome);
  printf("Benvenuta %s! Questo è un programma dimostrativo delle funzioni della libreria math.h.\n",nome);
  printf("\n8 + 7 = %3i\t3.2 + 8.4 = %.4f\t2^2+4^2 = %.4f\tsqrt(36) = %.4f\n", 8 + 7, 3.2 + 8.4, pow(2, 2) + pow(4, 2), sqrt(36));
  printf("\ncos(pi/6) = %.4f\tsin(pi/6) = %.4f\ttanh(1) = %.4f\tsinh(0) = %.4f\n", cos(M_PI/6), sin(M_PI/6), tanh(1), sinh(0));

}
