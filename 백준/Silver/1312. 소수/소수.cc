#include <stdio.h>

int main() {
    int a,b,n;
    scanf("%d %d %d", &a, &b, &n);

    int res;
    while(n--) {
        a*=10;
        res=a/b;
        a%=b;
    }

    printf("%d", res%10);

    return 0;

}
