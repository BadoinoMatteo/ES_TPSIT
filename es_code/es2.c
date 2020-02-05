/* Badoino Matteo
 * 27/11/2019
 * es2: Scrivere una funzione che inverta una coda, ovvero produca una coda invertendo l’ordine degli elementi della coda di partenza.
 * Suggerimento: utilizzare una pila.
*/


#include <stdlib.h>
#include <stdio.h>

typedef struct Coda{
    int element;
    struct Coda* next;
    struct Coda* prec;
};

typedef struct Pila{
    int number;
    struct Pila* succ;
};
//coda
void enqueue(struct Coda **head,struct Coda **tail, struct Coda *element);
struct Pila *dequeue(struct Coda **head, struct Coda **tail);
int stampaCoda(struct Coda *coda);
int is_emptyCoda(struct Coda *head);
//--------------------------------------------------------------------------------------------------------
//pile
int is_emptyPila(struct Pila *head);
int stampaPila(struct Pila *pila);
void push(struct Pila **pila, struct Pila *element);
struct Coda pop(struct Pila *pila);

int main(){
    int num;
    struct Pila *pila;
    struct Coda *coda;
    struct Coda* head;
    struct Coda* tail;
    struct Coda* element;
    while (num>-1) {
        printf("inserisci numero -1 per terminare");
        scanf("%p", element);
        enqueue(/*head*/coda, /*tail*/ element->prec, element);
    }
    stampaCoda(coda);

    while (coda->next != NULL){
        push(pila, dequeue(coda, tail));
    }
    stampaPila(pila);

    while (pila->succ != NULL){
        enqueue(coda, tail, pop(pila));
    }
    stampaCoda(coda);
}

int is_emptyPila(struct Pila *l){
    if(l->number==NULL){
        return 1;
    } else{
        return 0;
    }
}

void push(struct Pila **valore, struct Pila *element){
    if(is_empty(*valore)){
        *valore=element;
        element->succ=NULL;
    } else{
        element->succ=*valore;
        *valore=element;
    }
}

int stampaPila(struct Pila *l){
    if(l->succ != NULL){
        printf("\n%d - %p\n", l->number, l->succ);
        return StampaLista(l->succ);
    }else{
        printf("\n%d - %p\n", l->number, l->succ);
    }
    return 0;
}

int pop(struct Pila **valore){
    struct Pila *ret=*valore;
    if(is_empty(*valore)){
        return NULL;
    }else{
        *valore=ret->succ;
    }
    return ret;
}

//--------------------------------------------------------------------------------------------
void enqueue(struct Coda **head, struct Coda **tail, struct Pila *element){
    if(is_emptyCoda(*head)){
        *head=element;
    }else{
        *tail->next=element;
    }
    *tail=element;
    *element->next=NULL;
}

struct Lista *dequeue(struct Coda **head, struct Coda **tail){
    struct Lista* ret=*head;
    if(is_empty(*head)){
        return NULL;
    }else{
        *head=ret->next;
    }
    if(*head==NULL){
        *tail=NULL;
    }
    return ret;
}

int stampaCoda(struct Coda *coda){
    if(coda->next != NULL){
        printf("\n%d - %p\n", coda->element, coda->next);
        return StampaCoda(coda->next);
    }else{
        printf("\n%d - %p\n", coda->element, coda->next);
    }
    return 0;
}



