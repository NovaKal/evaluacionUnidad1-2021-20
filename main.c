#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "student.h"

int *create_array(int);
char *create_String(int);
void destroy_array(int *);
void destroy_String(char *);
struct Obj_t;

int main(int argc, char *argv[]) {

    FILE *inFile = fopen("./fin", "r");
    FILE *outFile = fopen("./fout", "a+");

    struct Obj_t obj1;
    struct Obj_t *pobj1 = &obj1;

    char *auxop = create_String(10);
    char **op = &auxop;
    int *auxparr = create_array(20);
    int **parr = &auxparr;
    int auxlength;
    int *length = &auxlength;

    if (inFile == NULL) {
        perror("Open file fin fails: ");
        return(EXIT_FAILURE);
    }

    if (outFile == NULL) {
        perror("Open file fout fails: ");
        return(EXIT_FAILURE);
    }

    feature1(inFile, outFile);
    feature2(inFile, outFile);
    feature3(inFile, outFile);
    feature4(inFile, parr, length, op);
    feature5(outFile, auxparr, *length, auxop);

    feature6(inFile, pobj1);
    
    destroy_array(auxparr);
    destroy_String(auxop);
    
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
