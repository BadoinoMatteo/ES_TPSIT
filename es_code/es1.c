/* Badoino Matteo
 * 27/11/2019
 * es1: Implementare i metodi enqueue() e dequeue()  e creare un programma
 * che permetta all’utente di riempire una coda di numeri interi di lunghezza arbitraria.
 * Successivamente testare la funzione dequeue per svuotare la coda.
*/


#include <stdlib.h>
#include <stdio.h>

typedef struct Lista{
    struct Lista* next;
    int number;
};

void enqueue(struct lista **head,struct lista **tail, struct lista *element);
struct Lista *dequeue(struct lista **head, struct lista **tail);
int is_empty(struct lista *head);
int stampaPila(struct lista *lista);

int main(){
    struct Lista* lista;
    struct Lista* fine;
    struct Lista* num;
    struct Lista* ret;
    while (num>-1){
        printf("inserisci numero -1 per terminare");
        scanf("%d", &num);
        enqueue(lista, fine, num );
    }
    while (lista->next != NULL){
        stampaPila(lista);
        ret=dequeue(lista,  fine);
        free(ret);
    }
}

int is_empty(struct lista *head){
    if(head==NULL){
        return 1;
    }else{
        return 0;
    }
}

void enqueue(struct lista **head, struct lista **tail, struct lista *element){
    if(is_empty(*head)){
        *head=element;
    }else{
        *tail->next=element;
    }
    *tail=element;
    *element->next=NULL;
}

struct Lista *dequeue(struct lista **head, struct lista **tail){
    struct Lista* ret=*head;
    if(is_empty(*head)){
        return NULL;
    }else{
        *head=ret>next;
    }
    if(*head==NULL){
        *tail=NULL;
    }
    return ret;
}

int stampaPila(struct lista *lista){
    if(l->next != NULL){
        printf("\n%d - %p\n", lista->valore, lista->next);
        return StampaLista(lista->next);
    }else{
        printf("\n%d - %p\n", lista->valore, lista->next);
    }
    return 0;
}
