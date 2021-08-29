#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "student.h"

int *create_array(int);
char *create_String(int);
void destroy_array(int *);
void destroy_String(char *);

int main(int argc, char *argv[]) {

    FILE *inFile = fopen("./fin", "r");
    FILE *inFileOut = fopen("./fout", "a+");
    char *auxop = create_String(10);
    char **op = &auxop;
    int *auxparr = create_array(20);
    int **parr = &auxparr;
    int *length;
    
    if (inFile == NULL) {
        perror("Open file fin fails: ");
        return(EXIT_FAILURE);
    }

    if (inFileOut == NULL) {
        perror("Open file fout fails: ");
        return(EXIT_FAILURE);
    }

    feature1(inFile, inFileOut);
    feature2(inFile, inFileOut);
    feature3(inFile, inFileOut);
    feature4(inFile, parr, length, op);
    feature5(inFileOut, auxparr, *length, auxop);
    
    destroy_array(auxparr);
    destroy_String(auxop);
    
    fclose(inFile);
    fclose(inFileOut);
    
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
