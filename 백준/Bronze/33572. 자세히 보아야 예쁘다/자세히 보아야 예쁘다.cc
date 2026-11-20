#include <stdio.h>

int main() {
    int n;
    long long m;
    scanf("%d %lld", &n, &m);

    long long a=0;
    long long k;
    for(int i=0; i<n;i++) {
        scanf("%lld", &k);
        a+=k-1;
    }

    if(m<=a) {
        printf("DIMI");
    }
    else {
        printf("OUT");
    }
    return 0;
}
