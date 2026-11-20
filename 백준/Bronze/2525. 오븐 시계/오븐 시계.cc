#include <stdio.h>


int main() {
    int x,y;
    int a;
    scanf("%d %d", &x, &y);
    scanf("%d", &a);
    int min=60*x+y;
    min+=a;
    int h=min/60, m=min%60;
    if(h>=24) {
        h-=24;
    }
    printf("%d %d", h, m);

    return 0;
}


