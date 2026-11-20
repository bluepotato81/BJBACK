#include <stdio.h>
#include <stdlib.h>

int compare_integers(const void *a, const void *b) {
    long long int_a = *(const long long*)a;
    long long int_b = *(const long long*)b;
    if (int_a < int_b) return -1;
    if (int_a > int_b) return 1;
    return 0;
}

int main()
{
	int n;
	scanf("%d", &n);
	long long a[n];
	for(int i=0; i<n; i++) {
        scanf("%lld", &a[i]);
	}

	qsort(a, n, sizeof(long long), compare_integers);

    int m;
    scanf("%d", &m);
    for(int i=0; i<m; i++) {
        long long k;
        scanf("%lld", &k);
        int lo=0, hi=n-1;
        
        int check=0;
        while(lo<=hi) {
            int mid = (lo+hi)/2;
            if(a[mid]==k) {
                check++;
                break;
            }
            else if(a[mid]<k) {
                lo=mid+1;
            }
            else {
                hi=mid-1;
            }
        }
        printf("%d\n", check);
    }

	return 0;
}
