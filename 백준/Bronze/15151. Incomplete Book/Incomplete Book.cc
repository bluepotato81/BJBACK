#include <stdio.h>

int main() {
    int k, d;
    scanf("%d %d", &k, &d);

    long long as=0;
    int num=0;
    while(as<=d) {
        as+=k;
        k*=2;
        num++;
    }

    printf("%d", num-1);

    return 0;
}
