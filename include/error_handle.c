#include "error_handle.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * \brief Prints an error and exits the program
 *
 * \param error The error to print out
 */
void die(char* error, char* extra_values) {
    printf("Error: %s %s", error, extra_values);

    exit(1);
}
