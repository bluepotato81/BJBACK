#include <stdio.h>

int main() {
    int p[101][101] = {0,};

    int n;
    scanf("%d", &n);

    for(int i=0; i<n; i++) {
        int a,b;
        scanf("%d %d", &a, &b);
        for(int j=a; j<a+10;j++) {
            for(int k=b+1;k<b+11;k++) {
                if(p[k][j]==0) {
                    p[k][j]++;
                }
            }
        }

    }

    int sp=0;
    for(int i=0;i<101;i++) {
        for(int j=0;j<101;j++) {
            if(p[j][i]!=0) {
                sp++;
            }
        }
    }
    printf("%d",sp);

    return 0;
}
