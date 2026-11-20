#include <stdio.h>

typedef struct{
    int val;
    int befin;
}num;

int main() {
    int n;
    scanf("%d", &n);
    int nums[n];
    for(int i=0; i<n; i++) {
        scanf("%d", &nums[i]);
    }
    num dp[n];
    for(int i=0; i<n; i++) {
        dp[i].val=1;
        dp[i].befin=-1;
    }
    for(int i=1; i<n; i++) {
        for(int j=0; j<i; j++) {
            if(nums[i]>nums[j]&&dp[i].val<dp[j].val+1) {
                dp[i].val=dp[j].val+1;
                dp[i].befin=j;
            }
        }
    }

    int point=0;
    int maxlen=dp[0].val;
    for(int i=1; i<n; i++) {
        if(dp[i].val>maxlen) {
            maxlen=dp[i].val;
            point=i;
        }
    }

    int path[maxlen];
    int curin=0;

    while(point>=0) {
        path[curin++]=nums[point];
        point=dp[point].befin;
    }

    printf("%d\n", maxlen);

    for(int i=maxlen-1;i>=0;i--) {
        printf("%d ", path[i]);
    }

    return 0;
}
