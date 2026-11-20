#include <stdio.h>

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int tot=0, min=10000;
    for(int i=n; i<=k; i++) {
        int divnum=0;
        for(int j=1; j<=i; j++) {
            if(i%j==0) {
                divnum++;
            }
        }
        if(divnum==2) {
            tot+=i;
            if(i<min) {
                min=i;
            }
        }
    }
    if(tot==0) {
        printf("-1");
    }
    else {
        printf("%d\n%d", tot,min);
    }
}
