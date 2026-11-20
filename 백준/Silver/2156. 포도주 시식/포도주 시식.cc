#include <stdio.h>

int maxe(int a,int b) {
    if(a>b) {
        return a;
    }
    else {
        return b;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int wine[n];
    for(int i=0; i<n; i++) {
        scanf("%d", &wine[i]);
    }
    int max[n];
    max[0]=wine[0];
    max[1]=wine[0]+wine[1];

    for(int i=2; i<n; i++) {
        max[i]=maxe(max[i-3]+wine[i-1]+wine[i],maxe(max[i-2]+wine[i],max[i-1]));
    }

    printf("%d", max[n-1]);
    return 0;
}

