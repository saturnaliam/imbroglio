#include "error_handle.h"
#include <stdlib.h>
#include <stdio.h>

void die(char* error) {
    printf(error);

    exit(1);
}
