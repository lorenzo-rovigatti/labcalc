#include <stdlib.h>
#include <stdio.h>
int main()
{
  char *pc; // N.B. char tra -128 e +127, unsigned char tra 0 e 255 
  char stringa[] = "ciao ";
  unsigned int a = 65534;
  unsigned char *uc;

  //stampo la stringa
  printf("stringa=%s\n", stringa);

  // dereferenzio il puntatore
  pc = stringa;
  printf("*pc=%c\n", *pc);
  printf("*(pc+2)=%c stringa[2]=%c\n", *(pc+2), stringa[2]);

  // modifico la stringa tramite il puntatore
  *(pc+4) = '!';
  printf("stringa=%s\n", stringa);

  //puntare ad un int
  uc = (unsigned char*) &a;// cast esplicito per evitare la warning del comp.
  printf("a=%d *uc=%2x (fe (=254 in base 10) è il contenuto del primo byte)\n", a, *uc);

  uc = uc + 1;
  printf("a=%d *uc=%2x (ff (=255 in base 10) è il contenuto del secondo byte)\n", a, *uc);
}
