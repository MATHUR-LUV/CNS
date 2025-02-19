#include <stdio.h>
#include <stdlib.h>

int main() {
    char *buffer = (char *)malloc(32);
    free(buffer);  // First free
    free(buffer);  // Double free

    return 0;
}