#include "Safe_input.h"
#include <stdio.h>

int safe_int_input(int *out) {
    char buffer[100];
    char extra;
    
    while (1) {
        if (!fgets(buffer, sizeof(buffer), stdin))
            return 0; // error

        if (sscanf(buffer, " %d %c", out, &extra) == 1)
            return 1; // succesfull

        printf("Error! Enter an integer:");
    }
}

