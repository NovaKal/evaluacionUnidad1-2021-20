#include <stdlib.h>
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
    }
    
    printf("\n");

    fflush(fin);
}