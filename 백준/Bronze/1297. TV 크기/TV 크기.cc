#include <stdio.h>
#include <math.h>

int main() {
    int d, h, w;
    scanf("%d %d %d", &d, &h, &w);

    double ratio=sqrt(h*h+w*w);
    int ah=(int)(d*h/ratio);
    int aw=(int)(d*w/ratio);

    printf("%d %d", ah, aw);

    return 0;
}
