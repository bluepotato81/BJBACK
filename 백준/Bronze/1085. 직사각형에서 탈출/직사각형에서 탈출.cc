#include <stdio.h>

int main() {
    int x,y,w,h;
    scanf("%d %d %d %d", &x, &y, &w, &h);
    int left, right, up, down;
    left=x;
    right=w-x;
    up=h-y;
    down=y;
    int min=left;
    if(right<min) {
        min=right;
    }
    if(up<min) {
        min=up;
    }
    if(down<min) {
        min=down;
    }

    printf("%d", min);
}
