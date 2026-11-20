#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int a=1;
    int f=0, t=0;
    int min=10000;
    while(a) {
        while(3*t+5*f<n) {
            t++;
        }
        if(3*t+5*f==n && min>t+f) {
                min=t+f;
        }
        f++;
        t=0;
        if(5*f>n) {
            break;
        }
    }

    if(min==10000) {
        printf("-1");
    }
    else {
        printf("%d", min);
    }



    return 0;
}

