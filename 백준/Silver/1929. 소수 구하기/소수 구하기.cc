#include <stdio.h>

int nums[1000001];
int main() {
    int m,n;
    scanf("%d %d", &m, &n);


    for(int i=2; i*i<=n; i++) {
        if(nums[i]==0) {
            for(int j=i*i; j<=n; j+=i) {
                nums[j]++;
            }
        }
    }

    for(int i=m; i<=n; i++) {
        if(i>1 && nums[i]==0) {
            printf("%d\n", i);
        }
    }




    return 0;
}
