#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int table[n][n];
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            scanf("%d", &table[i][j]);
        }
    }

    int larg[n];
    int largspot[n];

    for(int i=0; i<n; i++) {
        larg[i]=table[n-1][i];
        largspot[i]=n-1;
    }

    int ans;

    for(int i=0; i<n; i++) {
        int max=-1000000001;
        int maxindex=0;
        for(int j=0; j<n; j++) {
            if(larg[j]>max) {
                max=larg[j];
                maxindex=j;
            }
        }

        if(largspot[maxindex]==0) {
            larg[maxindex]=-1000000001;
        }
        else {
            larg[maxindex]=table[largspot[maxindex]-1][maxindex];
            largspot[maxindex]--;
        }

        if(i==n-1) {
            ans=max;
        }
    }

    printf("%d", ans);

    return 0;
}
