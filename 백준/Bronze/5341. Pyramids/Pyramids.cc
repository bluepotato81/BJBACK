#include <stdio.h>

int main() {
    int k;
    while(1) {
        scanf("%d", &k);
        if(!k) {
            break;
        }
        int l=0;
        while(k--) {
            l+=k+1;
        }
        printf("%d\n", l);
    }
    
    return 0;
}