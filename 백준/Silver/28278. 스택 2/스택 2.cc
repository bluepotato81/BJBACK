#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int stack[1000001];
    int stacklen=0;
    for(int i=0; i<n;i++) {
        int input;
        scanf("%d", &input);
        if(input==1) {
            scanf("%d", &stack[stacklen]);
            stacklen++;
        }
        else if(input==2) {
            if(stacklen==0) {
                printf("-1\n");
            }
            else {
                printf("%d\n", stack[stacklen-1]);
                stacklen--;
            }
        }
        else if(input==3) {
            printf("%d\n",stacklen);
        }
        else if(input==4) {
            if(stacklen==0) {
                printf("1\n");
            }
            else{
                printf("0\n");
            }
        }
        else if(input==5) {
            if(stacklen==0) {
                printf("-1\n");
            }
            else {
                printf("%d\n", stack[stacklen-1]);
            }
        }

    }

    return 0;
}
