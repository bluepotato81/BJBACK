#include <stdio.h>


int main() {
    int n[11]={1, 2, 4, 7, 13, 24, 44, 81, 149, 274, 504};

    int t;
    scanf("%d", &t);
    for(int i=0; i<t; i++) {
        int a;
        scanf("%d", &a);
        printf("%d\n",n[a-1]);
    }





}
