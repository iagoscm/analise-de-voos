#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char nome[3];
    short int delay;
} rawData;

typedef struct {
    char airLine[3];
    int totalFlights;
    int delayTotal;

} filteredData;

int contadorLinhas();

int comparaStr(char str1[], char str2[]);

void copiaStr(char str1[], char str2[]);

void bubbleSortAlph(rawData data1[],int tamStr);

int contadorLinhasAereas(rawData arr[], int quantidadeLinhas);

void filtrarDados(rawData raw[], filteredData filtered[], int quantidadeLinhas);

int main(){
    clock_t t;
    t = clock();

    char primeiraLinha[50];
    FILE *arqOriginal;
    rawData *dadosOriginais;
    filteredData *dadosFiltrados;
    int quantidadeLinhas;
    int quantidadeAirlines;

    arqOriginal = fopen("./files/Airlines.csv", "r");
    fscanf(arqOriginal, "%s", primeiraLinha);

    quantidadeLinhas = contadorLinhas();

    dadosOriginais = (rawData*) malloc(quantidadeLinhas*sizeof(rawData));

    int indice = 0;
    while (fscanf(arqOriginal, "%[^,], %hd", dadosOriginais[indice].nome, &dadosOriginais[indice].delay) != EOF)
    {
        indice ++;
    }

    bubbleSortAlph(dadosOriginais, quantidadeLinhas);

    quantidadeAirlines = contadorLinhasAereas(dadosOriginais,quantidadeLinhas);

    dadosFiltrados = (filteredData*) malloc(quantidadeAirlines*sizeof(filteredData));

    filtrarDados(dadosOriginais, dadosFiltrados, quantidadeLinhas);

    for (int i = 0; i < quantidadeAirlines; i++)
    {
        printf("%s - %d - %d\n", dadosFiltrados[i].airLine, dadosFiltrados[i].delayTotal, dadosFiltrados[i].totalFlights);
    }
    
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // calculate the elapsed time
    printf("The program took %f seconds to execute", time_taken);

    free(dadosOriginais);
    free(dadosFiltrados);
    
    

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

void copiaStr(char str1[], char str2[]) {
    for (int i = 0; i < 3; i++)
    {
        str1[i] = str2[i];
    }
    
}

void bubbleSortAlph(rawData data1[],int tamStr) {
    int i, j;
    rawData tempData;

    for (i = tamStr - 1; i > 0; i--)
    {
        for (j = 0; j < i; j++)
        {
            if (comparaStr(data1[j].nome, data1[j+1].nome) > 0)
            {
                tempData = data1[j];
                data1[j] = data1[j+1];
                data1[j+1] = tempData;
            }
            
        }
        
    }
    
}

int contadorLinhasAereas(rawData arr[], int quantidadeLinhas) {
    char temp[3];
    int contador = 1;

    copiaStr(temp, arr[0].nome);
    for (int i = 0; i < quantidadeLinhas; i++)
    {
        if (comparaStr(temp,arr[i].nome) != 0)
        {
            copiaStr(temp, arr[i].nome);
            contador++;
        }
        
    }
    return contador; 
}

void filtrarDados(rawData raw[], filteredData filtered[], int quantidadeLinhas) {
    char temp[3];
    int contador = 0;
    int totalDelays = 0;
    int totalFlights = 0;

    copiaStr(temp, raw[0].nome);
    for (int i = 0; i <= quantidadeLinhas; i++)
    {
        if (comparaStr(temp,raw[i].nome) == 0)
        {
            totalFlights++;
            if (raw[i].delay == 1)
            {
                totalDelays++;
            }   
        }
        
        if (comparaStr(temp,raw[i].nome) != 0)
        {
            copiaStr(filtered[contador].airLine, temp);
            filtered[contador].totalFlights = totalFlights;
            filtered[contador].delayTotal = totalDelays;

            copiaStr(temp, raw[i].nome);
            totalDelays = raw[i].delay;
            totalFlights = 1;
            contador++;
        }
        
    }

}
