#include <stdio.h>

int main(void) {
    int n,m;
    scanf("%d %d", &n, &m);
    char chess[n][m];

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            scanf(" %c", &chess[i][j]);
        }
    }

    int min_p=32;
    char cut[8][8];

    for(int i=0;i<n-7;i++) {
        for(int j=0;j<m-7;j++) {
            int p=0;
            for(int k=0;k<8;k++) {
                for(int l=0;l<8;l++) {
                    cut[k][l]=chess[i+k][j+l];
                }
            }
            for(int k=0;k<8;k++) {
                for(int l=0;l<8;l++) {
                    if((k+l)%2==0) {
                        if(cut[k][l]=='B') {
                            p++;
                        }
                    }
                    if((k+l)%2==1) {
                        if(cut[k][l]=='W') {
                            p++;
                        }
                    }
                }
            }
            if(p>32) {
                p=64-p;
            }
            if(min_p>p) {
                min_p=p;
            }
        }
    }

    printf("%d", min_p);
    return 0;
}
