#include <stdio.h>
#include <limits.h>

int main() {
    int n,m,b;
    scanf("%d %d %d", &n, &m, &b);

    int map[n][m];

    for(int i=0; i<n;i++) {
        for(int j=0; j<m;j++) {
            scanf("%d", &map[i][j]);
        }
    }

    int height[257];

    int mintime=INT_MAX;
    int mindex;

    for(int i=0; i<257;i++) {
        int mine=0;
        int place=0;
        for(int j=0; j<n;j++) {
            for(int k=0; k<m; k++) {
                if(map[j][k]<i) {
                    place+=i-map[j][k];
                }
                else {
                    mine+=map[j][k]-i;
                }
            }
        }

        if(mine+b>=place) {
            int time=mine*2+place;
            if(time<=mintime) {
                mintime=time;
                mindex=i;
            }
        }
    }

    printf("%d %d", mintime, mindex);

    return 0;
}
