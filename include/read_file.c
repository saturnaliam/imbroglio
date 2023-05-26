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
        die("cannot open file", file_name);
    }

    int eof = fseek(file, 0L, SEEK_END);
    long offset_end = ftell(file);
    size_t file_size = (size_t)offset_end;

    rewind(file);
    char* file_buffer = malloc(file_size);


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
    char* compressed = malloc(strlen(program));

    int commented, formatted_index = 0;

    // Removing spaces and comments
    for (int i = 0; i < strlen(program); i++) {
        char c = program[i];

        if (!commented) {
            if (c == ' ') {
                continue;
            } else if (c == ';') {
                commented = 1;
                continue;
            } else {
                compressed[formatted_index] = c;
                formatted_index++;
            }
        } else {
            if (c == '\n') {
                commented = 0;
            }

            continue;
        }
    }

    // Converting keywords into their compressed format
    compressed = realloc(compressed, formatted_index);

    char* formatted = malloc(strlen(compressed));

    char current_keyword[4];
    current_keyword[3] = '\0';

    formatted_index = 0;

    for (int i = 0; i < strlen(compressed); i++) {
        int identified = 0;
        current_keyword[i % 3] = compressed[i];

        if (i % 3 == 2) {
            for (int j = 0; j < 12; j++) {
                if (!strcmp(KEYWORDS[j].identifier, current_keyword)) {
                    identified = 1;
                    formatted[formatted_index] = KEYWORDS[j].value;
                    formatted_index++;
                    break;
                }
            }

            if (!identified) {
                die("unknown identifier", current_keyword);
            }
        }
    }

    formatted = realloc(formatted, formatted_index);

    free(compressed);
    return formatted;
}
