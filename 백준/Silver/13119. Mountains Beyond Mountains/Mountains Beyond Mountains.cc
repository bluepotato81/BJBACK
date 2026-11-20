#include <stdio.h>

int main() {
    int n,m,x;
    scanf("%d %d %d", &n, &m, &x);

    char dr[n][m];
    for(int i=0; i<n;i++) {
        for(int j=0; j<m;j++) {
            dr[i][j]='.';
        }
    }

    int moun[m];

    for(int i=0; i<m;i++) {
        scanf("%d", &moun[i]);
        for(int j=n-1; j>n-1-moun[i]; j--) {
            dr[j][i]='#';
        }
    }

    int height=n-x;

    for(int i=0; i<m;i++) {
        if(moun[i]<x) {
            dr[height][i]='-';
            if((i+1)%3==0) {
                for(int j=height+1;j<n-moun[i];j++) {
                    dr[j][i]='|';
                }
            }
        }
        else {
            dr[height][i]='*';
        }
    }

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            printf("%c", dr[i][j]);
        }
        printf("\n");
    }
    return 0;
}
