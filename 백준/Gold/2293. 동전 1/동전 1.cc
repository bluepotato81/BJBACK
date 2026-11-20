#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n,k;
    scanf("%d %d", &n, &k);

    int coin[n];
    int len=0;
    int a;
    for(int i=0;i<n; i++) {
        scanf("%d", &a);
        if(a<=k) {
            coin[len]=a;
            len++;
        }
    }

    qsort(coin, len, sizeof(int), compare);

    int dp[k+1];
    dp[0]=1;
    for(int i=1; i<=k; i++) {
        dp[i]=0;
    }


    for(int i=0; i<len; i++) {
        for(int j=coin[i]; j<=k; j++) {
            dp[j]+=dp[j-coin[i]];
        }
    }

    printf("%d", dp[k]);

    return 0;
}
