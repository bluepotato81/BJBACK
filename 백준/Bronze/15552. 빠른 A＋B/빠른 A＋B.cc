#include <stdio.h>


int main() {
    int x;
    scanf("%d", &x);
    for(int i=0; i<x; i++) {
        int a,b;
        scanf("%d %d", &a, &b);
        printf("%d\n", a+b);
    }


    return 0;
}
