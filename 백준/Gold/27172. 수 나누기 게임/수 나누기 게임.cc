#include <stdio.h>

int innum[100000];
int numcheck[1000001];
int ans[1000001];

int main() {
    int n;
    scanf("%d", &n);

    int a;
    for(int i=0; i<n; i++) {
        scanf("%d", &a);
        innum[i]=a;
        numcheck[a]=1;
    }

    for(int i=0; i<n; i++) {
        int k=innum[i];
        for(int j=k*2; j<1000001; j+=k) {
            if(numcheck[j]) {
                ans[j]--;
                ans[k]++;
            }
        }
    }

    for(int i=0; i<n; i++) {
        printf("%d ", ans[innum[i]]);
    }



    return 0;
}
