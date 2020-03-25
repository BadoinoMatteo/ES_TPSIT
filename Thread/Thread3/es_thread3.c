#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t m1, m2;

void *ping (void *arg){

    while(1){
        //sezione critica
        pthread_mutex_lock(&m1);         //--> rosso
        sleep(1);
        printf("ping\n");
        pthread_mutex_unlock(&m2);       //sblocchiamo mutex --> verde
        //sezione critica
    }
}

void *pong (void *arg){
    while(1){
        //sezione critica
        pthread_mutex_lock(&m2);         //--> rosso
        sleep(1);
        printf("pong\n");
        pthread_mutex_unlock(&m1);       //sblocchiamo mutex --> verde
        //fine sezione critica
    }
}

int main(int arg, char **argv){

    pthread_t t1, t2;

    pthread_mutex_unlock(&m1);  //sblocchiamo mutex --> verde
    pthread_mutex_lock(&m2);  //blocchiamo mutex --> rosso

    pthread_create(&t1, NULL,(void*)ping, NULL);
    pthread_create(&t2, NULL,(void*)pong, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    return 0;
}