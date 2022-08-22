#include <stdio.h>
#include <stdlib.h>
#include "bubblesort.h"

typedef struct {
    char nome[3];
    short int delay;
} rawData;

/*
    Criar biblioteca para o bubbleSort
*/



int main(){

    char firstLine[50];
    short int delay;
    char airline[2];
    FILE *originalFile;
    //Criar variavel

    originalFile = fopen("files/Airlines.csv", "r");
    fscanf(originalFile, "%s", firstLine);
    printf("%s", firstLine);

    if(originalFile){
        while(fscanf(originalFile, "%[^,],%d", airline, &delay) != EOF){// Mudar %d para short int
            //Armazenar dados num array de structs (rawData; airline, delay)
        }
        /*
            Ordenar rawData por ordem alfabetica, atraves do metodo bubbleSort
            criar array de structs newData
            Ler rawData ordenada por airline:
                - criar contador flights = 0 sempre que mudar de airline
                - criar contador delays = 0 sempre que mudar de airline
                - ler airline para armazenar na newData4
                - se a airline for a mesma, somar delays e/ou flights assim que necessario
                - se a airline for diferente:
                    - calcular average(media)
                    - armazenar average e airline na newData
        */
    }

    return 0;
}
