#include <stdio.h>
#include <math.h>

int main() {
    int n;
    scanf("%d", &n);

    int sol[n];

    int allpluscheck=1;
    int allminuscheck=1;
    for(int i=0; i<n; i++) {
        scanf("%d", &sol[i]);
        if(sol[i]<0) {
            allpluscheck=0;
        }
        if(sol[i]>0) {
            allminuscheck=0;
        }
    }

    if(allpluscheck==1) {
        printf("%d %d", sol[0],sol[1]);
        return 0;
    }

    if(allminuscheck==1) {
        printf("%d %d", sol[n-2],sol[n-1]);
        return 0;
    }


    int l=sol[0], r=sol[n-1];

    int val=abs(l+r);

    int left=0;
    int right=n-1;

    while(left<right) {
        int a,b,sum;
        a=sol[left];
        b=sol[right];
        sum=a+b;
        if(abs(sum)<val) {
            val=abs(sum);
            l=a;
            r=b;
        }
        if(sum>0) {
            right--;
        }
        else {
            left++;
        }
    }

    printf("%d %d", l, r);


    return 0;
}
