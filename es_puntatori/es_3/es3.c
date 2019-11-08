/* Badoino Matteo
  4A°-rob
  16/10/2019
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void caricaVettore(float* vett, int dim);
void leggiVettore(char* v);

void main(){
  int dim=0;
  printf("inserisci dimensioni: ");
  scanf("%d", &dim );
  printf("\n");
  char *vett=(char*)malloc((dim)*sizeof(char));
  caricaVettore(vett, dim);
  //char *vett=(char*)malloc((dim)*sizeof(float));
  printf("ciao");
  leggiVettore(vett);
}

void caricaVettore(float* vett, int dim){
  int i;
  for(i=0;i<dim;i++){
      printf("inserisci valore %d: ", i);
      scanf("%c", (vett+i) );
      printf("\n");
  }
  return;
}
void leggiVettore(char *v){
  int cont=0;
  printf("ciao");
  while(*(v+cont)='\0'){
    printf("%c", *(v+cont) );
    cont++;
  }
  printf("il vettore è lungo %d", cont);
  return 0;
}
