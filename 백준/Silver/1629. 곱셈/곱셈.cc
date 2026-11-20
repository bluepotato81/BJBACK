#include <stdio.h>

long long a,b,c;

long long f(long long x) {
    if(x==1) {
        return a%c;
    }
    long long k = x/2;
    if(x%2==1) {
        return ((f(k)*f(k+1))%c);
    }
    else {
        return ((f(k)*f(k))%c);
    }
}

int main() {
    scanf("%d %d %d", &a, &b, &c);
    printf("%lld", f(b));

    return 0;

}
