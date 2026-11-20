#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n;
    scanf("%d", &n);

    int nums[n];
    double tot=0;
    for(int i=0; i<n;i++) {
        scanf("%d", &nums[i]);
        tot+=nums[i];
    }
    if(tot/n>-0.5 && tot/n<0) {
        printf("0\n");
    }
    else {
        printf("%1.f\n", tot/n);
    }



    qsort(nums, n, sizeof(int),compare);

    int med=nums[n/2];
    printf("%d\n", med);

    int mode_count = 0;
    int max_count = 0;
    int mode = nums[0];
    int current_count = 1;

    for (int i = 1; i < n; i++) {
        if (nums[i] == nums[i - 1]) {
            current_count++;
        }
        else {
            if (current_count > max_count) {
                max_count = current_count;
                mode_count = 1;
                mode = nums[i - 1];
            }
            else if (current_count == max_count) {
                mode_count++;
                if (mode_count == 2) {
                    mode = nums[i - 1];
                }
            }
            current_count = 1;
        }
    }

    if (current_count > max_count) {
        max_count = current_count;
        mode_count = 1;
        mode = nums[n - 1];
    } else if (current_count == max_count && mode_count == 1) {
        mode_count++;
        mode = nums[n - 1];
    }

    printf("%d\n", mode);

    printf("%d\n", nums[n - 1] - nums[0]);


    return 0;
}
