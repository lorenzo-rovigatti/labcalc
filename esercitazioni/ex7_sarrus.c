#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define N 3
#define LOOP 1000
#define MAX_LEN 100
#define SQR(x) ((x) * (x))
#define EPS 1.0E-7
//per compilare in modo che esegua la funzione vettori()
//gcc -o sarrus.x sarrus.c -lm -DPRINT_VECTORS
/************************************************************/
/***************DICHIARAZIONE DI FUNZIONI********************/
void inserimento(char *message, char *format, void *var);
void PrintMatrix(int array[][N],int n1);
void ReadFileName(char filename[]);
void ReadMatrix(char filename[],int matrix[][N],int n1);
int CalcSarrus(int matrix[][3]);
void genvect(double vect[], int n);
void product(double vect1[],double vect2[],int matrix[][N],int n1);
void vettori(int matrix[][N],int n);
/************************************************************/
/************************MAIN*******************************/

int main(){
  unsigned int select;
  char junk[MAX_LEN];
  char text[MAX_LEN];
  char fname[MAX_LEN];
  int i,j,determinante;
  int A[N][N];
  double x[N],y[N];
  FILE *fp;
  srand48(2938472);
  fprintf(stdout,"***********************************************\n");
  fprintf(stdout,"QUESTO PROGRAMMA  CALCOLA IL DETERMINANTE \n");
  fprintf(stdout,"DI UNA MATRICE 3x3 USANDO LA REGOLA DI SARRUS\n");
  fprintf(stdout,"**********************************************\n");
  fprintf(stdout,"\n");
  
  do{
    fprintf(stdout,"PREMI: \n");
    fprintf(stdout,"1- Se vuoi far leggere al programma la matrice da terminale\n");
    fprintf(stdout,"2- Se vuoi far leggere al programma la matrice da file\n");
    fscanf(stdin,"%u", &select);
    fgets(junk,80,stdin);//acchiappa tutti i caratteri extra rimasti nel buffer
    
  }while(select!=1 && select!=2);
  
  if(select==1){
    for(i=0;i<N;i++){
      for(j=0;j<N;j++){
	sprintf(text,"Inserire l'elemento di matrice (%i %i): ",i,j);
	inserimento(text,"%i",&(A[i][j]));
      }
    }
  }else{
    ReadFileName(fname);
    ReadMatrix(fname,A,N);
  }
  fprintf(stdout,"***********************************************\n");
  fprintf(stdout,"La matrice A inserita e': \n");
  //chiamata alla funzione PrintMatrix che stampa la matrice in input su schermo
  PrintMatrix(A,N);
  fprintf(stdout,"\n");
  fprintf(stdout,"**********************************************\n");
  fprintf(stdout,"\n");

  //chiamata alla funzione  per il calcolo del determinante
  determinante=CalcSarrus(A);
  fprintf(stdout,"Il determinante della matrice e' %i\n",determinante);
  fprintf(stdout,"**********************************************\n");
  fprintf(stdout,"\n");
  
  //chiamata alla funzione genvect che genera un versore x 
  genvect(x, N);

  //chiamata alla funzione product che calcola y=Ax.
  product(x,y,A,N);

#ifndef PRINT_VECTORS //compila questa parte solo se non e' definita la macro PRINT_VECTORS
  fprintf(stdout,"Il vettore y = A x e' y=(%lf, %lf, %lf)\n",y[0],y[1],y[2]);
  fprintf(stdout,"***********************************************\n");
  fprintf(stdout,"\n");
  #endif
  
#ifdef PRINT_VECTORS //compila questa parte solo se e' definita la macro PRINT_VECTORS
  //funzione per generare i punti in coordinate.dat
  vettori(A,N);
  #endif
  
  return(0);
}
/************************************************************/
/************************************************************/
/**************DEFINIZIONE DI FUNZIONE***********************/

void inserimento(char *message,char *format, void *var){
  int fine, res=0, c;
  fine=0;
  char junk[80];
  //finche' res non restituisce 1
  while (!fine){
    fprintf(stdout,"%s",message);
    fine=1;
    res=fscanf(stdin,format,var);

    if(res!=1){
      fprintf(stderr,"Problema nella lettura da schermo\n");
      fine=0;
    }

    if(fgets(junk, 80, stdin) != NULL && (junk[0] !='\n')){//se e' rimasto qualcosa nel buffer che non e' il carattere di ritorno

      fprintf(stderr,"c'e' qualcosa che e' rimasto nel buffer: ");
      fprintf(stderr,"%s\n", junk);
      fine=0;
    }
  }
}

