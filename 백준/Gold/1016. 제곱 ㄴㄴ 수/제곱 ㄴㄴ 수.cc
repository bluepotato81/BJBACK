#include <stdio.h>
#include <math.h>

void prime(int *isprime, int limit) {
    for(int i=2;i<=limit;i++) {
        isprime[i]=1;
    }
    for (int i=2; i*i<=limit; i++) {
        if(isprime[i]) {
            for(int j=i*i; j<=limit ; j+=i) {
                isprime[j]=0;
            }
        }
    }
}

long long belnum(long long a, long long b) {
    int range= b-a+1;
    int issquare[1000001];
    for(long long i=0; i<range;i++) {
        issquare[i]=1;
    }

    int bs=sqrt(b);
    int isprime[bs+1];
    prime(isprime,bs);

    for(long long i=2;i<=bs;i++) {
        if(isprime[i]) {
            long long sq=i*i;
            long long start= (a%sq==0) ? a:a+(sq-a%sq);
            if(start<sq) {
                start=sq;
            }

            for(long long j=start; j<=b;j+=sq) {
                issquare[j-a]=0;
            }
        }
    }

    long long count = 0;
    for (long long i = 0; i < range; i++) {
        if (issquare[i]) count++;
    }

    return count;
}


int main() {
    long long min,max;
    scanf("%lld %lld", &min, &max);

    printf("%lld", belnum(min,max));

    return 0;
}
