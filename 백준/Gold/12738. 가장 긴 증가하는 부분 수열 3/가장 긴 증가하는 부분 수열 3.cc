#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int nums[n];

    for(int i=0; i<n; i++) {
        scanf("%d", &nums[i]);
    }

    int list[n];
    list[0]=nums[0];
    int listlen=1;
    for(int i=0; i<n; i++) {
        if(list[listlen-1]<nums[i]) {
            list[listlen++] = nums[i];
        }
        else {
            int l=0;
            int r=listlen;

            while(l<r) {
                int mid=(l+r)/2;
                if(list[mid] <nums[i]) {
                    l=mid+1;
                }
                else {
                    r=mid;
                }
            }
            list[r] = nums[i];
        }
    }

    printf("%d", listlen);



    return 0;
}
