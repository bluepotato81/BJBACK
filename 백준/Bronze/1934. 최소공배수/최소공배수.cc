#include <stdio.h>

int main() {
    int a;
    scanf("%d", &a);
    for(int i=0; i<a; i++) {
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
        printf("%lld\n", mm);
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
        printf("%lld\n", nm);
    }
    else {
        printf("%lld\n",n);
    }
    }



    return 0;
}
