#include <stdio.h>

int main() {
    int a,b;
    scanf("%d %d",&a,&b);
    int c=a, d=b;

    while(c!=d) {
        if(c<d) {
            c+=a;
        }
        else {
            d+=b;
        }
    }

    int m=a*b;

    printf("%d\n%d", m/c, c);

    return 0;
}
