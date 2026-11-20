#include <stdio.h>

int cx,cy;
int dir;

int room[50][50];

int clean=0;

int dx[4]={0,1,0,-1};
int dy[4]={-1,0,1,0};

void cl(int n, int m) {
    if(room[cy][cx]==0) {
        room[cy][cx]=2;
        clean++;
    }
    int check=0;
    for(int i=0;i<4; i++) {
        if(room[cy+dy[i]][cx+dx[i]]==0) {
            check++;
            break;
        }
    }
    if(!check) {
        if(room[cy-dy[dir]][cx-dx[dir]]!=1) {
            int by = cy - dy[dir];
            int bx = cx - dx[dir];

            if (by >= 0 && by < n && bx >= 0 && bx < m && room[by][bx] != 1) {
                cy = by;
                cx = bx;
                cl(n, m);
            }
        }
    }
    else {
        for (int i = 0; i < 4; i++) {
            dir = (dir + 3) % 4;
            int ny = cy + dy[dir];
            int nx = cx + dx[dir];

            if (ny >= 0 && ny < n && nx >= 0 && nx < m && room[ny][nx] == 0) {
                cy = ny;
                cx = nx;
                cl(n, m);
                return;
            }
        }

    }
    return;
}

int main() {
    int n,m;
    scanf("%d %d", &n, &m);

    scanf("%d %d %d", &cy, &cx, &dir);

    for(int i=0; i<n;i++) {
        for(int j=0;j<m;j++) {
            scanf("%d", &room[i][j]);
        }
    }

    cl(n,m);

    printf("%d", clean);

    return 0;
}
