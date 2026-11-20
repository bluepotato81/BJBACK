#include <stdio.h>

int main() {
    char s;
    scanf("%c", &s);
    
    float k;
    if(s=='A') {
        k=4.0;
    }
    if(s=='B') {
        k=3.0;
    }
    if(s=='C') {
        k=2.0;
    }
    if(s=='D') {
        k=1.0;
    }
    if(s=='F') {
        printf("0.0");
        return 0;
    }
    scanf("%c", &s);
    if(s=='+') {
        k+=0.3;
    }
    if(s=='-') {
        k-=0.3;
    }
    printf("%.1f", k);
    
    return 0;
}