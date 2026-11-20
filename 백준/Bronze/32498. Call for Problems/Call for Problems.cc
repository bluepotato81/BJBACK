#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int e=0;

    int a;
    for(int i=0; i<n; i++) {
        scanf("%d", &a);
        if(a%2) {
            e++;
        }
    }

    printf("%d", e);


    return 0;
}
