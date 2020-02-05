/* Badoino Matteo
 * es1.c:Creare un programma che dato un numero intero, avente un numero arbitrario di cifre inserite dall’utente,
 * lo scriva in output con le cifre in ordine inverso.
 * Utilizzare una pila e le implementazioni dei metodi push e pop.
 * 19/11/2019
*/

struct El{
    int valore;
    struct El *next;
};

void push(struct El **valore, struct El *element);
int is_empty(struct El *l)
int pop(struct El *l);
int stampaPila(struct El **valore);

int main(){
    struct El *lista;
    int num=0;
    while (num>-1){
        printf("inserisci numero -1 per terminare");
        scanf("%d", &num);
        push(lista, num);
    }
    while (l->next != NULL){
        stampaPila(lista);
        free(pop(l->next));
    }

}

int is_empty(struct El *l){
    if(l->valore==NULL){
        return 1;
    } else{
        return 0;
    }
}

void push(struct El **valore, struct El *element){
    if(is_empty(*valore)){
        *head=element;
        element->next=NULL;
    } else{
        element->next=*head;
        *head=element;
    }
}

int stampaPila(struct El *l){
    if(l->next != NULL){
        printf("\n%d - %p\n", l->valore, l->next);
        return StampaLista(l->next);
    }else{
        printf("\n%d - %p\n", l->valore, l->next);
    }
    return 0;
}

int pop(struct El **valore){
    if(is_empty(*valore)){
        return NULL;
    }else{
        *head=ret->next;
    }
    return ret;
}