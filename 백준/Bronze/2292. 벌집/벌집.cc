#include <stdio.h>

int main() {

    int a=0, b=1, c=1;
    int n;
    scanf("%d", &n);
    if(n==1) {
        printf("1");
        return 0;
    }
    while(n>c) {
        c+=b-1;
        b+=6;
        a++;
    }
    printf("%d", a);


    return 0;
}
