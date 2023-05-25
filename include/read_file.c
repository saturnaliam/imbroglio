#include "read_file.h"
#include "error_handle.h"
#include <stdio.h>

char* read_file(char* file_name) {
    FILE* file;
    if ((file = fopen(file_name, "r")) == NULL) {
        die("Cannot open file.");
    }
}
