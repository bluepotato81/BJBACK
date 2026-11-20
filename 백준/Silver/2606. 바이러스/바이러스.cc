#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int> > near;
vector<int> points;
vector<int> queue;

int qstart, qend;

int comp=0;

int mark;
void bfs() {
    points[1]=1;
    comp++;
    queue[qend++]=1;
    while(qstart!=qend) {
    	mark=queue[qstart];
    	qstart++;
    	for(int next : near[mark]) {
	    	if(!points[next]) {
	           points[next]=1;
	           comp++;
	           queue[qend++]=next;
	    	}
	    }
    }
   
}


int main() {
    int n,m;
    scanf("%d %d", &n, &m);

    near.resize(n+1);
    points.resize(n+1, 0);
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

    bfs();

    printf("%d\n", comp-1);


    return 0;
}
