#include <stdio.h>

int main() {
    int h, m;
    scanf("%d %d", &h, &m);
    if(m>=45) {
        m-=45;
    }
    else if(h>=1) {
        h-=1;
        m+=15;
    }
    else {
        h=23;
        m+=15;
    }

    printf("%d %d",h,m);


    return 0;
}
