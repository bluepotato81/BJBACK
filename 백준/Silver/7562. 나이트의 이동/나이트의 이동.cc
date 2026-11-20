#include <iostream>
#include <queue>

using namespace std;

typedef struct{
    int x;
    int y;
}pos;

queue<pos> loc;

int dx[]={-2,-2,-1,-1, 1,1,2,2};
int dy[]={1,-1,2,-2,2,-2,1,-1};

int main() {
    int t;
    scanf("%d", &t);

    for(int i=0; i<t; i++) {
        int l;
        scanf("%d", &l);
        int visited[l][l];
        for(int i=0; i<l; i++) {
            for(int j=0; j<l; j++) {
                visited[i][j]=0;
            }
        }
        int sx, sy;
        scanf("%d %d", &sx, &sy);
        int gx, gy;
        scanf("%d %d", &gx, &gy);
        if(sx==gx && sy==gy) {
            printf("0\n");
            continue;
        }
        pos og;
        og.x=sx;
        og.y=sy;
        loc.push(og);
        visited[sy][sx]=1;

        int moves=0;
        int check=0;

        while(!check) {
            moves++;
            int queuelen=loc.size();
            for(int i=0; i<queuelen;i++) {
                pos cur=loc.front();
                loc.pop();
                for(int j=0; j<8; j++) {
                    int nextx=cur.x+dx[j];
                    int nexty=cur.y+dy[j];
                    if(nextx>=0 && nextx<l && nexty>=0 && nexty<l && visited[nexty][nextx]==0) {
                        pos ne;
                        ne.x=nextx;
                        ne.y=nexty;
                        visited[nexty][nextx]=1;
                        loc.push(ne);
                        if(nextx==gx && nexty==gy) {
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

        printf("%d\n", moves);

        loc=queue<pos>();

    }

    return 0;
}
