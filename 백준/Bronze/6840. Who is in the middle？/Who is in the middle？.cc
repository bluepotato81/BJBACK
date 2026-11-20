#include <stdio.h>

int main() {
    int a[3];
    scanf("%d%d%d", &a[0], &a[1], &a[2]);

    int max=0;
    int maxin;
    int min=101;
    int minin;

    for(int i=0; i<3; i++) {
        if(a[i]>max) {
            maxin=i;
            max=a[i];
        }
        if(a[i]<min) {
            minin=i;
            min=a[i];
        }
    }

    for(int i=0; i<3; i++) {
        if(i!=maxin && i!=minin) {
            printf("%d", a[i]);
        }
    }



    return 0;
}
