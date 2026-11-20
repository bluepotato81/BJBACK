#include <stdio.h>

void printer(int nums[],int n, int m, int step, int min) {
    if(m-1==step) {
        for(int i=min; i<=n; i++) {
            int check=0;
            for(int j=0; j<step; j++) {
                if(i==nums[j]) {
                    check++;
                }
            }
            if(!check) {
                nums[step]=i;
                for(int i=0; i<step+1; i++) {
                    printf("%d ", nums[i]);
                }
                printf("\n");
            }
        }
    }
    else {
        for(int i=min; i<=n; i++) {
            int check=0;
            for(int j=0; j<step; j++) {
                if(i==nums[j]) {
                    check++;
                }
            }
            if(!check) {
                nums[step]=i;
                printer(nums, n, m, step+1, i+1);
            }
        }
    }

}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int num[m];

    printer(num, n, m, 0, 1);


    return 0;
}
