#include <stdio.h>

int main() {
    int a[9][9];
    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    int max=0;
    int max_i=1, max_j=1;

    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            if(a[i][j]>max) {
                max=a[i][j];
                max_j=j+1;
                max_i=i+1;
            }
        }
    }
    printf("%d\n", max);
    printf("%d %d", max_i, max_j);

    return 0;
}
