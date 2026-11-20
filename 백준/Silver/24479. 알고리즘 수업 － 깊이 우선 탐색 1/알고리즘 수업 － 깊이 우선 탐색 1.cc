#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> near;
vector<int> points;
vector<int> orders;

int order=1;
void dfs(int r) {
    points[r]=1;
    orders[r]=order++;
    for(int next : near[r]) {
        if(!points[next]) {
            dfs(next);
        }
    }
}


int main() {
    int n,m,r;
    scanf("%d %d %d", &n, &m, &r);

    near.resize(n+1);
    points.resize(n+1, 0);
    orders.resize(n+1,0);

    int a,b;
    for(int i=0; i<m; i++) {
        scanf("%d %d", &a,&b);
        near[a].push_back(b);
        near[b].push_back(a);
    }

    for(int i=1; i<=n; i++) {
        sort(near[i].begin(), near[i].end());
    }

    dfs(r);

    for(int i=1; i<=n; i++) {
        printf("%d\n", orders[i]);
    }


    return 0;
}
