#include <iostream>
#include <queue>

using namespace std;

typedef struct{
    int x;
    int y;
}pos;

queue<pos> loc;

int maze[1001][1001];

int begdis[1001][1001];
int enddis[1001][1001];

int visited[1001][1001];

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

int distmin=1048576;

int main() {
    int n,m;
    scanf("%d %d", &n, &m);
    getchar();


    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            char input;
            scanf("%c", &input);
            maze[i][j]=input-'0';
        }
        getchar();
    }

    pos og;
    og.x=m;
    og.y=n;
    loc.push(og);
    visited[n][m]=1;
    enddis[n][m]=1;

    if(n==1 && m==1) {
        printf("1");
        return 0;
    }

    while(!loc.empty()) {
        pos cur=loc.front();
        loc.pop();
        for(int i=0; i<4; i++) {
            int newx=cur.x+dx[i];
            int newy=cur.y+dy[i];
            if(newx>0 && newx<=m && newy>0 && newy<=n&& visited[newy][newx]==0 && maze[newy][newx]==0) {
                pos ne;
                ne.x=newx;
                ne.y=newy;
                loc.push(ne);
                visited[newy][newx]=1;
                enddis[newy][newx]=enddis[cur.y][cur.x]+1;
            }
        }
    }

    og.x=1;
    og.y=1;
    loc.push(og);
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            visited[i][j]=0;
        }
    }

    visited[1][1]=1;
    begdis[1][1]=1;


    while(!loc.empty()) {
        pos cur=loc.front();
        loc.pop();
        for(int j=0; j<4; j++) {
            int nextx=cur.x+dx[j];
            int nexty=cur.y+dy[j];
            if(nextx>0 && nextx<=m && nexty>0 && nexty<=n&& visited[nexty][nextx]==0) {
                if(maze[nexty][nextx]==1) {
                    for(int k=0; k<4; k++) {
                        int nextx2 = nextx+dx[k];
                        int nexty2 = nexty+dy[k];
                        if(enddis[nexty2][nextx2]!=0) {
                            if(begdis[cur.y][cur.x]+enddis[nexty2][nextx2]+1<distmin) {
                                distmin=begdis[cur.y][cur.x]+enddis[nexty2][nextx2]+1;
                            }
                        }
                    }
                }
                else {
                    pos ne;
                    ne.x=nextx;
                    ne.y=nexty;
                    loc.push(ne);
                    visited[nexty][nextx]=1;
                    begdis[nexty][nextx]=begdis[cur.y][cur.x]+1;
                }
            }
        }
    }

    if(begdis[n][m]!=0) {
        distmin=min(distmin, begdis[n][m]);
    }

    if(distmin==1048576) {
        printf("-1");
    }
    else {
        printf("%d", distmin);
    }


    return 0;
}
