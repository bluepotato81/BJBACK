#include <stdio.h>

int field[52][52];

void dfs(int i, int j) {
    if(field[i][j]==1) {
        field[i][j]=2;
        if(field[i-1][j]==1) {
            dfs(i-1,j);
        }
        if(field[i][j-1]==1) {
            dfs(i,j-1);
        }
        if(field[i][j+1]==1) {
            dfs(i,j+1);
        }
        if(field[i+1][j]==1) {
            dfs(i+1,j);
        }
    }
}




int main() {
    int t;
    scanf("%d", &t);

    for(int i=0; i<t; i++) {
        int m,n,k;
        scanf("%d %d %d", &m, &n, &k);
        int x,y;
        for(int i=0; i<k; i++) {
            scanf("%d %d", &x, &y);
            field[y+1][x+1]=1;
        }
        int wormnum=0;
        for(int i=1; i<n+1; i++) {
            for(int j=1; j<m+1; j++) {
                if(field[i][j]==1) {
                    dfs(i,j);
                    wormnum++;
                }
            }
        }
        printf("%d\n", wormnum);
        for(int i=1; i<n+1; i++) {
            for(int j=1; j<m+1; j++) {
                field[i][j]=0;
            }
        }
    }

    return 0;
}
