#include <iostream>
#include <vector>

using namespace std;
#define MAX 100001

int n;
int parent[MAX];
int visited[MAX];
vector<int> v[MAX];

void dfs(int k) {
    visited[k]=1;
    for(int next: v[k]) {
        if(!visited[next]) {
            parent[next]=k;
            dfs(next);
        }
    }
}


int main() {
    int n;
    scanf("%d", &n);

    for(int i=1; i<n; i++) {
        int x,y;
        scanf("%d %d", &x, &y);
        v[x].push_back(y);
        v[y].push_back(x);
    }

    dfs(1);

    for(int i=2; i<=n; i++) {
        printf("%d\n", parent[i]);
    }




    return 0;
}
