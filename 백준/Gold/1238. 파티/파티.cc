#include <iostream>
#include <vector>
#include <queue>

#define INF 2147483647

using namespace std;

vector<vector<pair<int, int>>> routes;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

int main() {
    int n, m, x;
    scanf("%d %d %d", &n, &m, &x);

    routes.resize(n+1);


    for(int i=0; i<m;i++) {
        int a,b,c;
        scanf("%d %d %d", &a, &b, &c);

        pair<int, int> k;
        k.first=b;
        k.second=c;
        routes[a].push_back(k);
    }

    int godis[n+1];
    vector<int> dist(n+1);
    for(int i=1;i<n+1;i++) {
        fill(dist.begin(), dist.end(), INF);

        dist[i]=0;
        pq.push({i, 0});

        while(!pq.empty()) {
            int u = pq.top().first;
            int d = pq.top().second;
            pq.pop();
            if(d>dist[u]) {
                continue;
            }

            for(auto k : routes[u]) {
                int v=k.first;
                int weight = k.second;
                if(dist[u]+weight<dist[v]) {
                    dist[v]=dist[u]+weight;
                    pq.push({v, dist[v]});
                }
            }
        }

        godis[i] = dist[x];
    }

    int comedis[n+1];

    fill(dist.begin(), dist.end(), INF);
    dist[x]=0;

    pq.push({x, 0});

    while(!pq.empty()) {
        int u = pq.top().first;
        int d = pq.top().second;
        pq.pop();
        if(d>dist[u]) {
            continue;
        }

        for(auto k : routes[u]) {
            int v=k.first;
            int weight = k.second;
            if(dist[u]+weight<dist[v]) {
                dist[v]=dist[u]+weight;
                pq.push({v, dist[v]});
            }
        }
    }

    for(int i=1; i<n+1;i++) {
        comedis[i] = dist[i];
    }


    int totdis[n+1];

    for(int i=1; i<n+1;i++) {
        totdis[i]=godis[i]+comedis[i];
    }

    int big=0;

    for(int i=1;i<n+1;i++) {
        big=max(big, totdis[i]);
    }


    printf("%d", big);

    return 0;
}
