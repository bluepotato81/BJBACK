#include <stdio.h>

int tile[129][129];
int shapes=1;
int rlen=1;

void shape(int len, int cox, int coy, int dir) {
    if(len==2) {
        if(dir==1) {
            tile[cox][coy]=shapes;
            tile[cox][coy+1]=shapes;
            tile[cox-1][coy]=shapes;
            shapes++;

        }
        if(dir==2) {
            tile[cox][coy]=shapes;
            tile[cox][coy+1]=shapes;
            tile[cox+1][coy]=shapes;
            shapes++;

        }
        if(dir==3) {
            tile[cox][coy]=shapes;
            tile[cox][coy-1]=shapes;
            tile[cox+1][coy]=shapes;
            shapes++;

        }
        if(dir==4) {
            tile[cox][coy]=shapes;
            tile[cox][coy-1]=shapes;
            tile[cox-1][coy]=shapes;
            shapes++;

        }
        return;
    }
    if(dir==1) {
        shape(len/2, cox-(len/4), coy+(len/4),  1);
        shape(len/2, cox-len+1, coy, 2);
        shape(len/2, cox, coy+len-1, 4);
        shape(len/2, cox, coy, 1);
        return;
    }
    if(dir==2) {
        shape(len/2, cox+(len/4), coy+(len/4),  2);
        shape(len/2, cox+len-1, coy, 1);
        shape(len/2, cox, coy+len-1, 3);
        shape(len/2, cox, coy, 2);
        return;
    }
    if(dir==3) {
        shape(len/2, cox+(len/4), coy-(len/4),  3);
        shape(len/2, cox+len-1, coy, 4);
        shape(len/2, cox, coy-len+1, 2);
        shape(len/2, cox, coy, 3);
        return;
    }
    if(dir==4) {
        shape(len/2, cox-(len/4), coy-(len/4),  4);
        shape(len/2, cox-len+1, coy, 3);
        shape(len/2, cox, coy-len+1, 1);
        shape(len/2, cox, coy, 4);
        return;
    }
}

void fill(int len, int x, int y, int bx, int by) {
    int cx=bx+(len/2)-1;
    int cy=by+(len/2)-1;
    if(x<=cx) {
        if(y<=cy) {
            if(len==2) {
                tile[bx+1][by+1]=shapes;
                tile[bx][by+1]=shapes;
                tile[bx+1][by]=shapes;
                shapes++;
                tile[bx][by]=-1;
                return;
            }
            shape(len/2, cx+(len/4), cy+(len/4),  4);
            shape(len/2, bx, by+len-1, 3);
            shape(len/2, bx+len-1, by+len-1, 4);
            shape(len/2, bx+len-1, by, 1);
            fill(len/2, x,y,bx,by);
        }
        else {
            if(len==2) {
                tile[bx+1][by+1]=shapes;
                tile[bx][by]=shapes;
                tile[bx+1][by]=shapes;
                shapes++;
                tile[bx][by+1]=-1;
                return;
            }
            shape(len/2, bx, by,  2);
            shape(len/2, cx+(len/4), cy-(len/4)+1, 1);
            shape(len/2, bx+len-1, by+len-1, 4);
            shape(len/2, bx+len-1, by, 1);
            fill(len/2, x,y,bx,by+len/2);
        }
    }
    else {
        if(y<=cy) {
            if(len==2) {
                tile[bx+1][by+1]=shapes;
                tile[bx][by+1]=shapes;
                tile[bx][by]=shapes;
                shapes++;
                tile[bx+1][by]=-1;
                return;
            }
            shape(len/2, bx+(len/4), cy+(len/4),  3);
            shape(len/2, bx, by+len-1, 3);
            shape(len/2, bx+len-1, by+len-1, 4);
            shape(len/2, bx, by,  2);
            fill(len/2, x,y,bx+len/2,by);
        }
        else {
            if(len==2) {
                tile[bx][by]=shapes;
                tile[bx][by+1]=shapes;
                tile[bx+1][by]=shapes;
                shapes++;
                tile[bx+1][by+1]=-1;
                return;
            }
            shape(len/2, bx+(len/4), by+(len/4),  2);
            shape(len/2, bx+len-1, by, 1);
            shape(len/2, bx, by,  2);
            shape(len/2, bx, by+len-1, 3);
            fill(len/2, x,y,bx+len/2,by+len/2);
        }
    }
}




int main() {
    int k;
    scanf("%d", &k);


    for(int i=0; i<k;i++) {
        rlen*=2;
    }

    int x,y;
    scanf("%d %d", &x, &y);

    fill(rlen,x,y,1,1);

    for(int i=rlen;i>=1;i--) {
        for(int j=1;j<=rlen;j++) {
            printf("%d ", tile[j][i]);

        }
        printf("\n");
    }

    return 0;
}
