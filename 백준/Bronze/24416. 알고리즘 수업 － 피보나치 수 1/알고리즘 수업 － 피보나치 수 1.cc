#include <stdio.h>

int r=0;
int d=0;

int fib(int n) {
    if(n==1 || n==2) {
        r++;
        return 1;
    }
    else {
        return (fib(n-1)+fib(n-2));
    }
}

int fibonacci(int n) {
    int f[n];
    f[0]=1;
    f[1]=1;
    for(int i=2; i<n; i++) {
        d++;
        f[i]=f[i-1]+f[i-2];
    }
    return f[n-1];
}


int main() {
    int n;
    scanf("%d", &n);
    fib(n);
    fibonacci(n);
    printf("%d %d", r, d);

    return 0;
}
