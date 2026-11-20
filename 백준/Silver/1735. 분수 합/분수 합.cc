#include <stdio.h>

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int lcm(int a, int b) {
    if (a == 0 || b == 0) return 0; 
    return (a / gcd(a, b)) * b;
}


int main() {
    int n, m, o, p;
    scanf("%d %d", &n, &m);
    scanf("%d %d", &o, &p);

    if (m == 0 || p == 0) {
        printf("Error: m or p should not be zero.\n");
        return 1;
    }

    int big = lcm(m, p);

    int top_big = n * (big / m) + o * (big / p);

    int L = gcd(top_big, big);

    top_big /= L;
    big /= L;
    
    printf("%d %d\n", top_big, big);

    return 0;
}
