#include <stdio.h>

int main() {
    int b,n;
    while(1) {
        scanf("%d %d", &b, &n);
        if(b==0 && n==0) {
            break;
        }
        
        int k=1;
        while(1) {
            int comp=1;
            for(int i=0; i<n;i++) {
                comp*=k;
            }
            
            if(comp>b) {
                break;
            } 
            k++;
        }
        
        int small=1;
        int big=1;
        for(int i=0; i<n;i++) {
            small*=k-1;
        }
        for(int i=0; i<n;i++) {
            big*=k;
        }
        
        if(b-small>big-b) {
            printf("%d\n", k);
        }
        else {
            printf("%d\n", k-1);
        }
        
    } 
    
    return 0;
}