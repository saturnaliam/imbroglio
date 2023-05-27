#include "read_file.h"
#include "error_handle.h"
#include "keywords.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * \brief Opens a file and reads it
 *
 *
 * \param file_name The file to open
 * \return The formatted file string
 */
char* read_file(char* file_name) {
    FILE* file;
    if ((file = fopen(file_name, "r")) == NULL) {
        die("cannot open file \"%s\"", file_name);
    }

    // getting the length of the file so we can read it all properly
    int eof = fseek(file, 0L, SEEK_END);
    long offset_end = ftell(file);
    size_t file_size = (size_t)offset_end;

    rewind(file);

    char* file_buffer = malloc(file_size); // reading the file into the buffer
    fread(file_buffer, 1, file_size, file);

    char* formatted = format_file(file_buffer);

    free(file_buffer);

    return formatted;
}

/**
 * \brief Formats the output of the file that was read
 *
 * \param program The file to be formatted
 * \return The formatted file
 */
char* format_file(char* program) {
    // the program w/o the spaces, comments, and newlines
    char* stripped = malloc(strlen(program));

    int commented = 0; // need them all on different lines or i segfault lmao
    int stripped_index = 0;
    int formatted_index = 0;
    int line_index = 0;

    // Removing spaces and comments
    for (int i = 0; i < strlen(program); i++) {
        char c = program[i];

        if (!commented) {
            if (c <= 32 && c != 10) { // checking if the character is a special character
                continue;
            } else if (c == ';') { // checking if theres a comment
                commented = 1;
                continue;
            } else {
                stripped[stripped_index] = c;
                stripped_index++;
            }
        } else {
            if (c == 10) {
                commented = 0;
                stripped[stripped_index] = 10;
                stripped_index++;
            }
        }
    }

    // reallocating memory
    // im writing this about five hours later and wtf like no shit ?? ofc that reallocates memory dumbass
    stripped = realloc(stripped, stripped_index);

    char* formatted = malloc(strlen(stripped));

    char* current_line = malloc(strlen(stripped));
    int line_num = 1;
    int opened_loop = 0;

    for (int i = 0; i < strlen(stripped); i++) {
        int identified = 0;

        char c = stripped[i];
        current_line[line_index] = c;
        line_index++;

        if (c == 10) {
            if (strcmp(current_line, "\n") != 0) {
                current_line[line_index - 1] = 0;

                for (int j = 0; j < 12; j++) {
                    if (strcmp(KEYWORDS[j].identifier, current_line) == 0 ) {
                        formatted[formatted_index] = KEYWORDS[j].value;
                        formatted_index++;
                        identified = 1;

                        if (KEYWORDS[j].value == ']') {
                            if (opened_loop) {
                                opened_loop = 0;
                            } else {
                                die("loop ended without beginning on line %d", line_num);
                            }
                        } else if (KEYWORDS[j].value == '[') {
                            if (opened_loop) {
                                die("loop on line %d began without ending previous loop", line_num);
                            } else {
                                opened_loop = 1;
                            }
                        }
                        break;
                    }
                }

                if (!identified) {
                    die ("unknown keyword on line %d", line_num);
                }
            }

            memset(current_line, 0, strlen(current_line));
            line_index = 0;
            line_num++;
        }
    }

    if (opened_loop) {
        die("unclosed loop");
    }

    formatted = realloc(formatted, formatted_index);

    free(current_line);
    free(stripped);
    return formatted;
}
