#include <stdio.h>

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int num=0;
    int checker=0;
    for(int i=1; i<=n; i++) {
        if(n%i==0) {
            num++;
        }
        if(num==k) {
            checker=i;
            break;
        }
    }
    printf("%d", checker);
}
