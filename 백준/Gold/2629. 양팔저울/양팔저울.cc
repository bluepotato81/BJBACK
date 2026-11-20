#include <stdio.h>

int n;
int weight[31];
int m;
int weightmax;
int dp[40001];

int main() {
    scanf("%d", &n);


    for(int i=0; i<n; i++) {
        scanf("%d", &weight[i]);
        weightmax+=weight[i];
    }

    for(int i=0; i<weightmax; i++) {
        dp[i]=0;
    }

    dp[0]=1;
    for(int i=0;i<n; i++) {
        for(int j=weightmax;j>=0; j--) {
            if(dp[j]) {
                dp[j+weight[i]]=1;
            }
        }
        for(int j=0; j<=weightmax;j++) {
            if(dp[j]) {
                int val;
                if(j-weight[i]<0) {
                    val=weight[i]-j;
                }
                else {
                    val=j-weight[i];
                }
                dp[val]=1;
            }
        }
    }

    scanf("%d", &m);

    for(int i=0; i<m; i++) {
        int k;
        scanf("%d", &k);
        if(dp[k]) {
            printf("Y ");
        }
        else {
            printf("N ");
        }
    }


    return 0;
}
