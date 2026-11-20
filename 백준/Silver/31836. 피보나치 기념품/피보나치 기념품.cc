#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    if(n%3==0) {
        printf("%d\n", (n/3)*2);
        for(int i=1; i<=n;i++) {
            if(i%3!=0) {
                printf("%d ", i);
            }
        }
        printf("\n");

        printf("%d\n", n/3);
        for(int i=1; i<=n;i++) {
            if(i%3==0) {
                printf("%d ", i);
            }
        }
    }
    else if(n%3==1) {
        printf("%d\n", ((n-1)/3)*2);
        for(int i=1; i<n;i++) {
            if(i%3!=0) {
                printf("%d ", i+1);
            }
        }
        printf("\n");

        printf("%d\n", (n-1)/3);
        for(int i=1; i<n;i++) {
            if(i%3==0) {
                printf("%d ", i+1);
            }
        }
    }
    else {
        printf("%d\n", ((n/3)*2)+1);
        printf("1 ");
        for(int i=3; i<=n;i++) {
            if((i-2)%3!=0) {
                printf("%d ", i);
            }
        }
        printf("\n");

        printf("%d\n", (n/3)+1);
        printf("2 ");
        for(int i=3; i<=n;i++) {
            if((i-2)%3==0) {
                printf("%d ", i);
            }
        }
    }

    return 0;
}
