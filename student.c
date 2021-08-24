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