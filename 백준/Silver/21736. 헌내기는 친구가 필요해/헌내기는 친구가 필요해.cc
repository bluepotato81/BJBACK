#include <stdio.h>

char campus[600][600];
int visited[600][600];

int person=0;

int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};

void dfs(int m, int n,int x, int y) {
    visited[y][x]=1;
    if(campus[y][x]=='P') {
        person++;
    }
    for(int i=0; i<4;i++) {
        int newx=x+dx[i];
        int newy=y+dy[i];
        if(newx>=0 && newx<m && newy>=0 && newy<n && visited[newy][newx]==0 && campus[newy][newx]!='X') {
            dfs(m,n,newx,newy);
        }
    }

}

int main() {
    int n,m;
    scanf("%d %d", &n, &m);
    getchar();

    int startx, starty;

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            scanf("%c", &campus[i][j]);
            if(campus[i][j]=='I') {
                startx=j;
                starty=i;
            }
        }
        getchar();
    }

    dfs(m,n,startx, starty);
    if(person==0) {
        printf("TT");
    }
    else {
        printf("%d", person);
    }

    return 0;
}
