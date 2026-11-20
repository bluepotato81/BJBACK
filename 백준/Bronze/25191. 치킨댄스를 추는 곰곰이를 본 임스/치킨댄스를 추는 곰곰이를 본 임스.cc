#include <stdio.h>

int main() {
    int n, a, b;
    scanf("%d", &n);
    scanf("%d %d", &a,&b);

    int ch=0;
    ch+=a/2;
    ch+=b;

    if(n>ch) {
        printf("%d", ch);
    }
    else {
        printf("%d", n);
    }

    return 0;
}
