#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[3];
    short int delay;
} rawData;

typedef struct{
    char nome[3];
    short int delay;
    short int travels;
} newData;


int contadorLinhas();
int comparaStr(char str1[], char str2[]);
int bubbleSort(rawData data1[],int tamStr);

int main(){

    char primeiraLinha[50];
    FILE *arqOriginal;
    rawData *dadosOrdenados;
    newData *dadosUnicos;
    int quantidadeLinhas;

    arqOriginal = fopen("./files/Airlines.csv", "r");
    fscanf(arqOriginal, "%s", primeiraLinha);

    quantidadeLinhas = contadorLinhas();

    dadosOrdenados = (rawData*) malloc(quantidadeLinhas*sizeof(rawData));

    int indice = 0;
    while (fscanf(arqOriginal, "%[^,], %hd", dadosOrdenados[indice].nome, &dadosOrdenados[indice].delay) != EOF)
    {
        indice ++;
    }

    bubbleSort(dadosOrdenados, quantidadeLinhas);

    dadosUnicos = (newData*) malloc(quantidadeLinhas*sizeof(newData));

    free(dadosUnicos);
    free(dadosOrdenados);
    fclose(arqOriginal);
    return 0;
}


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

int comparaStr(char str1[], char str2[]) {
    int i = 0;

    while (str1[i] == str2[i] && str1[i] != '\0')
    {
        i++;
    }

    if (str1[i] < str2[i])
    {
        return -1;
    } else if (str1[i] > str2[i])
    {
        return 1;
    } else {
        return 0;
    }

}

int bubbleSort(rawData data1[],int tamStr) {
    int i, j;
    rawData tempData;

    for (i = tamStr - 1; i > 0; i--){
        for (j = 0; j < i; j++)
            if (comparaStr(data1[j].nome, data1[j+1].nome) > 0)
            {
                tempData = data1[j];
                data1[j] = data1[j+1];
                data1[j+1] = tempData;
            }
    }
}

