#include <stdio.h>

int main() {
    char in[1000001];
    scanf("%s", in);

    int index=0;

    int added=0;

    int len=0;

    while(1) {
        if(in[index]=='\0') {
            break;
        }
        added+=in[index++]-'0';
        len++;
    }
    if(len==1) {
        printf("0\n");
        if(added%3==0) {
            printf("YES");
        }
        else {
            printf("NO");
        }
        return 0;
    }

    int next=0;
    int adds=1;

    while(1) {
        if(added<10) {
            break;
        }
        while(added>0) {
            next+=added%10;
            added/=10;
        }

        added=next;
        next=0;
        adds++;
    }

    printf("%d\n", adds);
    if(added%3==0) {
        printf("YES");
    }
    else {
        printf("NO");
    }

    return 0;
}
