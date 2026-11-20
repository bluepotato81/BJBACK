#include <iostream>
#include <deque>

using namespace std;

int main() {
    int n,k;
    scanf("%d %d", &n, &k);

    int cow[n+1];
    for(int i=1;i<=n;i++) {
        scanf("%d", &cow[i]);
    }


    long long dp[n+1];
    long long com[n+1];
    deque<long long> dq;

    com[1]=cow[1];
    for(int i=2;i<=n;i++) {
        com[i]=com[i-1]+cow[i];
    }

    dp[0]=0;
    com[0]=0;
    for(int i=1; i<=k;i++) {
        dp[i]=com[i];
        dq.push_back(i);
        while(!dq.empty()&& com[i]-dp[i-1]<=com[dq.back()]-dp[dq.back()-1]) {
            dq.pop_back();
        }
        dq.push_back(i);
    }


    for(int i=k+1; i<=n; i++) {
        while(!dq.empty() && dq.front()<i-k) {
            dq.pop_front();
        }
        //printf("%d ", dq.front());
        dp[i]=max(dp[i-1], com[i]-com[dq.front()]+dp[dq.front()-1]);
        while(!dq.empty()&& com[i]-dp[i-1]<=com[dq.back()]-dp[dq.back()-1]) {
            dq.pop_back();
        }
        dq.push_back(i);

    }
    //printf("\n");

    /*for(int i=1; i<=n;i++) {
        printf("%d ", dp[i]);
    }*/

    printf("%lld", dp[n]);



    return 0;
}
