#include <stdio.h>
#include <stdlib.h>


int compare(const void* a, const void* b) {
    return (*(int*)a-*(int*)b);
}

int list[8];

void printer(int nums[],int n, int m, int step) {
    if(m-1==step) {
        for(int i=0; i<n; i++) {
            int check=0;
            for(int j=0; j<step; j++) {
                if(i==nums[j]) {
                    check++;
                }
            }
            if(!check) {
                nums[step]=i;
                for(int i=0; i<step+1; i++) {
                    printf("%d ", list[nums[i]]);
                }
                printf("\n");
            }
        }
    }
    else {
        for(int i=0; i<n; i++) {
            int check=0;
            for(int j=0; j<step; j++) {
                if(i==nums[j]) {
                    check++;
                }
            }
            if(!check) {
                nums[step]=i;
                printer(nums, n, m, step+1);
            }
        }
    }

}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for(int i=0; i<n; i++) {
        scanf("%d", &list[i]);
    }

    qsort(list, n, sizeof(int), compare);


    int num[m];

    printer(num, n, m, 0);


    return 0;
}
