#include <stdio.h>

int main() {
    int n,k;
    scanf("%d %d", &n, &k);
    int temp[n];
    int sum[n];
    for(int i=0; i<n; i++) {
        scanf("%d", &temp[i]);
    }
    sum[0]=temp[0];
    for(int i=1; i<n; i++) {
        sum[i]=sum[i-1]+temp[i];
    }

    int max=sum[k-1];
    for(int i=k; i<n; i++) {
        if(max<sum[i]-sum[i-k]) {
            max=sum[i]-sum[i-k];
        }
    }

    printf("%d", max);

    return 0;
}
