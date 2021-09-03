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
    int i = 0;
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

void feature4(FILE *fin, int **parr, int *length, char **op) {
    char buffer[128];
    char *status = NULL;
    char *endptr;
    char *saveEndptr;
    char *auxop;
    int *auxparr;
    int lengthChars;
    status = fgets(buffer, sizeof(buffer), fin);

    if (status != NULL) {
        int i;
        int posStart;
        //strlen(buffer) es 33. En 33 esta el 0, 32 esta el \n y 31 el ultimo char
        for (i = strlen(buffer) - 2; i >= 0; i--) {
            if (buffer[i] == 32) {
                posStart = i;
                lengthChars = strlen(buffer) - i - 1;
                break;
            }
            //printf("buffer[i]: %c, %d\n", buffer[i], i);
        }

        saveEndptr = buffer;
        while (*saveEndptr != 10) {
            if (strtol(saveEndptr, &endptr, 10) == 0) {
                break;
            }
            //printf("%d\n", numero);
            saveEndptr = endptr;
            *length += 1;
        }
        printf("Length: %d\n", *length);
        //printf("Aua: %d\n", lengthChars); -> 4
        auxop = malloc(sizeof(char) * lengthChars);
        for (i = 0; i < lengthChars; i++) {
            auxop[i] = buffer[strlen(buffer) - lengthChars + i];
            if (i == lengthChars - 1) auxop[i] = 0;
            //printf("auxop[%d] = %d\n", i, auxop[i]);
        }
        *op = auxop;
    }
}