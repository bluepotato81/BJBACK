#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> near;
vector<int> points;
vector<int> orders;
vector<int> queue;

int qstart, qend;

int order=1;

int mark;
void bfs(int r) {
    points[r]=1;
    orders[r]=order++;
    queue[qend++]=r;
    while(qstart!=qend) {
    	mark=queue[qstart];
    	qstart++;
    	for(int next : near[mark]) {
	    	if(!points[next]) {
	           points[next]=1;
	           orders[next]=order++;
	           queue[qend++]=next;
	    	}
	    }
    }
   
}


int main() {
    int n,m,r;
    scanf("%d %d %d", &n, &m, &r);

    near.resize(n+1);
    points.resize(n+1, 0);
    orders.resize(n+1,0);
    queue.resize(2*n+1,0);

    int a,b;
    for(int i=0; i<m; i++) {
        scanf("%d %d", &a,&b);
        near[a].push_back(b);
        near[b].push_back(a);
    }

    for(int i=1; i<=n; i++) {
        sort(near[i].rbegin(), near[i].rend());
    }

    bfs(r);

    for(int i=1; i<=n; i++) {
        printf("%d\n", orders[i]);
    }


    return 0;
}
