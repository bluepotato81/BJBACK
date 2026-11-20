#include <stdio.h>

int nums[1000001];
int main() {
    while(1) {
        int n;
        scanf("%d",&n);

        if(n==0) {
            break;
        }

        int m=2*n;
        for(int i=2; i*i<=m; i++) {
            if(nums[i]==0) {
                for(int j=i*i; j<=m; j+=i) {
                    nums[j]++;
                }
            }
        }

        int a=0;
        for(int i=n+1; i<=m; i++) {
            if(i>1 && nums[i]==0) {
                a++;
            }
        }
        printf("%d\n", a);
    }





    return 0;
}
