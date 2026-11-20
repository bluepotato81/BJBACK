#include <stdio.h>
#include <stdlib.h>

int small(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}

int big(const void *a, const void *b) {
    return *(int*)b - *(int*)a;
}

int main() {
    int n;
    scanf("%d", &n);

    int a[n];
    int b[n];

    for(int i=0; i<n;i++) {
        scanf("%d", &a[i]);
    }

    for(int i=0; i<n;i++) {
        scanf("%d", &b[i]);
    }

    qsort(a,n,sizeof(int),small);
    qsort(b,n,sizeof(int),big);

    int comp=0;
    for(int i=0; i<n;i++) {
        comp+=a[i]*b[i];
    }

    printf("%d", comp);


    return 0;
}
