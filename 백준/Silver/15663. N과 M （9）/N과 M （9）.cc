#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int val;
    int use;
}num;

int compare(const void* a, const void* b) {
    const num *numa = (const num *)a;
    const num *numb = (const num *)b;

    return (numa->val-numb->val);
}

num list[8];

void printer(int nums[],int n, int m, int step) {
    if (step == m) {
        for (int j = 0; j < m; j++) {
            printf("%d ", nums[j]);
        }
        printf("\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        if (list[i].use == 1 || (i > 0 && list[i].val == list[i-1].val && list[i-1].use == 0)) {
            continue;
        }

        nums[step] = list[i].val;
        list[i].use = 1;
        printer(nums, n, m, step + 1);
        list[i].use = 0;
    }

}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int t;
    int len=0;
    for(int i=0; i<n; i++) {
        scanf("%d", &t);
        list[len].val=t;
        list[len].use=0;
        len++;
    }


    qsort(list, len, sizeof(num), compare);


    int nums[m];

    printer(nums, len, m, 0);


    return 0;
}
