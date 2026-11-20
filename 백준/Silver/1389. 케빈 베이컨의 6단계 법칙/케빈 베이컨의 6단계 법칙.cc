#include <stdio.h>
#include <limits.h>

int userpath[101][101];
int distance[101][101];

void calculate(int n) {
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n;j++) {
            if(userpath[i][j]==1) {
                distance[i][j]=1;
            }
        }
    }
    for(int i=1; i<=n; i++) {
        distance[i][i]=0;
    }
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n;j++) {
            for(int k=1; k<=n;k++) {
                if(distance[j][k]>distance[j][i]+distance[i][k]) {
                    distance[j][k]=distance[j][i]+distance[i][k];
                }
            }
        }
    }
}

int main() {
    int n,m;
    scanf("%d %d", &n, &m);

    int a,b;
    for(int i=0; i<m;i++) {
        scanf("%d %d", &a, &b);
        userpath[a][b]=1;
        userpath[b][a]=1;
    }

    for(int i=1; i<=n;i++) {
        for(int j=1; j<=n;j++) {
            distance[i][j]=40000;
        }
    }
    calculate(n);

    int small=INT_MAX;
    int smallindex=12321;

    for(int i=1; i<=n;i++) {
        int bacon=0;
        for(int j=1;j<=n;j++) {
            bacon+=distance[i][j];
        }
        if(bacon<small) {
            smallindex=i;
            small=bacon;
        }
    }

    printf("%d", smallindex);


    return 0;
}
