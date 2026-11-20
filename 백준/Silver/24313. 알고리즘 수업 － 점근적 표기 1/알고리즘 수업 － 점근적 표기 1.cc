#include <stdio.h>

int main() {
    int a,b,c,d;
    scanf("%d %d", &a, &b);
    scanf("%d",&c);
    scanf("%d", &d);

    if((c-a)<0) {
        printf("0");
    }

    else if((c-a)==0) {
        if(b<=0) {
            printf("1");
        }
        else {
            printf("0");
        }
    }
    else {
        if((c*d-a*d-b)<0) {
            printf("0");
        }
        else {
            printf("1");
        }
    }


    return 0;
}

