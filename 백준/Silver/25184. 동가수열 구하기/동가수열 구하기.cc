#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int ans[n];

    if(n%2==1) {
        for(int i=0; i<n; i+=2) {
            ans[i]=(n/2)+1+(i/2);
        }
        for(int i=1;i<n;i+=2) {
            ans[i]=(i+1)/2;
        }
        for(int i=0; i<n;i++) {
            printf("%d ", ans[i]);
        }
    }
    else {
        for(int i=0; i<n; i+=2) {
            ans[i]=(n/2)-(i/2);
        }
        for(int i=1;i<n;i+=2) {
            ans[i]=n-((i-1)/2);
        }
        for(int i=0; i<n;i++) {
            printf("%d ", ans[i]);
        }
    }

    return 0;
}
