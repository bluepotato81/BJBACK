#include <stdio.h>
#include <string.h>

#define MAX_LEN 1000001

int main() {
    char string[MAX_LEN];
    char bomb[37];

    scanf("%s", string);
    scanf("%s", bomb);
    
    size_t len = strlen(string);
    size_t bomblen = strlen(bomb);
    
    char stack[MAX_LEN];
    int stacklen = 0;

    for (size_t i = 0; i < len; i++) {
        stack[stacklen++] = string[i];

        if (stacklen >= bomblen && strncmp(&stack[stacklen - bomblen], bomb, bomblen) == 0) {
            stacklen -= bomblen;
        }
    }

    stack[stacklen] = '\0';

    if (stacklen == 0) {
        printf("FRULA");
    } else {
        printf("%s", stack);
    }

    return 0;
}
