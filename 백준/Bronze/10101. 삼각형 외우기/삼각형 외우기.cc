#include <stdio.h>

int main() {
    int a[3];
    for(int i=0; i<3; i++) {
        scanf("%d", &a[i]);
    }

    if(a[0]+a[1]+a[2]!=180) {
        printf("Error");
    }
    else if(a[0]==a[1] && a[1]==a[2] && a[2]==60) {
        printf("Equilateral");
    }
    else if(a[0]==a[1] || a[1]==a[2] || a[2]==a[0]) {
        printf("Isosceles");
    }
    else {
        printf("Scalene");
    }

    return 0;
}
