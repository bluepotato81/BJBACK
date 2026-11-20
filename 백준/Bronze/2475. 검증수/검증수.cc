#include <stdio.h>

int main() {

    int a=0;
    for(int i=0;i<5;i++) {
        int f;
        scanf("%d",&f);
        a+=f*f;
    }

    printf("%d",a%10);

    return 0;
}
