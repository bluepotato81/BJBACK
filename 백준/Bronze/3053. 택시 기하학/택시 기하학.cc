#include <stdio.h>

double pi = 3.14159265358979;

int main() {
    int r;
    scanf("%d", &r);

    printf("%f\n", r*r*pi);
    printf("%f\n", r*r*2.0);

    return 0;
}
