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
	for(int i=0; i<n; i++) {
        int num;
        scanf("%d", &num);
        while(1) {
            int in1, in2;
            scanf("%d", &in1);
            if(in1==-1) {
                break;
            }
            scanf("%d", &in2);

            edge e1={in1, in2};
            tree[num].push_back(e1);

            edge e2 = {num, in2};
            tree[in1].push_back(e2);
        }
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
