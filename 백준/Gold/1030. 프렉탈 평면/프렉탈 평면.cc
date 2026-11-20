#include <stdio.h>

int s,n,k, r1, r2, c1, c2;
long long len=1;


int det(int x, int y, int sx, int sy, long long slen) {
    int csx = sx+(slen/n)*(n-k)/2;
    int csy = sy+(slen/n)*(n-k)/2;
    int cex = csx+((slen/n)*k)-1;
    int cey = csy+((slen/n)*k)-1;

    if((x>=csx && x<=cex) && (y>=csy && y<=cey)) {
        return 1;
    }
    else {
        if(slen==n){
            return 0;
        }
        else {
            int tx=sx, ty=sy;
            while(tx<x) {
                tx+=slen/n;
            }
            tx-=slen/n;
            while(ty<y) {
                ty+=slen/n;
            }
            ty-=slen/n;
            return det(x,y,tx,ty, slen/n);
        }
    }
}

int main() {

    scanf("%d %d %d %d %d %d %d", &s, &n, &k, &r1, &r2, &c1, &c2);
    
    if(s==0) {
        printf("0");
        return 0;
    }


    for(int i=0;i<s;i++) {
        len*=n;
    }

    for(int i=r1; i<=r2;i++) {
        for(int j=c1; j<=c2;j++) {
            printf("%d", det(i,j,0, 0, len));
        }
        printf("\n");
    }

    return 0;
}
