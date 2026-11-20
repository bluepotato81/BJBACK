#include <stdio.h>

void printer(int nums[],int n, int m, int step) {
    if(m-1==step) {
        for(int i=1; i<=n; i++) {
            nums[step]=i;
            for(int i=0; i<step+1; i++) {
                printf("%d ", nums[i]);
            }
                printf("\n");
        }
    }
    else {
        for(int i=1; i<=n; i++) {
            nums[step]=i;
            printer(nums, n, m, step+1);
        }
    }

}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int num[m];

    printer(num, n, m, 0);


    return 0;
}