void PrintMatrix(int array[][N],int n1){
  int i,j;

  for(i=0;i<n1;i++){
    for(j=0;j<N;j++){
      fprintf(stdout,"%5i ",*(*(array+i)+j));//e' equivalente a scrivere array[i][j]
    }
    fprintf(stdout,"\n");
  }
}
void ReadMatrix(char filename[],int matrix[][N],int n1){
  FILE *fp;
  int i,j;

  fp=fopen(filename,"r");

  if(fp==NULL){
    fprintf(stderr,"Problema nell'apertura del file %s",filename);
    exit(1);
  }
  
  for(i=0;i<n1;i++){
    for(j=0;j<N;j++){
      fscanf(fp,"%i",*(matrix+i)+j);
    }
  }
  fclose(fp);
  
}

void ReadFileName(char filename[]){
  int i,n=0,ok=0;
  char ch;
  char trash[80];
  
  do{
    fprintf(stdout,"Inserire il nome del file da leggere\n");
    while(( (ch=getchar())!='\n' ) && (n<MAX_LEN)){
      filename[n++]=ch;
    }
    if(n>=MAX_LEN){
      fprintf(stderr,"Il nome file inserito  e' troppo lungo\n");
      exit(1);
    }else{
      fprintf(stdout,"Il nome file digitato e':\n");
      for(i=0; i<n; i++)//altrimenti stampo la frase memorizzata putchar(frase[i]);
	putchar(filename[i]);
      printf("\n");
    }
    
    do{
      fprintf(stdout,"- Digita 1 per confermare\n- Digita 0 per riscrivere il nome file\n");
      ok=-1;
      fscanf(stdin,"%i",&ok);
      fgets(trash,80,stdin);//l'ultimo carattere e' \n, quando torno su al primo while viene interrottosubito perche' leggo fino a che non trovo \n. Faccio pulizia
    }while(ok!=1 && ok!=0);
  }while(!ok);
}


int CalcSarrus(int matrix[][3]){//calcola il det. di una matrice 3x3

  int det=0,diag; 
  int i,j;
  int B[3][6];
  //Riempio la matrice B
  for(i=0;i<3;i++){
    for(j=0;j<3;j++){
      B[i][j]=matrix[i][j];
      B[i][3+j]=matrix[i][j];
    }
  }

 for(i=0;i<3;i++){
   diag=1;
   for(j=0;j<3;j++){//calcolo le diagonali 0,1,2
      diag*=B[j][j+i];
      //diag *= (*(*(B+j)+j+i));//versione con i puntatori
     //fprintf(stdout,"(%i %i)\n",j,j+i);
   }
   det+=diag;
   diag=-1;

   for(j=2;j>=0;j--){//calcolo le diagonali 5,4,3
     diag*=B[2-j][3+j-i];
     //diag*=(*(*(B+2-j)+(3+j-i)));//versione con i puntatori
     //fprintf(stdout,"(%i %i)\n",3-(j+1),3+j-i);
   }
   det+=diag;
 }

 return(det);
}

void genvect(double vect[], int n){
  int i;
  double norm=0,new_norm=0;
  for(i=0;i<n;i++){
    *(vect+i)=2.0*(drand48()-0.5);
    norm+=SQR(*(vect+i));//sommo il quadrato delle componenri del vettore
  }

  norm=sqrt(norm);//faccio la radice quadrata 
  
  for(i=0;i<n;i++){
    *(vect+i) /= norm;//divido le componenti per il modulo del vettore
    new_norm+=SQR(*(vect+i));//sommo il quadrato delle componenti del versore
  }
  

  if(sqrt(new_norm-1.0)>EPS){
    fprintf(stderr,"il versore non ha modulo 1 ma %lf\n",new_norm);
    exit(1);
  }
  
}

void product(double vect1[],double vect2[],int matrix[][N],int n1){

  int i,j;
  double norm=0;
 
  for(i=0; i<n1; i++){ /*ciclo sulle righe */
    vect2[i]=0.0;//inizializzo il vettore
    for(j=0; j<N; j++){
      vect2[i] += matrix[i][j]*vect1[j];
    }
    norm+=SQR(vect2[i]);
  }
  //check sul modulo del vettore risultante
#ifndef PRINT_VECTORS
  fprintf(stdout,"Il modulo del vettore y e' %lf\n",norm);
#endif
}

void vettori(int matrix[][N],int n){
  int i,j;
  double vv[N]={0.,0.,0.};
  double ww[N]={0.,0.,0.};
  FILE *fp;
  fp=fopen("coordinate.dat","w");
  for(i=0;i<LOOP;i++){
    genvect(vv, N);
    product(vv,ww,matrix,n);
    //fprintf(stdout,"%lf %lf %lf\n",ww[0],ww[1],ww[2]);
    fprintf(fp,"%lf %lf %lf\n",ww[0],ww[1],ww[2]);
  
  }
  fclose(fp);
  fprintf(stdout,"Ho generato %i vettori e stampati in coordinate.dat\n",LOOP);
}



