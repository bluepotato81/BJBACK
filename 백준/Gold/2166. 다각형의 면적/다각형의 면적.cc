#include <stdio.h>
#include <math.h>

int main() {
    int n;
    scanf("%d", &n);

    long long x[n];
    long long y[n];

    for(int i=0; i<n; i++) {
        scanf("%lld %lld", &x[i], &y[i]);
    }

    long long pluscom=0;
    long long mincom=0;

    for(int i=0; i<n-1; i++) {
        pluscom+=x[i]*y[i+1];
        mincom+=x[i+1]*y[i];
    }
    pluscom += x[n-1] * y[0];
    mincom += x[0] * y[n-1];

    double o=fabs((pluscom-mincom) / 2.0);

    printf("%.1f", round(o * 10) / 10);


    return 0;
}
