#include <stdio.h>

int main() {
    int a;
    scanf("%d", &a);
    
    printf("%d", !((a-2)%7));
    
    return 0;
}