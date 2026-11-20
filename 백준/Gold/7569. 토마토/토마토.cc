#include <iostream>
#include <queue>

using namespace std;

typedef struct {
    int x;
    int y;
    int z;
}loc;

queue<loc> location;

int tomato[100][100][100];
int visited[100][100][100];

int tottom;
int ripetom;

int dx[]={0,0,0,0,1,-1};
int dy[]={0,0,1,-1,0,0};
int dz[]={1,-1,0,0,0,0};

int days;

void bfs(int n, int m, int h) {
    while(tottom!=ripetom) {
        int len=location.size();
        int bef_ripetom=ripetom;
        days++;

        for(int i=0; i<len; i++) {
            loc current=location.front();
            location.pop();
            for(int j=0; j<6; j++) {
                int newx=current.x+dx[j];
                int newy=current.y+dy[j];
                int newz=current.z+dz[j];
                if (newz >= 0 && newz < h && newx >= 0 && newx < m && newy >= 0 && newy < n && !visited[newy][newx][newz] && tomato[newy][newx][newz] == 0) {
                    visited[newy][newx][newz] = 1;
                    tomato[newy][newx][newz]=1;
                    loc next;
                    next.x = newx;
                    next.y = newy;
                    next.z = newz;
                    location.push(next);
                    ripetom++;
                }
            }
        }
        if(bef_ripetom==ripetom && tottom!=ripetom) {
            days=-1;
            return;
        }

    }
    if (tottom == ripetom) {
        return;
    }
}

int main() {
    int n, m,h;
    scanf("%d %d %d", &m, &n, &h);

    for(int l=0; l<h; l++) {
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                scanf("%d", &tomato[i][j][l]);
                if(tomato[i][j][l]==1 || tomato[i][j][l]==0) {
                    tottom++;
                }
                if(tomato[i][j][l]==1) {
                    ripetom++;
                    loc ins;
                    ins.x=j;
                    ins.y=i;
                    ins.z=l;
                    location.push(ins);
                    visited[i][j][l]=1;
                }
            }
        }
    }

    if(tottom==ripetom) {
        printf("0");
        return 0;
    }

    bfs(n,m, h);
    printf("%d", days);


    return 0;
}
