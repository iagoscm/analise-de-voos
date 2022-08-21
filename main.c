#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct {
    char nome[3];
    short int delay;
} rawData;

typedef struct {
    char nome[3];
    short int delay;
} example;

int contadorLinhas() {
    FILE *fp;
    char linha[50];
    int count = 0;

    
    fp = fopen("./files/Airlines.csv", "r");
    fscanf(fp,"%s",linha);
    while (fscanf(fp,"%s",linha) != EOF)
    {
        count++;
    }
    return count;
    
}

int media(){
    int indice = 0;
    int flights=0;

}

int main(){
    clock_t t;
    t = clock();


    char primeiraLinha[50];
    FILE *arqOriginal;
    rawData *dadosOriginais;
    int quantidadeLinhas;

    arqOriginal = fopen("./files/Airlines.csv", "r");
    fscanf(arqOriginal, "%s", primeiraLinha);

    quantidadeLinhas = contadorLinhas();

    dadosOriginais = (rawData*) malloc(quantidadeLinhas*sizeof(rawData));

    int indice = 0;
    while (fscanf(arqOriginal, "%[^,], %hd", dadosOriginais[indice].nome, &dadosOriginais[indice].delay) != EOF)
    {
        indice ++;
    }
    

    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // calculate the elapsed time
    printf("The program took %f seconds to execute", time_taken);

    //pra simular o vetor vindo já em ordem alfabetica
    example ex[5];
    ex[0].delay=0;
    ex[1].delay=1;
    ex[2].delay=0;
    ex[3].delay=1;
    ex[4].delay=1;
    strcpy(ex[0].nome, "AB");
    strcpy(ex[1].nome, "AB");
    strcpy(ex[2].nome, "AB");
    strcpy(ex[3].nome, "BT");
    strcpy(ex[4].nome, "BT");
    

    free(dadosOriginais);
    
    

    return 0;
}
