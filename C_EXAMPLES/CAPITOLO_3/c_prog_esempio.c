#include<stdio.h> // printf e scanf
#include<math.h>  // funzioni matematiche
int main(void) {
// dichiarazioni di variabili (char, int, float e double e modificatori)
char c1, c2='c'; // c2 viene inizializzata nella dichirazione
unsigned uc1;
int ia;
long int ib=3;  // ib viene inizializzata nella dichiarazione
long long int ic;
unsigned int uia;
float fa;
double da, da_, da1; // fp a 64 bit
long double lda=3E10, lda_b; // lda viene inizializzata nella dichiarazione

// stampa dimensione 
printf("un char occupa: %lu bytes\n", sizeof(char));
printf("un int occupa: %lu bytes\n", sizeof(int));
printf("un long int occupa: %lu bytes\n", sizeof(long int));
printf("un long long int occupa: %lu bytes\n", sizeof(long long int));

c1=99; // inizializzo c1 (cioè gli assegno un valore)
ia=-3;
uia=(unsigned int)ia;
printf("uia=%u\n", uia);
da=3.0;
da_= sin(M_PI*0.5)+3.0; // istruzione composta da diversi operatori ed operandi (operatori: =, *, +, operandi: costanti e da_)
printf("da=%f da_=%f\n", da_, da);
da1 = (da < da_) + 1.0;
printf("da1=%f %f\n", da1, da_+da1+da1*sinh(3.0)+pow(da1,0.5));
//
// stampa in esadecimale
uia=163;
printf("%d in esadecimale è: %x\n", uia, uia); 

// stampa di una stringa
printf("prova di %s\n", "stringa");

// inserimento di un char da tastiera
printf("immetti un carattere:");
scanf("%c",&c1);
printf("hai immesso %c\n", c1);

/* inserimento di un intero da tastiera */
printf("immetti un intero:");
scanf("%d",&ia);
printf("hai immesso %d\n", ia);

printf("immetti un float:");
scanf("%f",&fa);
printf("hai immesso %f\n", fa);

printf("immetti un double:");
scanf("%lf",&da);
printf("hai immesso %f\n", da);

return 0;
}
