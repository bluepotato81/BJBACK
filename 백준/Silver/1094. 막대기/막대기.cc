#include <stdio.h>

int main() {
    int a;
    scanf("%d", &a);
    
    int k=0;
    while(a>0) {
        k+=a%2;
        a/=2;
    }
    
    printf("%d", k);
    
    return 0;
}