#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LUNG 10
typedef struct contat{
  char name[LUNG];
  int number;
  struct contat* next;
} Contat;

void main() {
  Contat giovanni;
  strcpy(giovanni.name, "giovanni");
  giovanni.number=256;
  giovanni.next=NULL;

  Contat mamma;
  strcpy(mamma.name, "mamma");
  mamma.number=123;
  mamma.next= &giovanni;

  Contat* supporto= mamma;
  do{
    printf("name: %s number: %d\n", supporto.name, supporto.number );
    supporto=supporto.next;
  }while(supporto-> next != NULL);
  return 0;
}
