#include <stdio.h>

int main() {
    int a,b,c,d,e;
    scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);

    int k=1;
    while(1) {
        int n=0;
        if(k%a==0) {
            n++;
        }
        if(k%b==0) {
            n++;
        }
        if(k%c==0) {
            n++;
        }
        if(k%d==0) {
            n++;
        }
        if(k%e==0) {
            n++;
        }
        if(n>=3) {
            break;
        }
        k++;
    }

    printf("%d", k);

    return 0;
}
