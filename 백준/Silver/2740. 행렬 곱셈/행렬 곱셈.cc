#include <stdio.h>


int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int mat1[n][m];
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            scanf("%d", &mat1[i][j]);
        }
    }

    int k;
    scanf("%d %d", &m, &k);

    int mat2[m][k];
    for(int i=0; i<m; i++) {
        for(int j=0; j<k; j++) {
            scanf("%d", &mat2[i][j]);
        }
    }

    int resmat[n][k];
    for(int i=0; i<n; i++) {
        for(int j=0; j<k; j++) {
            int res=0;
            for(int l=0; l<m; l++) {
                res+=mat1[i][l]*mat2[l][j];
            }
            resmat[i][j]=res;
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<k; j++) {
            printf("%d ", resmat[i][j]);
        }
        printf("\n");
    }



    return 0;

}
