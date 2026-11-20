#include <stdio.h>

int main() {
    int nums[5];
    for(int i=0; i<5;i++) {
        scanf("%d", &nums[i]);
    }

    int check=0;
    while(check!=4) {
        check=0;
        for(int i=0; i<4; i++) {
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

    int av=0;
    for(int i=0; i<5; i++) {
        av+=nums[i];
    }
    printf("%d\n%d", av/5, nums[2]);



    return 0;
}

