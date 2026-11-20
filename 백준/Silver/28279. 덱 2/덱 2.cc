#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    int de[2000000];
    int in, value;
    int deend = 1000000, destart = 1000000;

    for (int i = 0; i < N; i++) {
        scanf("%d", &in);
        
        if (in == 1) {
            // Push to front
            scanf("%d", &value);
            de[--destart] = value;
        } else if (in == 2) {
            // Push to back
            scanf("%d", &value);
            de[deend++] = value;
        } else if (in == 3) {
            // Pop from front
            if (deend == destart) {
                printf("-1\n");
            } else {
                printf("%d\n", de[destart++]);
            }
        } else if (in == 4) {
            // Pop from back
            if (deend == destart) {
                printf("-1\n");
            } else {
                printf("%d\n", de[--deend]);
            }
        } else if (in == 5) {
            // Size of deque
            printf("%d\n", deend - destart);
        } else if (in == 6) {
            // Is deque empty?
            if (deend == destart) {
                printf("1\n");
            } else {
                printf("0\n");
            }
        } else if (in == 7) {
            // Front element
            if (deend == destart) {
                printf("-1\n");
            } else {
                printf("%d\n", de[destart]);
            }
        } else if (in == 8) {
            // Back element
            if (deend == destart) {
                printf("-1\n");
            } else {
                printf("%d\n", de[deend - 1]);
            }
        }
    }

    return 0;
}
