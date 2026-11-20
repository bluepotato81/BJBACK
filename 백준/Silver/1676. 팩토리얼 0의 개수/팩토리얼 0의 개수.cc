#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int count = 0;
    for (int i = 5; n / i >= 1; i *= 5) {
        count += n / i;
    }

    printf("%d\n", count);
    return 0;
}
