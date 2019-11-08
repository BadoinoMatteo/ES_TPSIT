/* Badoino Matteo
 4° A-rob
 inizio:16/09/2019
 continuazione: 21/09/2019 - 26/09/2019
 fine:
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//lunghezza pre stabilita di tutte le stringhe
#define STRINGA 1000
// n giochi che si vogliono leggere
#define NUMGIOCHI 17000

/*stringhe dichiarate come puntatore*/
typedef struct tabella{
    int rank;
    char* name;
    char* platform;
    int year;
    char* genre;
    char* publisher;
    float naSales;
    float euSales;
    float jpSales;
    float otherSales;
    float globalSales;
} Tabella;

void leggiFile(Tabella giochi[], int max, int *numeroGiochi, char file[], int lungStr);
void stampaTabella(Tabella giochi[], int numeroGiochi);

int main(){
  /*code*/
  Tabella giochi[NUMGIOCHI];
  char nomeFile[]="vgsales.csv";
  int numGiochi=0;
  /*
  -passo la tabella;
  -il numero massimo di giochi che voglio leggere;
  -numGiochi per indirizzo, in cui mi memorizzerà il numero effettivo di giochi letti;
  -il nome del file da cui leggo i giochi;
  -la dimensione massima delle stringhe che poi utilizzerò;
  */
  leggiFile(giochi, NUMGIOCHI, &numGiochi, nomeFile, STRINGA);
  stampaTabella(giochi, numGiochi);
  return 0;
}

void leggiFile(Tabella giochi[], int max, int *numeroGiochi, char file[], int lungStr){
  /*code*/
  FILE *fp;
  char str[lungStr];
  char primaRiga[lungStr];
  char *pch;
  int k=0;

  fp = fopen(file, "r");

  if (fp==NULL){
    printf("Il file '%s' non esiste.\n", file);
  }
  else{
    fgets(primaRiga, lungStr, fp);
    printf("%s\n", primaRiga);
    while(k<max && fgets(str, lungStr, fp)!=NULL){
      pch = strtok (str, ",");
      giochi[k].rank=atoi(pch);
      pch = strtok (NULL, ",");
      /*con questa operazione definisco la grandezza della stringa in memoria*/
      giochi[k].name = malloc((strlen(pch) + 1)*sizeof(char));
      strcpy(giochi[k].name,pch);
      pch = strtok (NULL, ",");
      /*con questa operazione definisco la grandezza della stringa in memoria*/
      giochi[k].platform = malloc((strlen(pch) + 1)*sizeof(char));
      strcpy(giochi[k].platform,pch);
      pch = strtok (NULL, ",");
      giochi[k].year=atoi(pch);
      pch = strtok (NULL, ",");
      /*con questa operazione definisco la grandezza della stringa in memoria*/
      giochi[k].genre = malloc((strlen(pch) + 1)*sizeof(char));
      strcpy(giochi[k].genre,pch);
      pch = strtok (NULL, ",");
      /*con questa operazione definisco la grandezza della stringa in memoria*/
      giochi[k].publisher = malloc((strlen(pch) + 1)*sizeof(char));
      strcpy(giochi[k].publisher,pch);
      pch = strtok (NULL, ",");
      giochi[k].naSales=atof(pch);
      pch = strtok (NULL, ",");
      giochi[k].euSales=atof(pch);
      pch = strtok (NULL, ",");
      giochi[k].jpSales=atof(pch);
      pch = strtok (NULL, ",");
      giochi[k].otherSales=atof(pch);
      pch = strtok (NULL, ",");
      giochi[k].globalSales=atof(pch);
      k++;
    }
  }
  fclose(fp);
  *numeroGiochi=k;
}

void stampaTabella(Tabella giochi[], int numeroGiochi){
  /*code*/
  for(int k=0;k<numeroGiochi;k++){
    printf("%d, %s, %s, %d, %s, %s, %.2f, %.2f, %.2f, %.2f, %.2f\n", giochi[k].rank, giochi[k].name, giochi[k].platform, giochi[k].year, giochi[k].genre, giochi[k].publisher, giochi[k].naSales, giochi[k].euSales, giochi[k].jpSales, giochi[k].otherSales, giochi[k].globalSales);
  }
}
