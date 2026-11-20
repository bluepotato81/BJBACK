#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int o=0;
    for(int i=1; i<=n; i++){
        o+=i;
    }
    printf("%d\n%d\n", o, o*o);
    int t=0;
    for(int i=1; i<=n; i++) {
        t+=i*i*i;
    }
    printf("%d", t);
    
    return 0;
}