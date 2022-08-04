#include <stdio.h>
#include <stdlib.h>

int main(){

    char firstLine[50];
    int delay;
    char airline[2];
    FILE *originalFile;

    originalFile = fopen("files/Airlines.csv", "r");
    fscanf(originalFile, "%s", firstLine);
    printf("%s", firstLine);

    if(originalFile){
        while(fscanf(originalFile, "%[^,],%d", airline, &delay) != EOF){
            //
        }
        //
    }

    return 0;
}
