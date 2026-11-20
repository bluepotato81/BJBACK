#include <stdio.h>


int main() {
    int x;
    scanf("%d", &x);
    int a=0;
    for(int i=1; i<=x; i++) {
        a+=i;
    }
    printf("%d", a);



    return 0;
}
