#include <stdio.h>

int main() {
    int n;

    scanf("%d", &n);

    int list[n];

    list[0]=1;
    list[1]=3;

    for(int i=2; i<n; i++) {
        list[i]=(list[i-2]*2+list[i-1])%10007;
    }

    printf("%d", list[n-1]);

    return 0;
}
