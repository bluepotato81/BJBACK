#include <stdio.h>

int n,m;
int hill[500][500];
int dp[500][500];

int find(int x, int y) {
    if(x==n-1 && y==m-1) {
        return 1;
    }
    if(dp[x][y]!=-1) {
        return dp[x][y];
    }

    dp[x][y]=0;

    int xfind, yfind;

    xfind=x;
    yfind=y+1;
    if(xfind>=0 && yfind>=0 && xfind<n && yfind<m) {
        if(hill[xfind][yfind]<hill[x][y]) {
            dp[x][y]+=find(xfind,yfind);
        }
    }

    xfind=x;
    yfind=y-1;
    if(xfind>=0 && yfind>=0 && xfind<n && yfind<m) {
        if(hill[xfind][yfind]<hill[x][y]) {
            dp[x][y]+=find(xfind,yfind);
        }
    }

    xfind=x+1;
    yfind=y;
    if(xfind>=0 && yfind>=0 && xfind<n && yfind<m) {
        if(hill[xfind][yfind]<hill[x][y]) {
            dp[x][y]+=find(xfind,yfind);
        }
    }

    xfind=x-1;
    yfind=y;
    if(xfind>=0 && yfind>=0 && xfind<n && yfind<m) {
        if(hill[xfind][yfind]<hill[x][y]) {
            dp[x][y]+=find(xfind,yfind);
        }
    }
    return dp[x][y];

}

int main() {
    scanf("%d %d", &n, &m);


    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            scanf("%d", &hill[i][j]);
            dp[i][j]=-1;
        }
    }

    int k=find(0,0);

    printf("%d", k);

    return 0;
}
