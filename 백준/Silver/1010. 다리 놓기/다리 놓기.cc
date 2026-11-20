#include <stdio.h>

int main() {
    int a;
    scanf("%d", &a);
    for(int i=0; i<a; i++) {
        int n,m;
        scanf("%d %d", &n,&m);
        if(n>m/2) {
            n=m-n;
        }
        long long nf=1, mf=1;
        for(int j=m; j>=m-n+1; j--) {
            mf*=j;
        }
        for(int j=1; j<=n; j++) {
            nf*=j;
        }
        printf("%lld\n", mf/nf);


    }
    return 0;
}
