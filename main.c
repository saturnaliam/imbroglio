#include <stdio.h>
#include "include/keywords.h"


int main() {
    for (int i = 0; i < 12; i++) {
        printf("%s\n", KEYWORDS[i].identifier);
    }
}
