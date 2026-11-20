#include <stdio.h>

int main() {
    int a;
    scanf("%d", &a);
    for(int i=0; i<a; i++) {
        int x1,y1,r1,x2,y2,r2;
        scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
        int dis = (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
        if(dis>(r1+r2)*(r1+r2) || (dis==0 && r1!=r2) || (r2-r1)*(r2-r1)>dis) {
            printf("0\n");
        }
        else if(x1==x2 && y1==y2 && r1==r2) {
            printf("-1\n");
        }
        else if(dis==(r1+r2)*(r1+r2) || dis==(r2-r1)*(r2-r1) || dis==(r1-r2)*(r1-r2)) {
            printf("1\n");
        }

        else {
            printf("2\n");
        }
    }

    return 0;
}

