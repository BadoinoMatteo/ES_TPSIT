#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#define N 5
#define PENSA 2
#define HAFAME 1
#define MANGIA 0

sem_t S[N];

int fil[N] = {0,1,2,3,4};

void *filosofo(void *num){
    while(1){
        int *i = num;
        printf("il filosofo %d sta pensando", *i);
        sleep(1);
        printf("filoso %d ha fame", *i);
        sleep(1);
        // prendi forchette
       if(sem_trywait(&S[*i])==0){
           if(sem_trywait(&S[(*i+1)%N])==0){
               printf("il filosofo %d mangia", *i);
               sleep(1);
               sem_post(&S[*i]);
               sem_post(&S[(*i+1)%N]);
               
           }else{
               printf("il filsofo %d non può mangiare", *i);
                }
       }else{
           printf("il filsofo %d non può mangiare", *i);
       }
       sleep(1);
         
    }
}

int main(int argc, char **argv){
    int i;
    pthread_t t[N];

    for (i=0; i<N; i++){
        sem_init(&S[i], 0 ,1);
    }

    for (i=0;i<N;i++){
        pthread_create (&t[N], NULL, filosofo, &fil[i]);
    }

    for(i=0; i<N;i++){
        pthread_join(t[i], NULL);
    }

    return 0;
}