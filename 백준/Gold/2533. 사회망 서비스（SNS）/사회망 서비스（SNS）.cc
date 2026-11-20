#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> edges;

int dp[1000001][2]={0, };
int visited[1000001]={0,};

void dfs(int pos) {
    dp[pos][0]=0;
    dp[pos][1]=1;
    visited[pos]=1;
    for(int k:edges[pos]) {
        if(visited[k]) {
            continue;
        }
        dfs(k);
        dp[pos][0]+=dp[k][1];
        dp[pos][1]+=min(dp[k][0], dp[k][1]);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    edges.resize(n+1);

    for(int i=0; i<n-1;i++) {
        int a,b;
        scanf("%d %d", &a, &b);

        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    dfs(1);

    printf("%d", min(dp[1][0], dp[1][1]));



    return 0;
}
