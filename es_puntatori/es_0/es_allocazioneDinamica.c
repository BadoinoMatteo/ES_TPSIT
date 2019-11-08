/* Badoino Matteo
    11/10/2019
*/

#include <stdlib.h>
#include <stdio.h>

void caricaVettore(int v[], int n);
void maggiore(int v[], int n);
void minore(int v[], int n);

void main(){
    int dim;
    printf("inserisci dimensioni");
    scanf("%d", &dim );
    int *vett =malloc((dim)*sizeof(int));
    caricaVettore(vett, dim);
    maggiore(vett, dim);
    minore(vett, dim);
    return ;
}

void caricaVettore(int v[], int n){
  int cont;
  int somma=0;
  for(cont=0;cont<n;cont++){
    printf("inserisci valore %d", cont );
    scanf("%d", &v[cont]);
    somma=somma+v[cont];
  }
  printf("somma=%d", somma);
  return ;
}

void maggiore(int v[], int n){
    int cont;
    int maggiore=0;
    for(cont=0;cont<n; cont++){
        if(maggiore<v[cont]){
            maggiore=v[cont];
        }
    }
    printf("\nnumero maggiore:%d", maggiore);
}

void minore(int v[], int n){
    int cont;
    int minore=500;
    for(cont=0;cont<n; cont++){
        if(minore>v[cont]){
            minore=v[cont];
        }
    }
    printf("\nnumero minore:%d", minore);
}