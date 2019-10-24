#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main(void)
{
  int i;
  // do ... while()
  //
  printf("do....while ()\n");
  i=0;
  do 
    {
      printf("i=%d\n", i);
      i++;
    }
  while (i < 3);

  // while () ....
  printf("\nwhile () ....\n");
  i=0;
  while (i < 3)
    {
      printf("i=%d\n", i);
      i++;
    }
#if 0
if (0 > 1)
  {    
      printf("ciao\n");
    }

  printf("-----------\n");
  i=0;
  printf("i= %f \n", 1./i++);
  printf(">>>i=%d\n", i);
  i=0; 
  printf("i= %d \n", ++i);
  i=0;
  printf("i= %d \n", i=i+1);
  exit(1);
  //che è equivalente a: 
  printf("\nfor () ...\n");
#endif
  for (i=0; i < 3; i++)
    {
     printf("i=%d\n", i);
    }

  //uso di break (si può usare in tutti i costrutti per iterazioni)
  // while () ....
  printf("\nbreak in ciclo while () ....\n");
  i=0;
  while (1)
    {
      printf("i=%d\n", i);
      i++;
      if (i == 3)
        break;
    }

  // uso di continue
  printf("\ncontinue in ciclo while () ....\n");
  i=0;
  while (i < 3)
    {
      if (i==1)
        {
          i++;
          continue;
        }
      printf("i=%d\n", i);
      i++;
    }
  return 0;
}
