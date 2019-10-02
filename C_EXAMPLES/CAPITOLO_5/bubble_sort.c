#include <stdlib.h>
#include <stdio.h>
#define NC 5

int main()
{
  int data[NC]={4,5,1,2,3};
  int i,j, temp;
 
  // stampo l'array iniziale
  printf("data[] = {");
  for (j=0;j<NC;j++)
    {
      printf("%d",data[j]);
      if (j < NC-1)
        printf(",");
    }
  printf("};\n");
  /* ordino l'array data*/
  printf("ordino dal più grande (data[0]) al più piccolo (data[4])\n");
  /* BUBBLE SORT...
   * dopo ogni ciclo in i ho nella posizione i-esima l'elemento più grande di tutti
   * Il numero di confronti dunque è N-1 + N-2 + ... 1 = N*(N-1)/2 = O(N^2/2)  */
  for (i=0;i<NC-1;i++) // mi fermo a NC-2 poiché j parte da NC - 1 quindi se i=NC-1 il ciclo in j
                       // non verrebbe effettuato
    {
      for (j=NC-1; j > i; j--)//j=NC-1 è l'elemento più in "basso" 0 quello più in "alto"
	// arrivo fino a i, infatti 
	// 1) dopo il primo ciclo in 0 ho sicuramente l'elemento 
       	//    più grande quindi è inutile fari confronti con l'elemento in 0
       	// 2) dopo il secondo ciclo in 0 e 1 ho i due elementi più grandi 
       	//    e quindi è inutile confrontarsi con loro
	{
	  if(data[j] >= data[j-1])
	    {
              /* scambio i due elementi */
	      temp=data[j-1];
	      data[j-1]=data[j];
              data[j]=temp;
	    }
	}
      printf("iterazione i= %d: data[] = {", i);
      for (j=0;j<NC;j++)
        {
          printf("%d",data[j]);
          if (j < NC-1)
            printf(",");
        }
      printf("};\n");

    }
}
