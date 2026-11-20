#include <stdio.h>

int iceberg[300][300];
int next[300][300];
int check[300][300];
int num=0;

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

void melt(int n, int m) {
    for(int i=0; i<n;i++) {
        for(int j=0; j<m;j++) {
            if(iceberg[i][j]==0) {
                next[i][j]=0;
                continue;
            }
            int round=0;
            for(int k=0; k<4;k++) {
                int cx=j+dx[k];
                int cy=i+dy[k];
                if(cx>=0 && cx<m && cy>=0 && cy<n && iceberg[cy][cx]==0) {
                    round++;
                }
            }
            if(iceberg[i][j]<=round) {
                next[i][j]=0;
            }
            else {
                next[i][j]=iceberg[i][j]-round;
            }
        }
    }

    for(int i=0; i<n;i++) {
        for(int j=0; j<m;j++) {
            iceberg[i][j]=next[i][j];
        }
    }
}

void see(int n,int m, int x, int y) {
    check[y][x]=1;
    for(int k=0; k<4;k++) {
        int cx=x+dx[k];
        int cy=y+dy[k];
        if(cx>=0 && cx<m && cy>=0 && cy<n && iceberg[cy][cx]>0 && check[cy][cx]==0) {
            see(n, m,cx,cy);
        }
    }
}


int pieces(int n, int m) {
    int piece=0;
    for(int i=0; i<n;i++) {
        for(int j=0; j<m;j++) {
            check[i][j]=0;
        }
    }

    for(int i=0; i<n;i++) {
        for(int j=0; j<m;j++) {
            if(iceberg[i][j] && !check[i][j]) {
                see(n,m,j,i);
                piece++;
            }
        }

    }




    return piece;
}



int main() {
    int n,m;
    scanf("%d %d",&n, &m);

    for(int i=0; i<n;i++) {
        for(int j=0; j<m;j++) {
            scanf("%d", &iceberg[i][j]);
        }
    }

    int years=0;
    while(1) {
        int parts=pieces(n,m);
        if(parts>=2) {
            break;
        }
        if(parts==0) {
            years=0;
            break;
        }
        melt(n,m);
        years++;

    }

    printf("%d", years);

    return 0;
}
