#include<stdlib.h>
#include<stdio.h>
int ag; // variabile globale
void f(int);//dichiarazione ovvero prototipo
int main()
{
  ag=1;
  f(3);
  printf("ag=%d\n", ag);
}
// definizione della funzione
void f(int ag) // il tipo restituito di default è int
{
  // corpo della funzione
  ag=ag+1;
}
