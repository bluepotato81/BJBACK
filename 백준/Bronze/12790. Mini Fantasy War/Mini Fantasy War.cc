#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    while(n--) {
        int q,w,e,r,t,y,u,i;
        scanf("%d %d %d %d %d %d %d %d", &q, &w, &e, &r, &t, &y, &u, &i);

        int a=q+t;
        int b=w+y;
        int c=e+u;
        int d=r+i;

        if(a<1) {
            a=1;
        }
        if(b<1) {
            b=1;
        }
        if(c<0) {
            c=0;
        }

        printf("%d\n", a+(5*b)+(2*c)+(2*d));

    }


    return 0;
}
