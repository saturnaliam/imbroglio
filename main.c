#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include "include/interpreter.h"
#include "include/read_file.h"
#include "include/error_handle.h"
#include "include/transpile.h"

int main(int argc, char* argv[]) {
    if (argc == 2) {
        interpret_program(argv[1]);
    } else if (argc == 3) {
        if (strcmp(argv[1], "-t") == 0) {
            char* program = read_file(argv[2]);
            transpile(program, argv[2]);

            free(program);
        }
    }
}
