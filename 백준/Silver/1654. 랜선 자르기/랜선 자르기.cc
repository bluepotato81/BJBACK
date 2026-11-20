#include <stdio.h>
#include <stdlib.h>

int compare_integers(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int k,n;
    scanf("%d %d", &k, &n);
    long long num[k];
    long long max=0;
    for(int i=0; i<k; i++) {
        scanf("%lld", &num[i]);
        if(num[i]>max) {
            max=num[i];
        }
    }
    long long l=0, r=max;

    if (n==1)
    {
        printf("%lld\n", r);
        return 0;
    }
    
    int check = 0;
    if (k>=2)
    {
        for (int i=0; i < k-1; i++)
        {
            if (num[i] == num[i + 1])
            {
                check++;
            }
        }
        if (check == k - 1)
        {
            printf("%lld\n", num[0]);
            return 0;
        }
    }
    
    while(l<r) {
        long long m= (l+r)/2;
        int temp=0;
        for(int i=0; i<k; i++) {
            temp+=num[i]/m;
        }
        if(temp>=n) {
            l=m+1;
        }
        else if(temp<n) {
            r=m;
        }
    }
    printf("%lld\n", l-1);


    return 0;
}
