#include <stdio.h>
#include <vector>

using namespace std;


int pop[10001];

vector<vector<int>> r;
int lev[10001]={-1,};

void structure(int see, int curlev) {
    lev[see]=curlev;
    for(int k: r[see]) {
        if(lev[k]==0) {
            structure(k, curlev+1);
        }
    }
}

int dp[10001][2]={0, };

void dfs(int pos) {
    dp[pos][0]=0;
    dp[pos][1]=pop[pos];

    for(int k:r[pos]) {
        if(lev[k]>lev[pos]) {
            dfs(k);
            dp[pos][1]+=dp[k][0];
            dp[pos][0]+=max(dp[k][0], dp[k][1]);
        }

    }
}

int check[10001]={0, };

void rec(int pos, int in) {
    if(in==0) {
        for(int k:r[pos]) {
            if(lev[k]>lev[pos]) {
                if(dp[k][0]>dp[k][1]) {
                    rec(k, 0);
                }
                else {
                    rec(k,1);
                }
            }
        }
    }
    else {
        check[pos]=1;
        for(int k:r[pos]) {
            if(lev[k]>lev[pos]) {
                rec(k,0);
            }
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    for(int i=1; i<=n;i++) {
        scanf("%d", &pop[i]);
    }

    r.resize(n+1);

    for(int i=0; i<n-1;i++) {
        int a,b;
        scanf("%d %d", &a, &b);
        r[a].push_back(b);
        r[b].push_back(a);
    }
    structure(1,1);

    dp[1][0]=0;
    dp[1][1]=pop[1];

    dfs(1);

    printf("%d\n", max(dp[1][0], dp[1][1]));

    if(dp[1][0]>dp[1][1]){
        rec(1, 0);
    }
    else {
        rec(1,1);
    }

    for(int i=1;i<=n; i++) {
        if(check[i]==1) {
            printf("%d ", i);
        }
    }


    return 0;
}
