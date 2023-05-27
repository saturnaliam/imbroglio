#include "read_file.h"
#include "transpile.h"
#include "error_handle.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define ADD 43
#define INPUT 44
#define SUB 45
#define OUT 46
#define LEFT 60
#define RIGHT 62

/**
 * \brief Removes the file extension from a program's file
 *
 * \param file_name The file's raw name
 */
void remove_extension(char* file_name) {
    for (int i = 0; i < strlen(file_name); i++) {
        if (file_name[i] == '.') {
            file_name[i] = '\0';
        }
    }
}

/**
 * \brief Turns the progam into brainfuck
 *
 * \param program The program in imbroglio form
 * \param output_file The file name to be output
 */
void transpile(char* program, char* output_file) {
    char* transpiled = malloc(strlen(program) * 3); // times three to account for worst case (all move threes)
    int transpiled_index = 0;
    printf("%d\n", strlen(program));

    for (int i = 0; i < strlen(program); i++) {
        char c = program[i];
        int x = 1; // idk how to name this but its the amount of times c gets added

        switch (c) {
            case 's':
                c = SUB;
                break;

            case 'S':
                c = SUB;
                x = 3;
                break;

            case 'a':
                c = ADD;
                break;

            case 'A':
                c = ADD;
                x = 3;
                break;

            case 'r':
                c = RIGHT;
                break;

            case 'R':
                c = RIGHT;
                x = 3;
                break;

            case 'l':
                c = LEFT;
                break;

            case 'L':
                c = LEFT;
                x = 3;
                break;

            case 'p':
                c = OUT;
                break;

            case 'g':
                c = INPUT;
                break;
        }

        for (int j = 1; j <= x; j++) {
            transpiled[transpiled_index++] = c;
        }
    }

    transpiled[transpiled_index] = '\0';
    transpiled = realloc(transpiled, transpiled_index);

    remove_extension(output_file);

    FILE* file;

    strcat(output_file, ".bf");
    file = fopen(output_file, "w");

    if (file == NULL) {
        die("error writing to file", output_file);
    }


    fprintf(file, "%s", transpiled);
    fclose(file);
}
