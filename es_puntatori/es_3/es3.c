/* Badoino Matteo
  4A°-rob
  16/10/2019
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define MAX 20


void main(){
    char stringa[MAX] = "matteo";
    char end[3]="\0";
    int tro = -1;
    int k = 0;

    while (k<MAX && tro ==-1){
        /* code */
        if (strcmp((stringa+k), end) == 0){
            /* code */
            tro = k;
        }
        else{
            k++;
        }
    }
    puts(stringa);
    printf("Dimensione: %d\n", k);
}

