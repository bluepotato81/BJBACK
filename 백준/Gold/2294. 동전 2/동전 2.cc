#include <stdio.h>

int dp[10001];
int val[100];

void cal(int coinval, int k) {
    for(int i=coinval;i<=k;i++) {
        dp[i]= dp[i]>=dp[i-coinval]+1 ? dp[i-coinval]+1 : dp[i];
    }
}

int main() {
    int n,k;
    scanf("%d %d", &n, &k);

    for(int i=0; i<n;i++) {
        scanf("%d", &val[i]);
    }
    for(int i=0; i<=k;i++) {
        dp[i]=1000001;
    }

    dp[0]=0;

    for(int i=0; i<n;i++) {
        cal(val[i], k);
    }

    if(dp[k]==1000001) {
        printf("-1");
    }
    else {
        printf("%d", dp[k]);
    }



    return 0;
}
