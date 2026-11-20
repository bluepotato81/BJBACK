#include <stdio.h>

int main() {
    int nums[10];
    int rem[42] = {0};
    int count=0;
    for(int i=0; i<10;i++) {
        scanf("%d ", &nums[i]);
    }
    for(int i=0;i<10;i++) {
        if(rem[nums[i]%42]==0) {
            rem[nums[i]%42]++;
        }
    }

    for(int i=0; i<42;i++) {
        if(rem[i]!=0) {
            count++;
        }
    }

    printf("%d \n", count);

    return 0;
}

