#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);

    for(int i=0; i<t; i++) {
        int k,n;
        scanf("%d", &k);
        scanf("%d", &n);
        int p[k+1][n];
        for(int j=0; j<n; j++) {
            p[0][j]=j+1;
        }
        for(int j=1; j<=k; j++) {
            for(int a=0; a<n; a++) {
                int sum=0;
                for(int l=0; l<=a; l++) {
                    sum+=p[j-1][l];
                }
                p[j][a]=sum;
            }
        }

        printf("%d\n", p[k][n-1]);

    }



    return 0;
}
