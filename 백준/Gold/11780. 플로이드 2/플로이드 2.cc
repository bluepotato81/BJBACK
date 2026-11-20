#include <iostream>
#include <vector> 
#include <algorithm>
#include <limits.h>

using namespace std;


typedef struct {
    int start;
    int end;
    int cost;
} bus;

int dist[100][100];
int pre[100][100];
vector<int> path;

void floyd(int n) {
    for (int i = 0; i < n; i++) {
        dist[i][i] = 0;
        pre[i][i]=i;
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    pre[i][j]=pre[k][j];
                }
            }
        }
    }
}



void pathprint(int i, int j) {
	path.clear();
	path.push_back(j);
	if(pre[i][j]==-1) {
		printf("0 \n");
		return;
	}
	while(i!=j) {
		j=pre[i][j];
		path.push_back(j);
	}
	reverse(path.begin(), path.end());
	int len=path.size();
	if (len==1) {
        printf("0 \n");
        return;
    } else {
        printf("%d ", len);
    }
	for(int k=0; k<len; k++) {
		printf("%d ", path[k]+1);
	}
	printf("\n");
	return;
}

int main() {
	for(int i=0; i<100; i++) {
		for(int j=0; j<100; j++) {
			pre[i][j]=-1;
		}
	}
	
    int n, m;
    scanf("%d\n%d", &n, &m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dist[i][j] = INT_MAX;
        }
    }

    for (int i = 0; i < m; i++) {
        int start, end, cost;
        scanf("%d %d %d", &start, &end, &cost);
        start--;
        end--;
        if (dist[start][end] > cost) {
            dist[start][end] = cost;
        }
        pre[start][end]=start;
    }

    floyd(n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INT_MAX) {
                printf("0 ");
            } else {
                printf("%d ", dist[i][j]);
            }
        }
        printf("\n");
    }
     for (int i = 0; i < n; i++) {
     	for(int j=0; j<n; j++) {
     		pathprint(i,j);
     	}
        
    }

    return 0;
}
