#include <stdio.h>
#include <pthread.h>

int stampaID(void *arg){
    int tID=pthread_self();
    int dato=*((int*)arg);

    printf("sono il thread %u. Parametro passato: %d \n", tID, dato);

    pthread_exit(0);
}

void main(){
    pthread_t t[10];
    int i;

    for (i=0; i<10; i++){
        pthread_create(&t[i], NULL, (void *) &stampaID, (void*)  &i);
    }

    printf("Padre: attendo i 10 thread creat\n");

    for(i=0;i<10;i++){
        pthread_join(t[i], NULL);
    }

    printf("Tutti i thread sono terminati \n");
}