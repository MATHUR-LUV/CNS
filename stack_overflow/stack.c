#include <stdio.h>
#include <string.h>

void vulnerable_function(char *input) {
    char buffer[64];
    strcpy(buffer, input);
    printf("Input: %s\n", buffer);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <input>\n", argv[0]);
        return 1;
    }
    vulnerable_function(argv[1]);
    return 0;
}

// gcc -fno-stack-protector -z execstack -o stack_overflow stack_overflow.c
// python -c 'print("A" * 80)' | ./stack_overflow