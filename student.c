#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "student.h"

void feature1(FILE *fin, FILE *fout) {
    char buffer[128];
    char *status = NULL;
    status = fgets(buffer, sizeof(buffer), fin);
    if (status != NULL) {
        fprintf(fout, "%s", buffer);
    }
}

void feature2(FILE *fin, FILE *fout) {
    char buffer[128];
    char *status = NULL;
    status = fgets(buffer, sizeof(buffer), fin);
    if (status != NULL) {
        int length = strlen(buffer);
        for (int i = length - 2; i >= 0; i--) {
            fprintf(fout, "%c", buffer[i]);
        }
    }
}

void feature3(FILE *fin, FILE *fout) {
    char buffer[128];
    char *status = NULL;
    char *endptr;
    char *saveEndptr;
    status = fgets(buffer, sizeof(buffer), fin);
    if (status != NULL) {
        int suma = 0;
        saveEndptr = buffer;
        while (*saveEndptr != 0x0a) {
            suma += strtol(saveEndptr, &endptr, 10);
            saveEndptr = endptr;
        }
        fprintf(fout, "\n%d", suma);
    }
}