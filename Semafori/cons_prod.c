#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define MAXCICLI 100

sem_t mutex, pieno, vuoto;

char buffer[10];
int in, out;

void *produci(void *arg);
void *consuma(void *arg);

int main(int argc, char **argv){
    pthread_t prod, con;

    sem_init(&mutex, 0,1); //sbloccata
    sem_init(&pieno, 0,1);  //bloccato
    sem_init(&vuoto, 0,10); //sblocctata x 10 iterazioni

    pthread_create(&prod, NULL, (void*)produci, NULL);
    pthread_create(&con, NULL, (void*)consuma, NULL);

    pthread_join(&prod, NULL);
    pthread_join(&con, NULL);
}

void *produci(void *arg){
    int i=0;
    char c;
    while ((i<MAXCICLI)){
        i++;
        c= (char)(rand()%26)+97;
        sem_wait(&vuoto);
        sem_wait(&mutex);
        buffer[in]=c;
        printf("inserito %c\n", c);
        in=(in+1)%10;
        sem_post(&mutex);
        sem_post(&pieno);
    }
}

void *consuma(void *arg){
    int i=0;

    while(i< MAXCICLI){
        i++;
        char c;
        sem_wait(&pieno);
        sem_wait(&mutex);
        //sezione critica
        c=buffer[out];
        printf("prelevo %c \n", c);
        out=(out+1)%10;
        sem_post(&mutex);
        //fine sezione critica
        sem_post(&vuoto);
    }
}