#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> near;
vector<int> points1;
vector<int> points2;
vector<int> orders;
vector<int> queue;

int qstart, qend;

int order=1;
void dfs(int r) {
    points1[r]=1;
    printf("%d ", r);
    for(int next : near[r]) {
        if(!points1[next]) {
            dfs(next);
        }
    }
}

int mark;
void bfs(int r) {
    points2[r]=1;
    printf("%d ", r);
    queue[qend++]=r;
    while(qstart!=qend) {
    	mark=queue[qstart];
    	qstart++;
    	for(int next : near[mark]) {
	    	if(!points2[next]) {
	           points2[next]=1;
	           orders[next]=order++;
	           printf("%d ", next);
	           queue[qend++]=next;
	    	}
	    }
    }
}


int main() {
    int n,m,r;
    scanf("%d %d %d", &n, &m, &r);

    near.resize(n+1);
    points1.resize(n+1, 0);
    points2.resize(n+1, 0);
    orders.resize(n+1,0);
    queue.resize(2*n+1,0);

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
	printf("\n");

    bfs(r);

    return 0;
}
