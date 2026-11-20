#include <stdio.h>


int main() {
    int a;
    int com=0;
    int place;
    for(int i=0;i<9;i++) {
        scanf("%d", &a);
        if(com<a) {
            com=a;
            place=i+1;
        }
    }
    printf("%d\n%d", com, place);
    return 0;

}
