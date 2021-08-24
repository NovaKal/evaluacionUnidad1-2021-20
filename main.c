#include <stdio.h>
#include <stdlib.h>
#include "student.h"

int main(int argc, char *argv[]){

    FILE *inFile = fopen("./fin", "r");
    FILE *inFileOut = fopen("./fout", "a+");
    if (inFile == NULL) {
        perror("Open file fin fails: ");
        return(EXIT_FAILURE);
    }
    if (inFileOut == NULL) {
        perror("Open file fout fails: ");
        return(EXIT_FAILURE);
    }

    for (int i = 0; i < 6; i++)
    {
        if (i == 1) feature1(inFile, inFileOut);
    }
    
    fclose(inFile);
    fclose(inFileOut);
    
    return EXIT_SUCCESS;
}
