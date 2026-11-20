#include <stdio.h>

int main() {
    int a,b,c;
    scanf("%d %d %d", &a, &b, &c);

    if(a+b<=c) {
        printf("%d", a+b+a+b-1);
    }
    else if(a+c<=b) {
         printf("%d", a+c+a+c-1);
    }
    else if(b+c<=a) {
        printf("%d", b+c+b+c-1);
    }
    else {
        printf("%d", a+b+c);
    }
    return 0;
}

