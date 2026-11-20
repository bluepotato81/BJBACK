#include <stdio.h>

int list[1000001];

int main() {
    int n;
    scanf("%d", &n);

    list[1]=1;
    list[2]=2;
    for(int i=3; i<=n; i++) {
        list[i]=(list[i-1]+list[i-2])%15746;
    }
    printf("%d", list[n]);

    return 0;
}
