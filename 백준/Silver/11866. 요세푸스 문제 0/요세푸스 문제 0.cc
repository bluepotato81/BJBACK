#include <stdio.h>

int main() {
    int a, b;
    scanf("%d %d", &a, &b);

    int j[a];
    for(int i = 0; i < a; i++) {
        j[i] = 1;
    }

    int c = 0;
    int eliminated_count = 0;
    printf("<");

    while(eliminated_count < a - 1) {
        int step_count = 0;
        while(step_count < b) {
            if(j[c] == 1) {
                step_count++;
            }
            if(step_count < b) {
                c = (c + 1) % a;
            }
        }
        j[c] = 0;
        printf("%d, ", c + 1);
        eliminated_count++;
        while(j[c] == 0) {
            c = (c + 1) % a;
        }
    }

    for(int i = 0; i < a; i++) {
        if(j[i] == 1) {
            printf("%d>", i + 1);
            break;
        }
    }

    return 0;
}
