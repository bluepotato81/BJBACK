#include <stdio.h>

int main() {
    int n=1;
    while(1) {
        int a;
        scanf("%d", &a);
        if(!a) {
            break;
        }
        
        int k;
        while(a--) {
            scanf("%d", &k);
        }
        printf("Case %d: Sorting... done!\n", n);
        n++;
    }
    
    return 0;
}