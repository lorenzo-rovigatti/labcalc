#include<stdio.h>
#include<math.h>
int main(void) {
int a=2;
double c=2.0/3.0, c2; // fp a 64 bit
char d=-3;
char d2;
d2=-30;
c2=2.0+c;
printf("un intero occupa %lu\n", sizeof(char));
a=(unsigned int)d;
printf("ciao %i %d\n", a, d2);
return 0;
printf("immetti un intero:");
scanf("%d",&a);
printf("hai immesso %d\n", a);
}
