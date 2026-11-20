#include <stdio.h>
#include <stdlib.h>

void swap(long long *a, long long *b) {
    long long temp=*a;
    *a=*b;
    *b=temp;
}

long long check(long long a,long long b, long long c) {
    if(b*b*(a+c)*(a+c)<2*a*a*c*c) {
        return 0;
    }
    else {
        return 1;
    }

}
long long ans=0;
void permute(long long arr[], long long start, long long end) {
    if(start==end) {
        long long see=1;
        for(long long i=1; i<7;i++) {
            if(!check(arr[i-1], arr[i], arr[i+1])) {
                see=0;
                break;
            }
        }
        if(!check(arr[7], arr[0], arr[1])) {
            see=0;
        }
        if(!check(arr[6], arr[7], arr[0])) {
            see=0;
        }
        if(see) {
            ans++;
        }
        return;
    }

    for(long long i=start; i<=end;i++) {
        swap(&arr[start], &arr[i]);
        permute(arr, start+1, end);
        swap(&arr[start], &arr[i]);
    }

}


int main() {
    long long stat[8];

    for(long long i=0; i<8;i++) {
        scanf("%lld", &stat[i]);
    }
    permute(stat, 0,7);

    printf("%lld", ans);

    return 0;
}
