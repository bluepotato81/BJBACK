#include <stdio.h>

int y(int t) {
    return ((t/30)+1)*10;
}

int m(int t) {
    return ((t/60)+1)*15;
}

int main() {
    int n;
    scanf("%d", &n);

    int ytot=0, mtot=0;

    int c;
    for(int i=0; i<n; i++) {
        scanf("%d", &c);
        ytot+=y(c);
        mtot+=m(c);
    }


    if(ytot<mtot) {
        printf("Y %d", ytot);
    }
    else if(mtot<ytot) {
        printf("M %d", mtot);
    }
    else {
        printf("Y M %d", ytot);
    }


    return 0;
}
