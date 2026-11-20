#include <stdio.h>


int main() {
    int n;
    scanf("%d", &n);
    int a[501]={0,};

    for(int i=0; i<n; i++) {
        int al;
        scanf("%d", &al);
        scanf("%d", &a[al]);
    }

    int dp[501]={0,};
    int max=0;
    for(int i=1; i<=500; i++) {
        dp[i]=1;
        for (int j=1; j<i; j++) {
            if (a[j]!=0 && a[j]<a[i]) {
                if (dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                }
            }
        }
        if (dp[i] > max) {
            max = dp[i];
        }
    }

    printf("%d", n-max);


    return 0;
}
