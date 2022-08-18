#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char nome[3];
    short int delay;
} rawData;

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

    free(dadosOriginais);
    
    

    return 0;
}
