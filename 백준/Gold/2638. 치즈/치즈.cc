#include <stdio.h>

int cheese[100][100];
int openair[100][100];
int aircheck_visited[100][100];

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

int time=0;

int cheesen;

void aircheck(int n,int m, int x, int y) {
    openair[y][x]=1;
    aircheck_visited[y][x]=1;
    for(int i=0; i<4;i++) {
        int newx=x+dx[i];
        int newy=y+dy[i];
        if(newx>=0 && newx<m && newy>=0 && newy<n && aircheck_visited[newy][newx]==0 && cheese[newy][newx]!=1) {
            aircheck(n,m,newx,newy);
        }
    }
}

void melt(int n,int m) {
    aircheck(n,m,0,0);
    time++;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(cheese[i][j]==1) {
                int aircount=0;
                for(int k=0; k<4; k++) {
                    int checkx=j+dx[k];
                    int checky=i+dy[k];
                    if(openair[checky][checkx]==1) {
                        aircount++;
                    }
                }
                if(aircount>=2) {
                    cheesen--;
                    cheese[i][j]=0;
                }
            }
        }
    }

    if(cheesen==0) {
        return;
    }
    else {
        for(int i=0; i<n;i++) {
            for(int j=0; j<m; j++) {
                aircheck_visited[i][j]=0;
            }
        }
        melt(n,m);
        return;
    }
}

int main() {
    int n,m;
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++) {
        for(int j=0; j<m;j++) {
            scanf("%d", &cheese[i][j]);
            if(cheese[i][j]==1) {
                cheesen++;
            }
        }
    }

    melt(n,m);

    printf("%d", time);


    return 0;
}
