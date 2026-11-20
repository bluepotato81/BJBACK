#include <stdio.h>

int bag[101][100001]={0, };

int main() {
    int n,k;
    scanf("%d %d", &n, &k);
    int weight[n], value[n];
    for(int i=0; i<n; i++) {
        scanf("%d %d", &weight[i],&value[i]);
    }
    for(int i=0; i<n;i++) {
        for(int j=1; j<=k; j++) { //가능한 무게마다 모두 시도해봄
            if(weight[i]<=j) {
                if((value[i]+bag[i][j-weight[i]])>bag[i][j]) {
                    bag[i+1][j]=value[i]+bag[i][j-weight[i]];
                }
                else {
                    bag[i+1][j]=bag[i][j];
                }
            }
            else {
                bag[i+1][j]=bag[i][j];
            }
        }
    }

    printf("%d", bag[n][k]);

    return 0;
}
