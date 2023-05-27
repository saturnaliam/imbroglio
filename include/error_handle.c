#include "error_handle.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

/**
 * \brief Closes the program and prints an error
 * \warning may be black magic
 *
 * \param error The main error message
 * \param ... Any additional parameters to support the error
 * \author dxiv https://stackoverflow.com/users/5538420/dxiv
 */
void die(char* error, ...) {
    va_list args;
    va_start(args, error);
    int length = vsnprintf(NULL, 0, error, args);
    va_end(args);

    if (length < 0) exit(1);

    char message[length + 1];
    va_start(args, error);
    vsnprintf(message, length + 1, error, args);
    va_end(args);
    printf("\x1b[31mError: %s.\x1b[37m", message);

    exit(1);
}
