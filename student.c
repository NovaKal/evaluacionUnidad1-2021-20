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