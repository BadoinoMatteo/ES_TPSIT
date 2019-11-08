#include <stdio.h>
#include <stdlib.h>
// crea una lista
struct El{                  //struttura autodeferenziata
  int valore;
  struct El *next;
};

void StampaLista(struct  El* l);
int lunghezzaListaCiclo(struct El* l, int* lunghezzaCiclo);
int lunghezzaListaRicorsiva(struct El* l);

int main() {

  int n;
  struct El *lista;     //puntatore al primo elemento della lista
  struct El *l;
  int contCiclo=0;
  lista=NULL;    // inizializza il puntatore
  do{
    printf("inserisci un naturale o -1 per terminare\n" );
    scanf("%d", &n );
    if(n>=0){
      if(lista==NULL){ //verifico se il puntatore è uguale a NULL
        // alloca lo spazio per una struttura
        lista= (struct El*) malloc(sizeof(struct El));
        l=lista;    //assegno a l lista
      }else{    // se lista è diverso da NULL
          //viene allocato lo spazio in memoria per una nuova struttura e assegna al puntatore l dell'elemento corrente che punta all'elemento sucessivo
        l->next=(struct El*) malloc(sizeof(struct El));
        l=l->next;
      }
      l->valore=n; // assegno n al campo valore dell'elemento corrente
      l->next=NULL;    //assegno al campo next dell'elemento corrente il valore NULL
    }
  }while (n>=0);
  l=lista; // l usato come variabile d'appoggio a cui viene assegnato il primo puntatore della lista
  printf("numeri inseriti:" );
  while(l!=NULL){
    printf("%d - %p\n", l->valore, l->next);
    l=l->next; // il puntatore corrente è assegnato al puntatore dell'elemento successivo
  }
  printf("\nstampa ricorsiva:");
  StampaLista(lista);
  lunghezzaListaCiclo(lista, &contCiclo);
  printf("lunghezza lista calcolata con il ciclo:%d", contCiclo );
  printf("\nlunghezza lista calcolata in modo ricorsivo:%d", lunghezzaListaRicorsiva(lista));

return 0;
}

void StampaLista(struct  El* l) {
    if(l->next != NULL){
        printf("%d - %p\n", l->valore, l->next);
        return StampaLista(l->next);
    }else{
        printf("%d - %p\n", l->valore, l->next);
    }
}

int lunghezzaListaCiclo(struct El* l, int* lunghezzaCiclo){
    int contatore=0;
    while(l!=NULL){
        l=l->next;
        contatore++;
    }
    *lunghezzaCiclo=contatore;
    return 0;
}

int lunghezzaListaRicorsiva(struct El* l){
    int contatore=0;
    if(l->next!=NULL){
        return 1+lunghezzaListaRicorsiva(l->next);
    }else{
        return 1;
    }
}
