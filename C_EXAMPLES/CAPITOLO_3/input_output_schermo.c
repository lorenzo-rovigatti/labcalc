#include<stdio.h> // dichiarazioni di printf e scanf

// definizione nel codice della macro, ma possono
// anche essere definite dalla riga di comando in fase
// di compilazione

#define STAMPA_SEP 0 // oppure da riga di comando gcc -D STAMPA_SEP=1 (o 0)
#define CHIEDI_INTERO 
// oppure #undef CHIEDI_INTERO oppure 
// da riga di comando: gcc -D CHIEDI_INTERO 

// definisco la macro K (valore da assegnare ad a, vedi sotto)
#define K 2/3

int main(void)
{
  double a = K, c=3000000000;
  float b = 1.0/3; // casting implicito
  int i=5, l=-5, k;
  printf("a=%f b=%f  c=%g\n", a, b, c); 
  printf("i=%d l=%d l=%u\n", i, l, l); // casting implicito da int ad unsigned int --> C è "weakly typed"!!
  printf("notare che l=%u=2^32-5 è -5 in complemento a 2!\n", l);
#if STAMPA_SEP==1
  printf("---------------------\n");
#endif
#if STAMPA_SEP>1
  printf("*********************\n");
#endif
  printf("Immetti un double:");
  scanf("%lf", &a);
  printf("Hai immesso a=%f\n", a);
#ifdef CHIEDI_INTERO // o anche #if defined(CHIEDI_INTERO)
  printf("Immetti un intero:");
  scanf("%d", &i);
  printf("Hai immesso i=%d\n", i); 
#endif

#if 1
  printf("fine1\n");
#else
  printf("fine2\n");
#endif

  // gli operatori relazionali (>, <, !=, ==) agiscono su interi o float e restituiscono vero (1) o falso (0) 
  k = i > l;
  printf("k=%d  !k=%d\n", k, !k);


  printf("k=3  !k=%d\n", !3); // diverso da 0 vuol dire "vero", uguale a 0 vuol dire "falso"
  
  printf("(%d > %d) && 1 = %d\n", i, l, (i > l) && 1);
}
