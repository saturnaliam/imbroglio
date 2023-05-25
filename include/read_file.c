#include "read_file.h"
#include "error_handle.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* read_file(char* file_name) {
    FILE* file;
    if ((file = fopen(file_name, "r")) == NULL) {
        die("Cannot open file.");
    }

    long offset_end = ftell(file);
    size_t file_size = (size_t)offset_end;

    rewind(file);
    char* file_buffer = malloc(file_size);

    fread(file_buffer, 1, file_size, file);
    for (int i = 0; i < strlen(file_buffer); i++) {
        printf("d");
    }

    free(file_buffer);
    return ":d";
}
