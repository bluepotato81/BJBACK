#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int nums[n];
    for(int i=0; i<n;i++) {
        scanf("%d", &nums[i]);
    }

    int check=0;
    while(check!=n-1) {
        check=0;
        for(int i=0; i<n-1; i++) {
            if(nums[i]>nums[i+1]) {
                int pl;
                pl=nums[i];
                nums[i]=nums[i+1];
                nums[i+1]=pl;
            }
            else {
                check++;
            }
        }
    }

    for(int i=0; i<n; i++) {
        printf("%d\n", nums[i]);
    }



    return 0;
}

