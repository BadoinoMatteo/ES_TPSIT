#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LUNG 10
typedef struct tabella{
  char nome[LUNG];
  int number;
} Tabella;

int main(){
  Tabella* list;
  int dim=0;
  printf("inserisci dimensioni: ");
  scanf("%d", &dim );
  printf("\n");
  int *Tabella=(int*)malloc((dim)*sizeof(int));
  free(dim);
  for(int i=0; i<dim; i++){
    char n[LUNG];
    printf("inserisci nome:\n" );
    gets(n);
    strcpy(Tabella[i].nome,n );
    printf("%s\n", Tabella[i].nome);
  }
  printf("indirizzo tabella: %d\n", Tabella );
  return 0;
}
