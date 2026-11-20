#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef struct{
    int des;
    int weight;
}road;

vector<vector<road>> graph;
vector<int> visited;
vector<int> cost;

void djik(int r) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

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

    int start;
    scanf("%d", &start);

    graph.resize(v+1);
    visited.resize(v+1,0);
    cost.resize(v+1, 2147483647);

    int a,b,c;
    for(int i=0; i<e; i++) {
        scanf("%d %d %d", &a, &b, &c);
        road first;
        first.des=b;
        first.weight=c;
        graph[a].push_back(first);
    }


    djik(start);


    for(int i=1; i<=v; i++) {
        if(visited[i]==0) {
            printf("INF\n");
        }
        else {
            printf("%d\n", cost[i]);
        }
    }



    return 0;
}
