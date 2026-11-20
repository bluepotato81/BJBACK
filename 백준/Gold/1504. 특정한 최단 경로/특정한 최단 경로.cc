#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef struct{
    int des;
    int weight;
}road;

vector<vector<road> > graph;
vector<int> visited;
vector<int> cost;

void djik(int r) {
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int>>> pq;

    pq.push({0,r});
    cost[r]=0;

    while(!pq.empty()) {
        int curcost=pq.top().first;
        int curplace=pq.top().second;
        pq.pop();

        if(visited[curplace]) {
            continue;
        }
        visited[curplace]=1;

        for(road next:graph[curplace]) {
            int ncost=curcost+next.weight;
            if(ncost<cost[next.des]) {
                cost[next.des]=ncost;
                pq.push({ncost, next.des});
            }
        }
    }

}

int main() {
    int v,e;
    scanf("%d %d", &v, &e);

    int start=1;

    graph.resize(v+1);
    visited.resize(v+1,0);
    cost.resize(v+1, 2147483647);

    int a,b,c;
    for(int i=0; i<e; i++) {
        scanf("%d %d %d", &a, &b, &c);
        road first, second;
        first.des=b;
        first.weight=c;
        second.des=a;
        second.weight=c;
        graph[a].push_back(first);
        graph[b].push_back(second);
    }

    int o, t;
    scanf("%d %d", &o, &t);

    int stto, sttt, ott, tte, ote;

    djik(o);

    if(visited[start]==0 || visited[t]==0 || visited[v]==0) {
        printf("-1");
        return 0;
    }

    stto=cost[start];
    ott=cost[t];
    ote=cost[v];

    visited.resize(0);
    visited.resize(v+1, 0);
    cost.resize(0);
    cost.resize(v+1, 2147483647);

    djik(t);

    if(visited[start]==0 || visited[v]==0) {
        printf("-1");
        return 0;
    }

    sttt=cost[start];
    tte=cost[v];

    int ot=stto+ott+tte;
    int to=sttt+ott+ote;

    if(ot<to) {
           printf("%d\n", ot);
    }
    else {
           printf("%d\n", to);
    }



    return 0;
}
