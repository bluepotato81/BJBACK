#include <stdio.h>

int main() {
    int n;
    long long m;
    scanf("%d %lld", &n, &m);

    int trees[n];
    int max=0;
    for(int i=0; i<n; i++) {
        scanf("%d", &trees[i]);
        if(trees[i]>max) {
            max=trees[i];
        }
    }

    int l=0;
    int r=max;
    int end=0;

    while(l<=r) {
        int mid=(l+r)/2;
        long long ms=0;
        for(int i=0; i<n; i++) {
            if(trees[i]>mid) {
                ms+=(long long)(trees[i]-mid);
            }
        }
        if(ms>=m) {
            end=mid;
            l=mid+1;
        }
        else if(ms<m) {
            r=mid-1;
        }
    }

    printf("%d", end);

    return 0;
}
