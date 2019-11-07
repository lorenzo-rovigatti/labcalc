#include<string.h>
#include<stdio.h>
int main(void)
{
  char a[]="pippo";
  char b[]="pluto";

  printf("la stringa a è %s\n", a);
  strcpy(a,b);
  printf("la stringa a è %s\n", a);

  return 0;
}
