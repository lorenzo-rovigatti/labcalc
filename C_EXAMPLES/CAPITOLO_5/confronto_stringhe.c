#include<string.h>
#include<stdio.h>
int main(void)
{
  char a[]="pippo1";
  char b[]="pippo1";
  char c[]="pippo2";
  if (!strcmp(a,b))
    printf("Le stringhe %s e %s sono uguali\n", a, b);
  else
    printf("Le stringhe %s e %s sono diverse\n", a, b);

  if (!strcmp(a,c))
    printf("Le stringhe %s e %s sono uguali\n", a, c);
  else
    printf("Le stringhe %s e %s sono diverse\n", a, c);

  return 0;
}
