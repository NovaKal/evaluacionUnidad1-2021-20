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
    /*Variables Generales*/
    char buffer[128];
    char *status = NULL;
    char *endptr;
    char *saveEndptr;
    char *auxop;
    int *auxparr;
    int lengthChars;

    status = fgets(buffer, sizeof(buffer), fin);

    if (status != NULL) {
        /*Variables si existe texto*/
        int i;
        int numero;
        int j = 0;
        int posStart;

        /*Conocer length de los chars que indican operacion*/
        for (i = strlen(buffer) - 2; i >= 0; i--) {
            if (buffer[i] == 32) {
                posStart = i;
                lengthChars = strlen(buffer) - i - 1;
                break;
            }
        }

        /*Conocer cantidad de numeros*/
        saveEndptr = buffer;
        while (*saveEndptr != 10) {
            if (strtol(saveEndptr, &endptr, 10) == 0) {
                break;
            }
            saveEndptr = endptr;
            *length += 1;
        }

        /*Crear malloc int, agregar y pasar dir*/
        auxparr = malloc(sizeof(int) * (*length));
        saveEndptr = buffer;
        while (*saveEndptr != 10) {
            numero = strtol(saveEndptr, &endptr, 10);
            if (numero == 0) {
                break;
            }
            auxparr[j] = numero;
            saveEndptr = endptr;
            j++;
        }
        *parr = auxparr;

        /*Crear malloc char, agregar y pasar dir*/
        auxop = malloc(sizeof(char) * lengthChars);
        for (i = 0; i < lengthChars; i++) {
            auxop[i] = buffer[strlen(buffer) - lengthChars + i];
            if (i == lengthChars - 1) auxop[i] = 0;
        }
        *op = auxop;
    }
}

void feature5(FILE *fout, int *parr, int length, char *op) {
    char *avg = "avg";
    char *max = "max";
    char *min = "min";
    int resultado;
    int i;

    if (strcmp(op, avg) == 0) {
        int promedio = 0;
        for (i = 0; i < length; i++) {
            promedio += parr[i];
        }
        promedio /= length;
        fprintf(fout, "\n%d", promedio);
    }

    if (strcmp(op, max) == 0) {
        int max = parr[0];
        for (i = 1; i < length; i++) {
            if (parr[i] > max) {
                max = parr[i];
            }
        }
        fprintf(fout, "\n%d", max);
    }

    if (strcmp(op, min) == 0) {
        int min = parr[0];
        for (i = 1; i < length; i++) {
            if (parr[i] < min) {
                min = parr[i];
            }
        }
        fprintf(fout, "\n%d", min);
    }

    free(parr);
    free(op);
}

void feature6(FILE *fin, struct Obj_t *pobj) {
    char buffer[128];
    char *endptr;
    char *status = NULL;
    char *token;
    char sep[2] = ",";
    char *rest;
    int i;

    status = fgets(buffer, sizeof(buffer), fin);
    if (status != NULL) {
        token = strtok(buffer, sep);
        char *auxname = malloc(sizeof(char) * strlen(token));
        for (i = 0; i < strlen(token); i++) {
            auxname[i] = token[i];
        }
        pobj->nombre = auxname;
        token = strtok(NULL, ",");
        pobj->cedula = strtol(token, &endptr, 10);
    }
}