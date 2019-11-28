#include<stdlib.h>
#include<stdio.h>
int ag; // variabile globale
void f(void);//dichiarazione ovvero prototipo
int main()
{
  ag=1;
  f();
  printf("ag=%d\n", ag);
}
// definizione della funzione
void f(void) // il tipo restituito di default è int
{
  int ag=3;
  // corpo della funzione
  ag=ag+1;
}
