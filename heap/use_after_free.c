#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *buffer = (char *)malloc(32);
    strcpy(buffer, "Hello, World!");
    printf("Before Free: %s\n", buffer);

    free(buffer);  // Free the buffer

    // UAF vulnerability
    printf("After Free: %s\n", buffer);

    return 0;
}