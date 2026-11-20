#include <stdio.h>

int m[100][100];
int visited[100][100];
int n;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

void dfs(int x, int y, int l) {
    visited[y][x]=1;
    for (int i=0; i<4; i++) {
        int nx, ny;
        nx = x + dx[i];
        ny = y + dy[i];
        if(nx>=0 && nx<n && ny>=0 && ny<n && m[ny][nx]>l && visited[ny][nx]==0) {
            dfs(nx, ny, l);
        }
    }
}

int flood(int l){

    int islands = 0;


    for(int i=0; i<n;i++) {
        for(int j=0; j<n; j++) {
            visited[i][j]=0;
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(visited[i][j]==1) {
                continue;
            }

            if(m[i][j]>l) {
                islands++;
                dfs(j, i,l);

            }
        }
    }

    return islands;
}


int main() {
    scanf("%d", &n);

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            scanf("%d", &m[i][j]);
        }
    }

    int maxil = 0;
    for (int i=0; i<100; i++) {
        int k = flood(i);
        if(k>maxil) {
            maxil = k;
        }
        //printf("%d\n", k);
    }

    printf("%d", maxil);


    return 0;
}
