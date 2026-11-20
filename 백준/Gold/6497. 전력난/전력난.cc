#include <stdio.h>
#include <limits.h>
#include <queue>

using namespace std;

int main() {
    while(1) {
        int m,n;
        scanf("%d %d", &m, &n);

        if(m==0) {
            break;
        }

        int prev=0;

        vector<vector<pair<int,int>>> adj(m);

        for(int i=0; i<n;i++) {
            int a,b,c;
            scanf("%d %d %d", &a, &b, &c);
            adj[a].emplace_back(b,c);
            adj[b].emplace_back(a,c);
            prev+=c;
        }

        vector<int> dist(m, INT_MAX);
        vector<int> visited(m, 0);

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;

        dist[0]=0;
        pq.push({0,0});
        int tot=0;

        while(!pq.empty()) {
            pair<int,int> k=pq.top();
            pq.pop();
            int u=k.second;
            int d=k.first;
            if(visited[u]) {
                continue;
            }

            visited[u]=1;
            tot+=d;

            for(pair<int,int> &k:adj[u]) {
                if(!visited[k.first]&&k.second<dist[k.first]) {
                    dist[k.first]=k.second;
                    pq.push({k.second, k.first});
                }
            }

        }

        printf("%d\n", prev-tot);


    }
    return 0;
}
