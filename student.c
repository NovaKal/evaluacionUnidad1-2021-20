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

        fprintf(fout, "%d\n", suma);
    }
    printf("\n");
}

void feature4(FILE *fin, int **parr, int *length, char **op) {
    char buffer[64];
    char *endptr;
    char *saveEndptr;
    char *status = NULL;
    int numero = 1;
    int i = 0;
    int total;

    status = fgets(buffer, sizeof(buffer), fin);

    if (status != NULL) {

        saveEndptr = buffer;

        while (*saveEndptr != 0x0a && numero != 0) {
            numero = strtol(saveEndptr, &endptr, 10);
            if (numero == 0) continue;
            (*parr)[i] = numero;
            saveEndptr = endptr;
            i++;
        }

        for (int j = 0; j < strlen(endptr); j++) {
            (*op)[j] = endptr[j+1];
        }

        *length = i;

    }

    printf("\n");
}

void feature5(FILE *fout, int *parr, int length, char *op) {
    int suma = 0;

    for (int i = 0; i < length; i++) {
        suma += parr[i];
    }

    suma /= length;
    fprintf(fout, "%d\n", suma);

    printf("\n");
}

void feature6(FILE *fin, struct Obj_t *pobj) {
    //Queda complicado explicar que fue lo que hice en este feature
    char buffer[64];
    char *status = NULL;
    char *endptr;
    int posFinalName = 0;
    int posFinalCC = 0;
    long ccNumero;

    status = fgets(buffer, sizeof(buffer), fin);

    if (status != NULL) {
        for (int i = 0; i < sizeof(buffer); i++) {
            if (buffer[i] == 44) {
                posFinalName = i;
            }
            if (buffer[i] == 10) {
                posFinalCC = i;
                i = sizeof(buffer);
            }
        }

        int sizeObjNombre = sizeof(pobj->nombre);
        char name[sizeObjNombre];
        for (int i = 0; i < sizeof(pobj->nombre); i++) {
            name[i] = buffer[i];
        }
        
        name[sizeof(name)] = 0;
        
        int j = 0;
        char numero[posFinalCC - posFinalName];
        for (int i = posFinalName + 1; i < posFinalCC; i++) {
            numero[j] = buffer[i];
            j++;
        }
        ccNumero = strtol(numero, &endptr, 10);

        pobj->nombre = name;
        pobj->cedula = ccNumero;
    }

    printf("\n");
}