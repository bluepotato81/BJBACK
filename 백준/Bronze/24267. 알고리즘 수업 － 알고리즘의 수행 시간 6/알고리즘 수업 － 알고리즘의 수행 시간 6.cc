#include <stdio.h>

int main() {
    long long a;
    scanf("%lld", &a);
    long long tot=0;
    for(long long i=a-1; i>0; i--) {
        tot+= i*(i-1)/2;
    }
    printf("%lld\n%lld", tot, 3);

    return 0;
}
