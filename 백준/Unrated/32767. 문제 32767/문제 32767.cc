#include <stdio.h>
#include <math.h>


int len(double a) {
    a = fabs(a); // Ensure positive for digit counting
    long long k = (long long)round(a); // Round to nearest integer for better precision
    int l = 1;
    while (k >= 10) {
        k /= 10;
        l++;
    }
    return l;
}

int main() {
    double res;
    scanf("%lf", &res);

    char op;
    scanf(" %c", &op); // Note the space before %c to ignore leftover whitespace
    double inp;
    scanf("%lf", &inp);

    if (op == '+') {
        res += inp;
    } else if (op == '-') {
        res -= inp;
    } else if (op == '*') {
        res *= inp;
    } else {
        res /= inp;
    }
    scanf(" %c", &op); // Again, handle whitespace correctly
    scanf("%lf", &inp);

    if (op == '+') {
        res += inp;
    } else if (op == '-') {
        res -= inp;
    } else if (op == '*') {
        res *= inp;
    } else {
        res /= inp;
    }

    int o = len(res);
    //printf("%lf\n", res);
    //printf("%d\n", o);

    for (int i = 0; i < 17; i++) {
        printf("=");
    }
    printf("\n|SASA CALCULATOR|\n");
    printf("|");

    for (int i = 0; i < 11 - o; i++) {
        printf(" ");
    }

    printf("%.3lf|\n", res);

    for (int i = 0; i < 17; i++) {
        printf("-");
    }

    printf("\n");

    printf("|               |\n| AC         /  |\n| 7  8  9    *  |\n| 4  5  6    -  |\n| 1  2  3    +  |\n|    0  .    =  |\n=================");

    return 0;
}
