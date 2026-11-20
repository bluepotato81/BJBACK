#include <stdio.h>

int main() {
    long long n,k;
    scanf("%lld\n%lld",&n, &k);

    long long s=0;
    long long e=n*n;

    int res;
    while(s<=e) {
        long long mid=(s+e)/2;
        long long count=0;

        for(long long i=1; i<=n; i++) {
            if(mid/i<n) {
                count+=mid/i;
            }
            else {
                count+=n;
            }
        }

        if(count>=k) {
            res=mid;
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }

    printf("%lld", res);



    return 0;
}
