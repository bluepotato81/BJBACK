#include <iostream>
#include <queue>

using namespace std;

typedef struct {
    int x;
    int y;
}loc;

queue<loc> location;

int tomato[1000][1000];
int visited[1000][1000];

int tottom;
int ripetom;

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

int days;

void bfs(int n, int m) {
    while(tottom!=ripetom) {
        int len=location.size();
        int bef_ripetom=ripetom;
        days++;
        for(int i=0; i<len; i++) {
            loc current=location.front();
            location.pop();
            for(int j=0; j<4; j++) {
                int newx=current.x+dx[j];
                int newy=current.y+dy[j];
                if (newx >= 0 && newx < m && newy >= 0 && newy < n && !visited[newy][newx] && tomato[newy][newx] == 0) {
                    visited[newy][newx] = 1;
                    tomato[newy][newx]=1;
                    loc next;
                    next.x = newx;
                    next.y = newy;
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
    int n, m;
    scanf("%d %d", &m, &n);

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            scanf("%d", &tomato[i][j]);
            if(tomato[i][j]==1 || tomato[i][j]==0) {
                tottom++;
            }
            if(tomato[i][j]==1) {
                ripetom++;
                loc ins;
                ins.x=j;
                ins.y=i;
                location.push(ins);
                visited[i][j]=1;
            }
        }
    }

    if(tottom==ripetom) {
        printf("0");
        return 0;
    }

    bfs(n,m);
    printf("%d", days);


    return 0;
}
