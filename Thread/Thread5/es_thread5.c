 /*
        Creare un programma che simuli l'acquisto dei biglietti di un cinema avente due casse
        I biglietti disponibili sono prefissati (risorsa condivisa)
        All'avvio vengono generati n clienti/threads "per la cassa1 e per la cassa2" per procedere all'acquisto.
            - Gestire la situazione in cui vengono generati x clienti per cassa1 e y clienti per cassa2 
        Ogni cliente:
            - accede alla risorsa "biglietti disponibili" in modalità ESCLUSIVA
            - random, acquista un numero di biglietti compreso tra 1 e 5 
            - infine, stampa un messaggio a video indicando 
                1. Quanti biglietti ha tentato di acquistare
                2. Quanti biglietti ha di fatto acquistato
                3. Quanti biglietti sono ancora disponibili
            - prevedere la possibilità in cui:
                1. non tutti i clienti riescano ad acquistare x biglietti (in questo caso acquistare i biglietti residui)
                2. i biglietti siano completamente esauriti
        La rispettiva cassa, al termine di ogni acquisto (o tentativo di acquisto), valuta, con probabilità 1/2 (50% o random val 0-1), 
        se far 'passare' il cliente subito successivo alla medesima fila oppure dare la precedenza al cliente in fila sull'altra cassa 
        Esempio esecuzione:
        > Sono il cliente 489737546 in fila alla cassa1 e voglio acquistare 4 biglietti:
        > biglietti acquistati: 4
        > biglietti disponibili: 96
        > Sono il cliente 794632639 in fila alla cassa2 e voglio acquistare 3 biglietti:
        > biglietti acquistati: 3
        > biglietti disponibili: 93
        > Sono il cliente 876432834 in fila alla cassa2 e voglio acquistare 10 biglietti:
        > biglietti acquistati: 10
        > biglietti disponibili: 83
        ....
        > Sono il cliente 982374984 in fila alla cassa1 e voglio acquistare 8 biglietti:
        > biglietti acquistati: 2
        > biglietti disponibili: 0
        > Sono il cliente 876865756 in fila alla cassa2 e voglio acquistare 10 biglietti:
        > biglietti acquistati: 0
        > biglietti disponibili: 0
*/   
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

int n_biglietti = 30; // Risorsa condivisa: biglietti decrementati ogni volta che vengono acquistati con successo
pthread_mutex_t m1 = PTHREAD_MUTEX_INITIALIZER; // init della mutex
pthread_mutex_t m2 = PTHREAD_MUTEX_INITIALIZER; // init della mutex


void *cassa1(void *argv){
    int rnd;

    /* SEZIONE CRITICA */
    pthread_mutex_lock(&m1); // accesso in mutua esclusione 

    rnd = 1 + rand()%5; // valore random (1<= rnd <=5) 
    printf("Sono il cliente %u in coda alla cassa1 e voglio acquistare %d biglietti\n", pthread_self(), rnd);
    if(n_biglietti == 0){ // se biglietti esauriti 
        printf("Biglietti acquistati 0\n");
    }else if(n_biglietti>0 && rnd<=n_biglietti){ // se biglietti non esauriti e biglietti da acquistare inferiori a quelli disponibili
        printf("Biglietti acquistati %d\n", rnd);
        n_biglietti = n_biglietti - rnd;
    }else if(n_biglietti>0 && rnd>n_biglietti){ // (1° condizione superflua) se biglietti non esauriti e biglietti da acquistare superiori a quelli disponibili 
        printf("Biglietti acquistati %d\n", n_biglietti);
        n_biglietti = 0;
    }

    printf("Biglietti disponibili %d\n", n_biglietti);

    /* FINE SEZIONE CRITICA */
    int c=1+rand()%1;
    if(c==0){
        pthread_mutex_unlock(&m1); // cliente successivo cassa 1
    }else{
        pthread_mutex_unlock(&m2); // lcliente cassa2
    }

	pthread_exit(NULL); // terminazione thread

}

void *cassa2(void *argv){
    int rnd;

    /* SEZIONE CRITICA */
    pthread_mutex_lock(&m2); // accesso in mutua esclusione 

    rnd = 1 + rand()%5; // valore random (1<= rnd <=5) 
    printf("Sono il cliente %u in coda alla cassa2 e voglio acquistare %d biglietti\n", pthread_self(), rnd);
    if(n_biglietti == 0){ // se biglietti esauriti 
        printf("Biglietti acquistati 0\n");
    }else if(n_biglietti>0 && rnd<=n_biglietti){ // se biglietti non esauriti e biglietti da acquistare inferiori a quelli disponibili
        printf("Biglietti acquistati %d\n", rnd);
        n_biglietti = n_biglietti - rnd;
    }else if(n_biglietti>0 && rnd>n_biglietti){ // (1° condizione superflua) se biglietti non esauriti e biglietti da acquistare superiori a quelli disponibili 
        printf("Biglietti acquistati %d\n", n_biglietti);
        n_biglietti = 0;
    }

    printf("Biglietti disponibili %d\n", n_biglietti);

    /* FINE SEZIONE CRITICA */
    int c=1+rand()%1;
    if(c==0){
        pthread_mutex_unlock(&m2); // cliente successivo cassa 2
    }else{
        pthread_mutex_unlock(&m1); // cliente cassa 1
    }
	pthread_exit(NULL); // terminazione thread 
}

int main(int argc, char **argv){
	pthread_t t1[10]; // vettore di tipo pthread_t per 'clienti' che accedono alla 'cassa1'
    pthread_t t2[10]; // vettore di tipo pthread_t per 'clienti' che accedono alla 'cassa2'
	int i;

	for(i=3; i>0; i--){
        printf("Apertura cinema tra %d...\n", i);
        sleep(1);
	}

    srand(time(NULL)); // inizializzazione random => affinchè, ad ogni nuova esecuzione del programma, vengano genereati valori random diversi

    for(i=0; i<10; i++){
        pthread_create(&t1[i], NULL, (void*)cassa1, NULL); // creazione 'cliente' e posizionamento in 'fila alla cassa1' 
        sleep(1);
	}

    for(i=0; i<10; i++){
        pthread_create(&t2[i], NULL, (void*)cassa2, NULL); // creazione 'cliente' e posizionamento in 'fila alla cassa2' 
        sleep(1);
	}

    for(i=0; i<10; i++){
        pthread_join(t1[i], NULL); // attendo terminazione di ogni 'cliente'
	}

    for(i=0; i<10; i++){
        pthread_join(t2[i], NULL); // attendo terminazione di ogni 'cliente'
	}

	return 0;
}