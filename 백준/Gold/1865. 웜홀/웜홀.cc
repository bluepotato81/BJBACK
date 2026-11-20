#include <iostream>
#include <vector>
#include <limits>

#define INT_MAX 10000000000

using namespace std;

int main() {
    int tc;
    scanf("%d", &tc);
    while(tc--) {
        int n,m, w;
        scanf("%d %d %d", &n, &m , &w);

        vector<vector<pair<int, int>>> road;
        road.resize(n+1);

        for(int i=2; i<=m+1;i++) {
            int a,b,c;
            scanf("%d %d %d", &a, &b, &c);
            pair<int, int> k;
            k.first=c;
            k.second=b;
            road[a].push_back(k);
            k.second=a;
            road[b].push_back(k);
        }

        for(int i=m+2;i<=m+w+1; i++ ) {
            int a,b,c;
            scanf("%d %d %d", &a, &b, &c);
            pair<int, int> k;
            k.first=-c;
            k.second=b;
            road[a].push_back(k);
        }

        int cycle=0;
        vector<int> distance(n+1, INT_MAX);
        distance[1]=0;

        for(int i=1; i<n; ++i) {
            for(int j=1; j<=n; ++j) {
                for(pair<int, int> k: road[j]) {
                    int weight=k.first;
                    int v=k.second;
                    if(distance[j]!=INT_MAX && distance[j]+weight<distance[v]) {
                        distance[v]=distance[j]+weight;
                    }
                }
            }
        }

        for(int i=1; i<=n && !cycle; ++i) {
            for(pair<int, int> k: road[i]) {
                int weight=k.first;
                int v=k.second;
                if(distance[i]!=INT_MAX && distance[i]+weight<distance[v]) {
                    cycle=1;
                    break;
                }
            }
        }

        if(cycle) {
            printf("YES\n");
        }
        else {
            printf("NO\n");
        }

    }

    return 0;
}
