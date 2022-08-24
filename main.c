#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct
{
    char nome[3];
    short int delay;
} rawData;

typedef struct
{
    char airLine[3];
    int totalFlights;
    int delayTotal;
    double media;
} filteredData;

int contadorLinhas();

int comparaStr(char str1[], char str2[]);

void copiaStr(char str1[], char str2[]);

void bubbleSort(filteredData *dadosFiltrados, int quantAirlines);

void bubbleSortAlph(rawData data1[], int tamStr);

int contadorLinhasAereas(rawData arr[], int quantidadeLinhas);

void filtrarDados(rawData raw[], filteredData filtered[], int quantidadeLinhas);

int main()
{
    clock_t t, tBubble1, tBubble2;
    t = clock(); // calcular o tempo de execucao

    char primeiraLinha[50];
    FILE *arqOriginal;
    rawData *dadosOriginais;
    filteredData *dadosFiltrados;
    int quantidadeLinhas;
    int quantidadeAirlines;

    arqOriginal = fopen("./files/Airlines.csv", "r");
    fscanf(arqOriginal, "%s", primeiraLinha);

    quantidadeLinhas = contadorLinhas();

    dadosOriginais = (rawData *)malloc(quantidadeLinhas * sizeof(rawData));

    int indice = 0;
    while (fscanf(arqOriginal, "%[^,], %hd", dadosOriginais[indice].nome, &dadosOriginais[indice].delay) != EOF)
    {
        indice++;
    } // traducao do arquivo csv para um array de struct

    tBubble1 = clock(); // calcular o tempo de execucao do primeiro bubblesort

    bubbleSortAlph(dadosOriginais, quantidadeLinhas); // ordenar o array de struct alfabeticamente

    tBubble1 = clock() - tBubble1; // calcula tempo final de execucao do primeiro bubble sort
    double tempoBubble1 = ((double)tBubble1) / CLOCKS_PER_SEC;
    printf("O primeiro bubblesort levou %f segundos para executar\n", tempoBubble1);

    quantidadeAirlines = contadorLinhasAereas(dadosOriginais, quantidadeLinhas);

    dadosFiltrados = (filteredData *)malloc(quantidadeAirlines * sizeof(filteredData));

    filtrarDados(dadosOriginais, dadosFiltrados, quantidadeLinhas); //  agrupar total de atrasos e voos por linha aeria

    double media;
    for (int i = 0; i < quantidadeAirlines; i++) // alocar a media calculada na struct
    {
        media = (dadosFiltrados[i].delayTotal) / ((double)(dadosFiltrados[i].totalFlights));
        dadosFiltrados[i].media = media;
    }

    tBubble2 = clock(); // calcular o tempo de execucao do segundo bubblesort

    bubbleSort(dadosFiltrados, quantidadeAirlines);

    tBubble2 = clock() - tBubble2; // calcula tempo final de execucao do primeiro bubble sort
    double tempoBubble2 = ((double)tBubble2) / CLOCKS_PER_SEC;
    printf("O segundo bubblesort levou %f segundos para executar\n", tempoBubble2);

    FILE *arq;
    arq = fopen("./files/Airlines_grafico.csv", "wt"); // Cria um arquivo texto para gravação
    if (arq == NULL)
    {
        printf("Problemas na CRIACAO do arquivo\n");
        return 0;
    }

    fputs("Airlines, Media de atrasos",arq);
    for (int i = 0; i < quantidadeAirlines; i++)
    {
        fputs(dadosFiltrados[i].airLine,arq);
        fputs(",",arq);
        fprintf(arq,"%lf",dadosFiltrados[i].media);
    }

    free(dadosOriginais);
    free(dadosFiltrados);
    fclose(arqOriginal);
    fclose(arq);

    t = clock() - t; // calcula tempo final de execucao
    double time_taken = ((double)t) / CLOCKS_PER_SEC;
    printf("O programa levou %f segundos para executar", time_taken);

    return 0;
}

void bubbleSort(filteredData *dadosFiltrados, int quantAirlines)
{
    filteredData *temp = (filteredData *)malloc(sizeof(filteredData));

    for (int a = quantAirlines - 1; a > 0; a--)
    {
        for (int i = 0; i < a; i++)
        {
            if (dadosFiltrados[i].media > dadosFiltrados[i + 1].media)
            {
                *temp = dadosFiltrados[i];
                dadosFiltrados[i] = dadosFiltrados[i + 1];
                dadosFiltrados[i + 1] = *temp;
            }
        }
    }
}

int contadorLinhas()
{
    FILE *fp;
    char linha[50];
    int count = 0;

    fp = fopen("./files/Airlines.csv", "r");
    fscanf(fp, "%s", linha);
    while (fscanf(fp, "%s", linha) != EOF)
    {
        count++;
    }
    return count;
}

int comparaStr(char str1[], char str2[])
{
    int i = 0;

    while (str1[i] == str2[i] && str1[i] != '\0')
    {
        i++;
    }

    if (str1[i] < str2[i])
    {
        return -1;
    }
    else if (str1[i] > str2[i])
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void copiaStr(char str1[], char str2[])
{
    for (int i = 0; i < 3; i++)
    {
        str1[i] = str2[i];
    }
}

void bubbleSortAlph(rawData data1[], int tamStr)
{
    int i, j;
    rawData tempData;

    for (i = tamStr - 1; i > 0; i--)
    {
        for (j = 0; j < i; j++)
        {
            if (comparaStr(data1[j].nome, data1[j + 1].nome) > 0)
            {
                tempData = data1[j];
                data1[j] = data1[j + 1];
                data1[j + 1] = tempData;
            }
        }
    }
}

int contadorLinhasAereas(rawData arr[], int quantidadeLinhas)
{
    char temp[3];
    int contador = 1;

    copiaStr(temp, arr[0].nome);
    for (int i = 0; i < quantidadeLinhas; i++)
    {
        if (comparaStr(temp, arr[i].nome) != 0)
        {
            copiaStr(temp, arr[i].nome);
            contador++;
        }
    }
    return contador;
}

void filtrarDados(rawData raw[], filteredData filtered[], int quantidadeLinhas)
{
    char temp[3];
    int contador = 0;
    int totalDelays = 0;
    int totalFlights = 0;

    copiaStr(temp, raw[0].nome);
    for (int i = 0; i <= quantidadeLinhas; i++)
    {
        if (comparaStr(temp, raw[i].nome) == 0)
        {
            totalFlights++;
            if (raw[i].delay == 1)
            {
                totalDelays++;
            }
        }

        if (comparaStr(temp, raw[i].nome) != 0)
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
