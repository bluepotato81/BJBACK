#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    char room[n][n+1];

    for(int i=0; i<n;i++) {
        scanf("%s", room[i]);
    }

    int hor=0;
    for(int i=0;i<n;i++) {
        int cur=0;
        for(int j=0;j<n;j++) {
            if(room[i][j]=='.') {
                cur++;
            }
            else {
                if(cur>=2) {
                    hor++;
                }
                cur=0;
            }
        }
        if(cur>=2) {
            hor++;
        }
    }
    int ver=0;
    for(int i=0;i<n;i++) {
        int cur=0;
        for(int j=0;j<n;j++) {
            if(room[j][i]=='.') {
                cur++;
            }
            else {
                if(cur>=2) {
                    ver++;
                }
                cur=0;
            }
        }
        if(cur>=2) {
            ver++;
        }
    }

    printf("%d %d", hor, ver);













    return 0;
}
