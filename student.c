#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "student.h"

void feature1(FILE *fin, FILE *fout) {
    
    char buffer[64];
    char *status = NULL;

    status = fgets(buffer, sizeof(buffer), fin);

    if (status != NULL) {
        fprintf(fout, "%s", buffer);
    }

    printf("\n");
    fflush(fin);
}

void feature2(FILE *fin, FILE *fout) {

    char buffer[70];
    char *status = NULL;

    status = fgets(buffer, sizeof(buffer), fin);

    if (status != NULL) {

        for (int i = sizeof(buffer) - 2; i >= 0; i--) {
            fprintf(fout, "%c", buffer[i]);
        }

        fprintf(fout, "%s", "\n");
    }
    
    printf("\n");
    fflush(fin);
}

void feature3(FILE *fin, FILE *fout) {
    
    char buffer[64];
    char *endptr;
    char *saveEndptr;
    char *status = NULL;
    int suma = 0;

    //Aui va mensaje para el profesor. El mensaje como tal esta en el commit del feature 3.
    status = fgets(buffer, sizeof(buffer), fin);
    status = fgets(buffer, sizeof(buffer), fin);

    if (status != NULL) {

        saveEndptr = buffer;

        while (*saveEndptr != 0x0a) {
            suma += strtol(saveEndptr, &endptr, 10);
            saveEndptr = endptr;
        }

        fprintf(fout, "%d", suma);
    }

    printf("\n");
    fflush(fin);
}

void feature4(FILE *fin, int **parr, int *length, char **op) {
    //Esto se hace con la lectura 11. Memoria Dinamica porque si guarda algo aqui, cuando se acabe de ejecutar, se va el stack a la mierda
    
    //**int par es un puntero que guarda la direccion de otro puntero de tipo int que guarda la direccion de una variable tipo int
    char buffer[64];
    char *status = NULL;

    status = fgets(buffer, sizeof(buffer), fin);

    if (status != NULL) {

    }

    printf("\n");
    fflush(fin);
}