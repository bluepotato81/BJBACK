#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);


    while(1) {
        printf("? %d", n);
        fflush(stdout);
        char ans;
        scanf("%c", &ans);
        if(ans=='Y') {
            break;
        }
    }

    printf("! %d", n);


    return 0;
}
