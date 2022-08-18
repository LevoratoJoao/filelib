#include <stdio.h>
#include <stdlib.h>
#include "filelib.h"

/**
 * @brief Create a file
 *
 * @param file
 * @param name
 * @return FILE*
 */
FILE *cr_file(char *name) {
    FILE *file = fopen(name, "w+");
    if (file == NULL) {
        printf("error: fail to create file\n");
        return NULL;
    }
    return file;
}

/**
 * @brief Close the file
 *
 * @param file
 * @param name
 * @return void*
 */
void cl_file(FILE *file, char *name) {
    fclose(file);
}

FILE *op_file(char *name) {
    FILE *file = fopen(name, "r+");
    if (file == NULL)
    {
        printf("error: fail to open file\n");
        return NULL;
    }
    else
        return file;
}

/**
 * @brief Read all the file and returns the number of lines in this file
 *
 * @param file
 * @param name
 * @return int*
 */
int ln_file(FILE *file) {
    int ln = 1;
    char c;
    //(c = fgetc(file)) != EOF
    while (1) {
        fscanf(file, "%c", &c);
        if (c == '\n')
            ln++;
        if (feof(file))
            break;
    }
    fclose(file);
    return ln;
}

