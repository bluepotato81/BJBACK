#include <stdio.h>
#include <stdlib.h>

// Comparison function for qsort
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int n;
    int nums[100001];
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    // Sort the array
    qsort(nums, n, sizeof(int), compare);

    int tar;
    scanf("%d", &tar);
    int start = 0;
    int end = n - 1;
    int count = 0;

    while (start < end) {
        int sum = nums[start] + nums[end];
        if (sum < tar) {
            start++;
        } else if (sum > tar) {
            end--;
        } else {
            count++;
            start++;
            end--;
        }
    }

    printf("%d\n", count);

    return 0;
}
