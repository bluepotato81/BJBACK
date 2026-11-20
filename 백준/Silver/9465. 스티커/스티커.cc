#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int t;
    scanf("%d", &t);

    for(int i=0; i<t; i++) {
        int n;
        scanf("%d", &n);
        int sticker[2][n];
        for(int j=0; j<2; j++) {
            for(int k=0; k<n; k++) {
                scanf("%d", &sticker[j][k]);
            }
        }
        if(n==1) {
            if(sticker[0][0]>sticker[1][0]) {
                printf("%d\n", sticker[0][0]);
            }
            else {
                printf("%d\n", sticker[1][0]);
            }
            continue;
        }

        int dp[2][n];
        dp[0][0] = sticker[0][0];
        dp[1][0] = sticker[1][0];
        dp[0][1] = sticker[1][0] + sticker[0][1];
        dp[1][1] = sticker[0][0] + sticker[1][1];

        for(int i = 2; i < n; i++) {
            dp[0][i] = max(dp[1][i-1], dp[1][i-2]) + sticker[0][i];
            dp[1][i] = max(dp[0][i-1], dp[0][i-2]) + sticker[1][i];
        }
        printf("%d\n", max(dp[0][n-1], dp[1][n-1]));

    }

    return 0;
}
