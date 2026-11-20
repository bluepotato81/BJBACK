#include <iostream>
#include <vector>
#include <deque>

using namespace std;


vector<long long> bri;

int main() {
    int n,d;
    scanf("%d %d", &n, &d);

    bri.resize(n+1);

    int allmin=0;
    for(int i=1; i<=n;i++) {
        scanf("%lld", &bri[i]);
        if(bri[i]>=0) {
            allmin++;
        }
    }

    if(!allmin) {
        long long mm=-1000000000000000;

        for(int i=1;i<=n;i++) {
            mm=max(mm, (long long)bri[i]);
        }
        printf("%lld", mm);
        return 0;
    }

    long long dp[n+1];
    deque<long long> dq;
    dp[1]=bri[1];
    dq.push_back(1);

    for(int i=2; i<=n; i++) {
        while(!dq.empty() && dq.front()<i-d) {
            dq.pop_front();
        }

        dp[i]=bri[i];

        long long see=dp[dq.front()];

        if(see>0) {
            dp[i]=max(dp[i], see+bri[i]);
        }

        else {
            dp[i]=max(dp[i], bri[i]);
        }

        while(!dq.empty()&& dp[i]>=dp[dq.back()]) {
            dq.pop_back();
        }

        dq.push_back(i);
    }

    /*for(int i=1; i<=n; i++) {
        printf("%d ", dp[i]);
    }
    printf("\n");*/
    long long m=-1000000000000000;

    for(int i=1;i<=n;i++) {
        m=max(m, dp[i]);
    }
    printf("%lld", m);


    return 0;
}
