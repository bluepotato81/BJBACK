#include <stdio.h>

int ans[100001];

void swap(int x, int y){
    int t=ans[x];
    ans[x]=ans[y];
    ans[y]=t;
}

int main() {
    int n,k;
    scanf("%d %d", &n, &k);

    int ns=n-1-k;

    for(int i=1; i<=n;i++) {
        ans[i]=i;
    }

    if(n==k) {
        printf("Impossible");
        return 0;
    }

    if(ns%2==0) {
        for(int i=0; i<ns; i+=2) {
            swap(n-i, n-i-1);
        }
        for(int i=1; i<=n;i++) {
            printf("%d ", ans[i]);
        }
    }
    else {
        for(int i=0; i<ns-2; i+=2) {
            swap(n-i, n-i-1);
        }
        swap(1,2);
        for(int i=1; i<=n;i++) {
            printf("%d ", ans[i]);
        }
    }

    return 0;
}
