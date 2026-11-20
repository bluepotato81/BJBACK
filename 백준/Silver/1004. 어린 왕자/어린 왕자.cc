#include <stdio.h>

int in(int x, int y, int cx, int cy, int r) {
    int xdis=cx-x;
    int ydis=cy-y;
    if(r*r>xdis*xdis+ydis*ydis) {
        return 1;
    }
    else{
        return 0;
    }
}

int main() {
    int t;
    scanf("%d", &t);

    while(t--) {
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

        int oin=0, tin=0;

        int n;
        scanf("%d", &n);
        while(n--) {
            int cx, cy, r;
            scanf("%d %d %d", &cx, &cy, &r);
            int o=in(x1, y1, cx, cy,r);
            int t=in(x2,y2,cx,cy,r);
            
            if(o==1 && t==0) {
                oin++;
            }
            else if(o==0 && t==1) {
                tin++;
            }
        }

        printf("%d\n", oin+tin);
    }

    return 0;
}
