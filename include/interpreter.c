#include "interpreter.h"
#include "error_handle.h"
#include "read_file.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAPE_SIZE 10

/**
 * \brief Runs the program
 *
 * \param file The file containing the program
 */
void interpret_program(char *file) {
    char* program = read_file(file);

    int tape[TAPE_SIZE] = { [0 ... TAPE_SIZE - 1] = 0 };
    int ptr, looping, loop_index, loop_ptr, prev_print = 0; // 🤓 this is bad practice!! stfu nerd

    for (int i = 0; i < strlen(program); i++) {
        char c = program[i];

        // truncation
        if (ptr >= TAPE_SIZE) ptr -= TAPE_SIZE;
        if (ptr < 0) ptr += TAPE_SIZE;
        if (tape[ptr] >= 128) tape[ptr] -= 128;
        if (tape[ptr] < 0) tape[ptr] += 128;

        switch (c) {
            case 'a':
                tape[ptr]++;
                break;

            case 's':
                tape[ptr]--;
                break;

            case 'A':
                tape[ptr] += 3;
                break;

            case 'S':
                tape[ptr] -= 3;
                break;

            case 'r':
                ptr++;
                break;

            case 'l':
                ptr--;
                break;

            case 'R':
                ptr += 3;
                break;

            case 'L':
                ptr -= 3;
                break;

            case 'p':
                if (c < 32) break; // making sure special ascii chars cant be used (exclusing carriage return and newline)

                printf("%c", tape[ptr]);

                prev_print = 1;
                break;

            case 'g':
                char g;

                if (prev_print) printf("\n"); // bad code but idrc
                scanf(" %c", &g);

                tape[ptr] = (g >= 32 ? g : 0);

                break;

            case '[':
                if (tape[ptr] > 0) {
                    looping = 1;
                    loop_ptr = ptr;
                    loop_index = i;
                }

                break;

            case ']':
                if (looping) {
                    if (tape[loop_ptr] > 0) {
                        ptr = loop_ptr;
                        i = loop_index - 1;
                    } else {
                        looping = 0;
                    }
                }

                break;
        }
    }

    free(program); // FREE MY MAN PROGRAM
}
