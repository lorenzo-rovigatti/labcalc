#include<stdlib.h>
#include<stdio.h>
#define N 10000000 
void f(void);//dichiarazione ovvero prototipo
#ifdef HEAP
int a[N];
#endif
int main()
{
  f();
}
// definizione della funzione
void f(void) // il tipo restituito di default è int
{
  // corpo della funzione
#ifndef HEAP
  int a[N];
#endif
  int i;
  for (i=0; i < N; i++)
    a[i]=1;
}
