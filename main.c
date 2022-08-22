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
    int voos;
    int voosAtrasados;
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

int main(){
    clock_t t;
    t = clock();

    int i;
    double media[50]; //substituir 50 pelo tamanho do vetor de struct com dados de voos e voos atrasados, que é a qntd de linhas aereas
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
    ex[0].voos=20;
    ex[0].voosAtrasados=2;
    ex[1].voos=100;
    ex[1].voosAtrasados=20;
    ex[2].voos=2000;
    ex[2].voosAtrasados=400;
    ex[3].voos=11;
    ex[3].voosAtrasados=1;
    ex[4].voos=104;
    ex[4].voosAtrasados=4;
   
    for (i=0;i<5;i++){ //preenchendo array media que vai ser o eixo y
        media[i] = (ex[i].voosAtrasados)/((double)(ex[i].voos));
    }

    free(dadosOriginais);
    
    

    return 0;
}
