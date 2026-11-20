#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int road[n-1];
    int city[n];
    for(int i=0; i<n-1; i++) {
        scanf("%d", &road[i]);
    }
    for(int i=0; i<n; i++) {
        scanf("%d", &city[i]);
    }

    long long result=0;
    int curprice=city[0];


    for(int i=1; i<n; i++) {
        result+=(long long)road[i-1]*curprice;
        if(city[i]<curprice) {
            curprice = city[i];
        }
    }

    printf("%lld", result);

    return 0;
}
