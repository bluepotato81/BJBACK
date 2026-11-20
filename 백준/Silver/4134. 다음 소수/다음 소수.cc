#include <stdio.h>
#include <math.h>

int is_prime(long long n) {
    if (n <= 1) return 0;
    if (n <= 3) return 1;
    if (n % 2 == 0 || n % 3 == 0) return 0;
    for (long long i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return 0;
    }
    return 1;
}

int main() {
    long long a;
    scanf("%lld", &a);

    for (int i = 0; i < a; i++) {
        long long k;
        scanf("%lld", &k);
        long long start = k;

        while (!is_prime(start)) {
            start++;
        }

        printf("%lld\n", start);
    }
    return 0;
}
