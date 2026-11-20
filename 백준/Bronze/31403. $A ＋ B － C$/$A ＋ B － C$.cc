#include <stdio.h>

int main() {
    int a,b,c;
    scanf("%d%d%d", &a, &b, &c);
    int d;
    if(b>=1000) {
        d=a*10000+b-c;
    }
    else if(b>=100) {
        d=a*1000+b-c;
    }
    else if(b>=10) {
        d=a*100+b-c;
    }
    else {
        d=a*10+b-c;
    }
    printf("%d\n%d", a+b-c, d);
    return 0;
}
