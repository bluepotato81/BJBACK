#include <stdio.h>

int main() {
    int n=0;

    for(size_t i=0; i<5;i++) {
        int k;
        scanf("%d", &k);
        n+=k;
    }
    
    printf("%d", n);

    return 0;
}
