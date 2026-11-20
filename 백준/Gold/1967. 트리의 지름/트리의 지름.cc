#include <iostream>
#include <vector>

using namespace std;

typedef struct {
    int des;
    int dis;
}edge;

vector<vector<edge>> tree;

vector<int> discal;
vector<int> visited;

int maxdis=0;
int maxindex;

void dfs(int a) {
    visited[a]=1;
    for(edge next: tree[a]) {
        if(!visited[next.des]) {
            discal[next.des]=discal[a]+next.dis;
            if(discal[next.des]>maxdis) {
                maxdis=discal[next.des];
                maxindex=next.des;
            }
            dfs(next.des);
        }
    }
}

int main() {
	int n;
	scanf("%d", &n);

	tree.resize(n+1);
	for(int i=0; i<n-1; i++) {
        int a,b,c;
        scanf("%d %d %d", &a, &b, &c);
        tree[a].push_back({b,c});
        tree[b].push_back({a,c});
	}

	discal.resize(n+1);
	visited.resize(n+1);

	fill(discal.begin(), discal.end(), 0);
    fill(visited.begin(), visited.end(), 0);
    dfs(1);

    fill(discal.begin(), discal.end(), 0);
    fill(visited.begin(), visited.end(), 0);
    maxdis = 0;
    dfs(maxindex);

    printf("%d", maxdis);

	return 0;
}
