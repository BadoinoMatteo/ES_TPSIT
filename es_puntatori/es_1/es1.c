/* Badoino Matteo
  4A°-rob
  16/10/2019
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void caricaVettore(float* vett, int dim);
void controlloVettore(float* vett, int dim);

void main(){
  int dim=0;
  printf("inserisci dimensioni: ");
  scanf("%d", &dim );
  printf("\n");
  float *vett=(float*)malloc((dim)*sizeof(float));
  caricaVettore(vett, dim);
  stampaVettore(vett , dim);
}

  void caricaVettore(float *vett, int dim){
    int i;
    for(i=0;i<dim;i++){
        printf("inserisci valore %d: ", i);
        scanf("%f", (vett+i) );
        printf("\n");
    }
    return;
}

  void stampaVettore(float *vett, int dim){
    int i;
    for(i=0;i<dim;i++){
      printf("%.2f\n", *(vett+i) );
    }
    return;
}
