#include <stdio.h>

char draw[100][100];
char drawb[100][100];
int visited[100][100] = {0};
int visitedb[100][100] = {0};

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

int color = 0;
int colorb = 0;
void dfs(int n, char ref, int x, int y) {
    visited[y][x]=1;
    for(int i=0; i<4; i++) {
        int nextx=x+dx[i];
        int nexty=y+dy[i];
        if(nextx>=0 && nextx<n && nexty>=0 && nexty<n && draw[nexty][nextx]==ref && visited[nexty][nextx]==0) {
            dfs(n, ref, nextx, nexty);
        }
    }
}

void dfsb(int n, char ref, int x, int y) {
    visitedb[y][x]=1;
    for(int i=0; i<4; i++) {
        int nextx=x+dx[i];
        int nexty=y+dy[i];
        if(nextx>=0 && nextx<n && nexty>=0 && nexty<n && drawb[nexty][nextx]==ref && visitedb[nexty][nextx]==0) {
            dfsb(n, ref, nextx, nexty);
        }
    }
}


int main() {
    int n;
    scanf("%d", &n);
    getchar();

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            scanf("%c", &draw[i][j]);
            if(draw[i][j]=='G') {
                drawb[i][j]='R';
            }
            else {
                drawb[i][j]=draw[i][j];
            }
        }
        getchar();
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(visited[i][j]==0) {
                dfs(n,draw[i][j],j,i);
                color++;
            }
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(visitedb[i][j]==0) {
                dfsb(n,drawb[i][j],j,i);
                colorb++;
            }
        }
    }

    printf("%d %d", color, colorb);

    return 0;
}
