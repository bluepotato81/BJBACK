#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int ans[n];

    for(int i=0; i<n;i+=2) {
        if(n%2==1) {
            ans[i]=(i/2)+1;
        }
        else {
            ans[i]=n-i/2;
        }
    }
    for(int i=1; i<n;i+=2) {
        if(n%2==1) {
            ans[i]=n-((i-1)/2);
        }
        else {
            ans[i]=(i+1)/2;
        }
    }

    for(int i=0; i<n; i++) {
        printf("%d ", ans[i]);
    }

    return 0;
}
