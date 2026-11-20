#include <stdio.h>

int main() {
    int a,b,c;
    scanf("%d %d %d", &a, &b, &c);
    int n;
    scanf("%d", &n);
    
    c+=n;
    int up=c/60;
    c=c%60;
    
    b+=up;
    up=b/60;
    b=b%60;
    
    a+=up;
    a=a%24;
    
    printf("%d %d %d", a,b,c);
    
    return 0;
}