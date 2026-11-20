#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int stack[n];
    int stacklen = 0;
    int max = 0;
    int nocheck = 0;

    char operations[2 * n];
    int op_index = 0;

    int input[n];
    for(int i=0; i<n; i++) {
        scanf("%d", &input[i]);
    }

    for (int i = 0; i < n; i++) {
        int a;
        a=input[i];
        if (max < a) {
            for (int j = max + 1; j <= a; j++) {
                stack[stacklen++] = j;
                operations[op_index++] = '+';
            }
            max = a;
        }

        if (stacklen == 0 || stack[stacklen - 1] != a) {
            nocheck = 1;
            break;
        } else {
            stacklen--;
            operations[op_index++] = '-';
        }
    }

    if (nocheck == 1) {
        printf("NO\n");
    } else {
        for (int i = 0; i < op_index; i++) {
            printf("%c\n", operations[i]);
        }
    }

    return 0;
}
