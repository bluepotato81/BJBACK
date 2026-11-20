#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int house[n][n];
    for(int i=0; i<n;i++) {
        for(int j=0;j<n;j++) {
            scanf("%d", &house[i][j]);
        }
    }

    int dph[n][n];
    int dpv[n][n];
    int dpd[n][n];
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            dph[i][j]=0;
            dpv[i][j]=0;
            dpd[i][j]=0;
        }
    }

    dph[0][1]=1;
    for(int i=2; i<n;i++) {
        if(house[0][i]) {
            break;
        }
        dph[0][i]=1;
    }



    for(int i=1;i<n;i++) {
        for(int j=2;j<n;j++) {
            if(house[i][j]) {
                continue;
            }
            else if(house[i-1][j] || house[i][j-1]) {
                dph[i][j]=dph[i][j-1]+dpd[i][j-1];
                dpv[i][j]=dpv[i-1][j]+dpd[i-1][j];
            }
            else {
                dph[i][j]=dph[i][j-1]+dpd[i][j-1];
                dpv[i][j]=dpv[i-1][j]+dpd[i-1][j];
                dpd[i][j]=dph[i-1][j-1]+dpd[i-1][j-1]+dpv[i-1][j-1];
            }
        }
    }

    /*int dp[n][n];
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            dp[i][j]=dph[i][j]+dpv[i][j]+dpd[i][j];
            printf("%d ", dp[i][j]);
        }
        printf("\n");
    }*/

    printf("%d", dpv[n-1][n-1]+dpd[n-1][n-1]+dph[n-1][n-1]);



    return 0;
}
