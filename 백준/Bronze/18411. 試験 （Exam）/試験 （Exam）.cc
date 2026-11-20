#include <stdio.h>

int main() {
    int a,b,c;
    scanf("%d %d %d", &a, &b, &c);
    
    int max=0;
    int maxin;
    if(a>max) {
        max=a;
        maxin=1;
    }
    if(b>max) {
        max=b;
        maxin=2;
    }
    if(c>max) {
        max=c;
        maxin=3;
    }
    
    int secmax=0;
    if(maxin==1) {
        if(b>secmax) {
            secmax=b;
        }
        if(c>secmax) {
            secmax=c;
        }    
    }
    if(maxin==2) {
        if(a>secmax) {
            secmax=a;
        }
        if(c>secmax) {
            secmax=c;
        }    
    }
    if(maxin==3) {
        if(a>secmax) {
            secmax=a;
        }
        if(b>secmax) {
            secmax=b;
        }    
    }
    
    printf("%d", max+secmax);
    return 0;
}