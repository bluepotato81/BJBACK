#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

struct Road {
    int des;
    int weight;
};

vector<vector<Road>> graph;
vector<int> visited;
vector<int> cost;
vector<int> possible;

void djik(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, start});
    cost[start] = 0;

    while (!pq.empty()) {
        int curcost = pq.top().first;
        int curplace = pq.top().second;
        pq.pop();

        if (visited[curplace]) continue;
        visited[curplace] = 1;

        for (Road next : graph[curplace]) {
            int ncost = curcost + next.weight;
            if (ncost < cost[next.des]) {
                cost[next.des] = ncost;
                pq.push({ncost, next.des});
            }
        }
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m, t;
        cin >> n >> m >> t;

        int s, g, h;
        cin >> s >> g >> h;

        graph.assign(n + 1, vector<Road>());
        visited.assign(n + 1, 0);
        cost.assign(n + 1, INT_MAX);
        possible.resize(t);

        for (int i = 0; i < m; i++) {
            int x, y, z;
            cin >> x >> y >> z;
            graph[x].push_back({y, z});
            graph[y].push_back({x, z});
        }

        for (int i = 0; i < t; i++) {
            cin >> possible[i];
        }

        vector<int> sl(n + 1, INT_MAX), gl(n + 1, INT_MAX), hl(n + 1, INT_MAX);

        // Run Dijkstra from s, g, and h to fill sl, gl, and hl
        cost = sl;
        visited.assign(n + 1, 0);
        djik(s);
        sl = cost;

        cost = gl;
        visited.assign(n + 1, 0);
        djik(g);
        gl = cost;

        cost = hl;
        visited.assign(n + 1, 0);
        djik(h);
        hl = cost;

        // Collect valid destinations
        vector<int> results;
        for (int dest : possible) {
            if (sl[dest] == sl[g] + gl[h] + hl[dest] || sl[dest] == sl[h] + hl[g] + gl[dest]) {
                results.push_back(dest);
            }
        }

        // Sort and output results
        sort(results.begin(), results.end());
        for (int r : results) {
            cout << r << " ";
        }
        cout << "\n";

        // Clear structures for the next test case
        graph.clear();
        visited.clear();
        cost.clear();
    }

    return 0;
}
