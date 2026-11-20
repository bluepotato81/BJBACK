#include <stdio.h>

int main() {
    int a,b,c,d;
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    scanf("%d", &d);
    if(a==b && a==c && a==d) {
        printf("Fish At Constant Depth");
    }
    else if(a<b&& b<c&& c<d) {
        printf("Fish Rising");
    }
    else if(a>b&& b>c&& c>d) {
        printf("Fish Diving");
    }

    else {
        printf("No Fish");
    }


    return 0;
}
