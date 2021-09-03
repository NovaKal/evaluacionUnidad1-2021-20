#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include "student.h"

int *create_array(int);
char *create_String(int);
void destroy_array(int *);
void destroy_String(char *);
struct Obj_t;

    if (argc == 1 || argc > 4) {
        perror("La cantidad de archivos necesarios para la ejecucion es incorrecta.");
        return(EXIT_FAILURE);
    }

    FILE *inFile = fopen(argv[1], "r");
    FILE *outFile = fopen("./fout", "a+");

    if (inFile == NULL) {
        perror("Open file fin fails: ");
        return(EXIT_FAILURE);
    }

    if (outFile == NULL) {
        perror("Open file fout fails: ");
        return(EXIT_FAILURE);
    }

    int *parr;
    int length = 0;
    char *op;

    feature1(inFile, outFile);
    feature2(inFile, outFile);
    feature3(inFile, outFile);
    feature4(inFile, &parr, &length, &op);
    feature5(outFile, parr, length, op);
    free(parr);
    free(op);
    fclose(inFile);
    fclose(outFile);
    
    return EXIT_SUCCESS;
}

int *create_array(int size){
    return (int * ) malloc(size * sizeof(int));
}

char *create_String(int size) {
    return (char * ) malloc(size  * sizeof(char));
}

void destroy_array(int *this){
    free(this);
}

void destroy_String(char *this){
    free(this);
}
