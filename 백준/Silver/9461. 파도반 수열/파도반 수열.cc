#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    long long padovan[100];

    padovan[0]=1;
    padovan[1]=1;
    padovan[2]=1;

    for(int i=3; i<100; i++) {
        padovan[i]=padovan[i-2]+padovan[i-3];
    }

    for(int i=0; i<n; i++) {
        int k;
        scanf("%d", &k);
        printf("%lld\n", padovan[k-1]);

    }

    return 0;
}
