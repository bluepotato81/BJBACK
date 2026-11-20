#include <stdio.h>

int gcd(int a, int b) {
    while (b!=0) {
        int temp=b;
        b=a%b;
        a=temp;
    }
    return a;
}

int lcm(int a, int b) {
    return (a*b)/gcd(a,b);
}

int main() {
    int t;
    scanf("%d", &t);
    for(int i=0; i<t; i++) {
        int m,n,x,y;
        scanf("%d %d %d %d", &m, &n, &x, &y);
        if(x==m) {
            x=0;
        }
        if(y==n) {
            y=0;
        }
        int lim=lcm(m,n);
        int num=x;


        while(num<=lim) {
            if(num%n==y) {
                break;
            }
            num+=m;
        }
        if(num>lim) {
            printf("-1\n");
        }
        else if(num==0) {
            printf("%d\n", lim);
        }
        else {
            printf("%d\n", num);
        }
    }

    return 0;
}
