#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include "include/interpreter.h"
#include "include/read_file.h"
#include "include/error_handle.h"


int main(int argc, char* argv[]) {
    if (argc == 2) {
        interpret_program(argv[1]);
    } else if (argc == 3) {
        if (argv[1] == "t") {
            char* program = read_file(argv[2]);
        }
    }
}
