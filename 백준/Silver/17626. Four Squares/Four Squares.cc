#include <stdio.h>
#include <math.h>

#define INF 100000000  

int add[50001];

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i <= n; i++) {
        add[i] = INF;
    }
    add[0] = 0;
    for (int i = 1; i*i <= n; i++) {
        int square = i*i;
        for (int j = square; j <= n; j++) {
            if (add[j - square] + 1 < add[j]) {
                add[j] = add[j - square] + 1;
            }
        }
    }

    printf("%d", add[n]);
    return 0;
}
