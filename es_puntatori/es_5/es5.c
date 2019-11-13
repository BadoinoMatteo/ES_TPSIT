#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LUNG 10
typedef struct contact{
  char name[LUNG];
  int number;
  struct contact* next;
} Contact;

void main() {
  Contact giovanni;
  strcpy(giovanni.name, "giovanni");
  giovanni.number=256;
  giovanni.next=NULL;

  Contat mamma;
  strcpy(mamma.name, "mamma");
  mamma.number=123;
  mamma.next= &giovanni;

  Contat* support= &mamma;
  do{
    printf("name: %s number: %d\n", support->name, support->number );
    support=support->next;
  }while(support-> next != NULL);
    printf("name: %s number: %d\n", support->name, support->number );
  return ;
}
