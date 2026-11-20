#include <iostream>
#include <queue>

using namespace std;

typedef struct {
    int x;
    int y;
}loc;

queue<loc> location;

int mapp[1000][1000];
int dis[1000][1000];
int visited[1000][1000];

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

void bfs(int n, int m, int x, int y) {
    dis[y][x]=0;
    loc pusher;
    pusher.x = x;
    pusher.y = y;
    location.push(pusher);
    visited[y][x]=1;

    while(!location.empty()) {
        loc current=location.front();
        location.pop();
        for(int i=0; i<4; i++) {
            int newx=current.x+dx[i];
            int newy=current.y+dy[i];
            if (newx >= 0 && newx < m && newy >= 0 && newy < n && !visited[newy][newx] && mapp[newy][newx] == 1) {
                dis[newy][newx] = dis[current.y][current.x] + 1;
                visited[newy][newx] = 1;
                loc next;
                next.x = newx;
                next.y = newy;
                location.push(next);
            }
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int startlocx;
    int startlocy;

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            scanf("%d", &mapp[i][j]);

            if(mapp[i][j]==2) {
                startlocx=j;
                startlocy=i;
            }

            if(mapp[i][j]==0) {
                dis[i][j]=0;
            }
            else {
                dis[i][j]=-1;
            }
        }
    }
    bfs(n,m,startlocx, startlocy);

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            printf("%d ", dis[i][j]);
        }
        printf("\n");
    }



    return 0;
}
