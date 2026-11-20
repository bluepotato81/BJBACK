#include <stdio.h>

int main() {
    int px[3];
    int py[3];

    int a,b;

    for(int i=0; i<3;i++) {
        scanf("%d %d", &px[i], &py[i]);
    }

    int k=(px[1]-px[0])*(py[2]-py[0]) - (py[1]-py[0])*(px[2]-px[0]);

    if(k>0) {
        printf("1");
    }
    else if(k==0) {
        printf("0");
    }
    else {
        printf("-1");
    }

    return 0;
}
