#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int nums[n];

    int k;
    if(n%2==1){
        k=1;
    }
    else{
        k=0;
    }

    for(int i=0; i<=(n/2)-1;i++) {
        nums[i]=(i+1)*2-1+k;
    }

    for(int i=(n/2); i<n; i++) {
        nums[i]=n-((i-(n/2))*2);
    }

    for(int i=0; i<n;i++) {
        printf("%d ", nums[i]);
    }

    return 0;
}
