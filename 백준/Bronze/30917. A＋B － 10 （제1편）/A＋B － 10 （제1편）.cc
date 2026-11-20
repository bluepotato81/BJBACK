#include <stdio.h>
int main() {
    int r;
    for(int a=1; a<=9; a++){
        printf("? A %d\n", a);
        fflush(stdout);

        scanf("%d", &r);

        if(r==1){
            int b=0;
            for(b=1; b<=9;b++) {
                printf("? B %d\n", b);
                fflush(stdout);
                scanf("%d", &r);
                if(r==1) {
                    break;
                }
            }
            printf("! %d", a + b);
            break;
        }
    }
}
