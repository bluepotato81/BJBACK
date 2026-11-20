#include <iostream>
#include <queue>

using namespace std;

typedef struct{
    int x;
    int y;
}pos;

queue<pos> loc;

int maze[101][101];
int visited[101][101];

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

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
    og.x=1;
    og.y=1;
    loc.push(og);

    visited[1][1]=1;

    if(n==1 && m==1) {
        printf("0");
        return 0;
    }

    int moves=0;
    int check=0;

    while(!check) {
        moves++;
        int queuelen=loc.size();
        for(int i=0; i<queuelen;i++) {
            pos cur=loc.front();
            loc.pop();
            for(int j=0; j<4; j++) {
                int nextx=cur.x+dx[j];
                int nexty=cur.y+dy[j];
                if(nextx>0 && nextx<=m && nexty>0 && nexty<=n && visited[nexty][nextx]==0 && maze[nexty][nextx]!=0) {
                    pos ne;
                    ne.x=nextx;
                    ne.y=nexty;
                    visited[nexty][nextx]=1;
                    loc.push(ne);
                    if(nextx==m && nexty==n) {
                        check=1;
                        break;
                    }
                }
            }
            if(check) {
                break;
            }
        }
    }

    printf("%d", moves+1);

    return 0;
}
