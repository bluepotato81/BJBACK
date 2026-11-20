#include <stdio.h>

int main() {
    int a,b,c;
    scanf("%d %d %d", &a, &b, &c);

    int raw=a*6916+b*4845+c*4200;


    if(raw%7980) {
        printf("%d", raw%7980);
    }
    else {
        printf("7980");
    }
    return 0;
}
