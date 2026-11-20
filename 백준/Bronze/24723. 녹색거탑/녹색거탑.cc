#include <stdio.h>

int main() {
    int a;
    scanf("%d", &a);
    int k=1;
    for(int i=0; i<a; i++) {
        k*=2;
    }

    printf("%d", k);
    return 0;
}
