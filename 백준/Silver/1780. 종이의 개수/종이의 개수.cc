#include <stdio.h>

int nums[2187][2187];
int minus=0;
int zero=0;
int plus=0;

void divide(int x, int y, int len) {
    int check = 1;
    int comp = nums[x][y];

    for(int i = x; i < x + len; i++) {
        for(int j = y; j < y + len; j++) {
            if(nums[i][j] != comp) {
                check = 0;
                break;
            }
        }
        if(!check) break;
    }

    if(check) {
        if(comp == 1) plus++;
        else if(comp == 0) zero++;
        else minus++;
    } else {
        int nexlen = len / 3;
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                divide(x + i * nexlen, y + j * nexlen, nexlen);
            }
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &nums[i][j]);
        }
    }

    divide(0, 0, n);
    printf("%d\n%d\n%d", minus, zero, plus);

    return 0;
}
