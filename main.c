#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include "include/read_file.h"


int main() {
    char* hi = read_file("instructions.ism");
    printf("%s", hi);
}
