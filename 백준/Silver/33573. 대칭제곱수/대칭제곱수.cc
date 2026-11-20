#include <stdio.h>
#include <math.h>

long long flip(long long n) {
    long long rev=0;
    while(n>0) {
        int digit=n%10;
        rev*=10;
        rev+=digit;
        n/=10;
    }
    return rev;
}

int check(long long n) {
    double sq=sqrt(n);
    long long sqi=(long long)sq;
    if(sqi*sqi==n) {
        return 1;
    }
    else {
        return 0;
    }
}

int main() {
    int n;
    scanf("%d", &n);


    long long in;
    for(int i=0; i<n; i++) {
        scanf("%lld", &in);
        if(!check(in)) {
            printf("NO\n");
            continue;
        }

        long long fl=flip(in);

        if(check(fl)) {
            printf("YES\n");
        }
        else {
            printf("NO\n");
        }

    }
    return 0;
}
