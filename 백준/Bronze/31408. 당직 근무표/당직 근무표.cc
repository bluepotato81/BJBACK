#include <stdio.h>

int sol[100000];

int main() {
    int n;
    scanf("%d", &n);

    int a;
    for(int i=0; i<n; i++) {
        scanf("%d", &a);
        sol[a-1]++;
    }

    int lim=(n+1)/2;
    for(int i=0; i<100000; i++) {
        if(sol[i]>lim) {
            printf("NO");
            return 0;
        }

    }

    printf("YES");

    return 0;
}
