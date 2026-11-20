#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>

using namespace std;

typedef struct{
    int des;
    int weight;
}road;

vector<vector<road>> graph;
vector<int> visited;
vector<int> cost;
vector<int> jumps;
vector<int> pre;

void djik(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;

    pq.push({0, start});
    cost[start] = 0;

    jumps[start] = 0;

    while (!pq.empty()) {
        int curcost = pq.top().first;
        int curplace = pq.top().second;
        pq.pop();

        if (visited[curplace]) continue;
        visited[curplace] = 1;

        for (road next : graph[curplace]) {
            int ncost = curcost + next.weight;
            if (ncost < cost[next.des]) {
                cost[next.des] = ncost;
                pre[next.des] = curplace;
                jumps[next.des] = jumps[curplace]+1;
                pq.push({ncost, next.des});
            }
        }
    }
}

int main() {
    int n, m;
    scanf("%d\n%d", &n, &m);

    graph.resize(n+1);
    visited.resize(n+1,0);
    cost.resize(n+1, 2147483647);
    jumps.resize(n+1,0);
    pre.resize(n+1,-1);

    int x, y, z;
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &x, &y, &z);
        road inp;
        inp.des=y;
        inp.weight=z;
        graph[x].push_back(inp);
    }

    int start, finish;
    scanf("%d %d", &start, &finish);

    djik(start);

    /*for(int i=0; i<n; i++) {
        printf("%d ", pre[i]);
    }
    printf("\n");*/

    printf("%d\n%d\n",cost[finish], jumps[finish]+1);

    vector<int> path;
    for (int k = finish; k != -1; k = pre[k]) {
        path.push_back(k);
    }
    reverse(path.begin(), path.end());

    for(int node:path) {
        printf("%d ", node);
    }
    return 0;
}
