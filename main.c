#include <stdio.h>

int main(){

    char primeiraLinha[50];
    FILE *arqOriginal;

    arqOriginal = fopen("/files/Airlines.csv", "r");
    fscanf(arqOriginal, "%s", primeiraLinha);
    printf("%s", primeiraLinha);

    return 0;
}
