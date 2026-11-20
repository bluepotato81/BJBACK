#include <iostream>
#include <queue>

#define INF 2147483647

using namespace std;

int poscal(int n, int x, int y) {
    return y*n+x;
}
int xcal(int k, int n) {
    return k%n;
}
int ycal(int k, int n) {
    return k/n;
}

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0,0, -1, 1};


int main() {
    int n;
    int probnum=1;
    while(1) {
        scanf("%d", &n);
        if(n==0) {
            break;
        }
        int cave[n][n];
        for(int i=0; i<n;i++) {
            for(int j=0;j<n;j++) {
                scanf("%d", &cave[i][j]);
            }
        }

        int graph[n][n];
        int pushed[n][n];
        int done[n][n];

        for(int i=0; i<n;i++) {
            for(int j=0;j<n;j++) {
                graph[i][j]=INF;
                done[i][j]=0;
                pushed[i][j]=0;
            }
        }
        graph[0][0]=cave[0][0];

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        q.push({graph[0][0], poscal(n, 0, 0)});

        while(!q.empty()) {
            int x = xcal(q.top().second, n);
            int y = ycal(q.top().second, n);
            q.pop();

            if (done[y][x]) continue;

            for(int i=0; i<4;i++) {
                int newx=x+dx[i];
                int newy=y+dy[i];
                if(newx>=0&&newx < n &&newy>=0&& newy < n && done[newy][newx]==0) {
                    if(graph[newy][newx]>graph[y][x]+cave[newy][newx]) {
                        graph[newy][newx]=graph[y][x]+cave[newy][newx];
                        q.push({graph[newy][newx], poscal(n, newx, newy)});
                    }
                    if(pushed[newy][newx]==0) {
                        pushed[newy][newx] = 1;
                    }
                }


            }
            done[y][x]=1;

        }

        printf("Problem %d: %d\n", probnum++, graph[n-1][n-1]);
    }

    return 0;
}
