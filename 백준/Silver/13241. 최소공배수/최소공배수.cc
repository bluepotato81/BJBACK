#include <stdio.h>

int main() {
    long long n,m;
    scanf("%lld %lld",&n, &m);

    long long nm=n,mm=m;
    if(n<m) {
        while(1) {
            if(mm%n==0) {
                break;
            }
            else {
                mm+=m;
            }
        }
        printf("%lld", mm);
    }
    else if(m<n) {
        while(1) {
            if(nm%m==0) {
                break;
            }
            else {
                nm+=n;
            }
        }
        printf("%lld", nm);
    }
    else {
        printf("%lld",n);
    }




    return 0;
}
