#include <stdio.h>

int main() {
    int p[4];
    for(int i=0; i<4; i++) {
        scanf("%d", &p[i]);
    }
    
    int x,y,r;
    scanf("%d %d %d", &x, &y, &r);
    
    int k=0;
    
    for(int i=0; i<4; i++) {
        if(p[i]==x) {
            k=i+1;
        }
    }
    
    printf("%d", k);
    
    return 0;
}