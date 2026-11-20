#include <stdio.h>

int memory[101];
int cost[101];

int dp[101][10001];

int main() {
	int n,m;
	scanf("%d %d", &n, &m);


	for(int i=1; i<=n; i++) {
		scanf("%d", &memory[i]);
	}

	int costcom=0;
	for(int i=1; i<=n; i++) {
		scanf("%d", &cost[i]);
		costcom+=cost[i];
	}

	for(int i=1; i<=n; i++) {
        for(int j=0; j<=costcom; j++) {
            if(j-cost[i]>=0) {
                int k=dp[i-1][j-cost[i]]+memory[i];
                if(k>dp[i][j]) {
                    dp[i][j]=k;
                }
            }
            if(dp[i-1][j]>dp[i][j]) {
                dp[i][j]=dp[i-1][j];
            }
        }
	}

	for(int i=0; i<=costcom; i++) {
        if(dp[n][i]>=m) {
            printf("%d", i);
            break;
        }
	}

	return 0;
}

