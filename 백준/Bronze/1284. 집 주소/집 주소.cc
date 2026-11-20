#include <stdio.h>

int main() {
    while(1) {
        int a;
        scanf("%d", &a);
        if(a==0) {
            break;
        }
        int tot=1;
        while(a>0) {
            int k= a%10;
            if(k==1) {
                tot+=2;
            }
            else if(k==0) {
                tot+=4;
            }
            else {
                tot+=3;
            }
            a/=10;
            tot++;
        }
        printf("%d\n", tot);
    }
    return 0;
}
