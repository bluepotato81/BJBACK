#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    for(int i=0; i<2*n;i++) {
        for(int j=0; j<2*n-i-1;j++) {
            printf(" ");
        }
        printf("*");
        if(i<n) {
            for(int j=0; j<n;j++) {
                printf(" ");
            }
        }
        else {
            for(int j=0;j<n+1+(2*(i-n));j++){
                printf(" ");  
            }
        }
        printf("*");
        if(i<n) {
            for(int j=0; j<2*i+1;j++) {
                printf(" ");
            }
        }
        else {
            for(int j=0;j<(2*n-1)-2*(i-n);j++){
                printf(" ");  
            }
        }
        printf("*");
        if(i<n) {
            for(int j=0; j<n-i-1;j++) {
                printf(" ");
            }
        }
        else {
            for(int j=0;j<i-n;j++){
                printf(" ");  
            }
        }
        printf("\n");
    }
    
    return 0;
}