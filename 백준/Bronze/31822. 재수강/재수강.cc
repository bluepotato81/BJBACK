#include <stdio.h>
#include <string.h>

int main() {
    char target[11];
    scanf("%10s", target);
    int n;
    scanf("%d", &n);
    int matchCount = 0;

    for (int i = 0; i < n; i++) {
        char current[11];
        scanf("%10s", current);
        int matches = 1;
        for (int j = 0; j < 5; j++) {
            if (target[j] != current[j]) {
                matches = 0;
                break;
            }
        }

        if (matches) {
            matchCount++;
        }
    }

    printf("%d\n", matchCount);

    return 0;
}
