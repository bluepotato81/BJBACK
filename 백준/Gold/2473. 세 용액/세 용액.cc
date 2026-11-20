#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n;
    scanf("%d", &n);

    int sol[n];

    int allpluscheck=1;
    int allminuscheck=1;
    for(int i=0; i<n; i++) {
        scanf("%d", &sol[i]);
        if(sol[i]<0) {
            allpluscheck=0;
        }
        if(sol[i]>0) {
            allminuscheck=0;
        }
    }

    qsort(sol, n, sizeof(int), compare);

    if(allpluscheck==1) {
        printf("%d %d %d", sol[0],sol[1], sol[2]);
        return 0;
    }

    if(allminuscheck==1) {
        printf("%d %d %d",sol[n-3], sol[n-2],sol[n-1]);
        return 0;
    }

    int num1, num2, num3;

    long long min=LONG_MAX;

    for(int i=0; i<n-2; i++) {
        int l=i+1;
        int r=n-1;
        while(l<r) {
            long long com=sol[i]+sol[l]+sol[r];
            if(abs(com)<min) {
                min=abs(com);
                num1=sol[i];
                num2=sol[l];
                num3=sol[r];
            }
            if(com<0) {
                l++;
            }
            else {
                r--;
            }
        }
    }


    printf("%d %d %d", num1, num2, num3);



    return 0;
}
