#include <stdio.h>

int main() {
    int a;
    scanf("%d",&a);
    int k=0;
    for(int i=1; i*i<=a;i++) {
        k++;
    }
    printf("%d", k);


    return 0;
}
