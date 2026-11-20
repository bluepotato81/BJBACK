#include <stdio.h>

int main() {
    int a;
    scanf("%d", &a);


    long long f=1;
    for(int i=1; i<=a; i++) {
        f*=i;
    }

    printf("%lld", f);

    return 0;
}
