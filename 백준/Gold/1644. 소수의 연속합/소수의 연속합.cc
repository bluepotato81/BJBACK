#include <stdio.h>

int nums[4000001];
int primesum[4000000];

int main() {
    int n;
    scanf("%d", &n);


    for(int i=2; i*i<=n; i++) {
        if(nums[i]==0) {
            for(int j=i*i; j<=n; j+=i) {
                nums[j]++;
            }
        }
    }

    int primenum=1;
    primesum[0]=0;

    for(int i=2; i<=n; i++) {
        if(i>1 && nums[i]==0) {
            primesum[primenum]=primesum[primenum-1]+i;
            primenum++;
        }
    }

    int l=0, r=0;

    int res=0;
    while(r<primenum) {
        if(primesum[r]-primesum[l]<n) {
            r++;
        }
        else if(primesum[r]-primesum[l]>n) {
            l++;
        }
        else {
            res++;
            r++;
        }
    }

    printf("%d", res);


    return 0;
}
