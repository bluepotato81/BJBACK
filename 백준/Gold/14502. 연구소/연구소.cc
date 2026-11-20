#include <stdio.h>

int spread[8][8];
int prev_save[8][8];

int vloc[64];
int vnum;

int libnum;
int resnum=0;

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

void reset(int n, int m) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<m;j++) {
            spread[i][j]=prev_save[i][j];
        }
    }
}

void print(int n, int m) {
    for(int k=0; k<n; k++) {
        for(int l=0; l<m; l++) {
            printf("%d ", spread[k][l]);
        }
        printf("\n");
    }
    printf("\n");
}

void infect(int n, int m, int x, int y) {
    spread[y][x]=2;
    for(int i=0; i<4; i++) {
        int newx=x+dx[i];
        int newy=y+dy[i];
        if(newx>=0 && newx<m && newy>=0 && newy<n && spread[newy][newx]==0) {
            infect(n,m,newx,newy);
        }
    }
}

void libcheck(int n, int m, int x, int y) {
    spread[y][x]=3;
    libnum++;
    for(int i=0; i<4; i++) {
        int newx=x+dx[i];
        int newy=y+dy[i];
        if(newx>=0 && newx<m && newy>=0 && newy<n && spread[newy][newx]==0) {
            libcheck(n,m,newx,newy);
        }
    }
}

void calc(int n, int m, int stage, int curi, int curj) {
    if(stage==3) {
        for(int i=0; i<n; i++) {
            for(int j=0; j<m;j++) {
                prev_save[i][j]=spread[i][j];
            }
        }
        for(int i=0; i<vnum;i++) {
            int vy=vloc[i]/10;
            int vx=vloc[i]%10;
            infect(n,m,vx, vy);
            //print(n,m);
        }
        int check=0;
        libnum=0;
        for(int i=0; i<n; i++) {
            for(int j=0;j<m; j++) {
                if(spread[i][j]==0) {

                    libcheck(n,m, j, i);
                    //print(n,m);
                    //printf("s\n\n");
                    if(libnum>resnum) {
                        resnum=libnum;
                        //print(n,m);
                    }
                }
            }

        }
        //print(n,m);
        reset(n,m);
        //print(n,m);
        //printf("r\n\n");
        return;
    }
    else {
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(spread[i][j]==0) {
                    spread[i][j]=1;
                    //print(n,m);
                    //printf("%d\n\n", stage+1);
                    calc(n,m,stage+1, i,j);
                    spread[i][j]=0;
                }
            }
        }
        return;
    }
}


int main() {
    int n,m;
    scanf("%d %d", &n, &m);

    for(int i=0; i<n;i++) {
        for(int j=0; j<m; j++) {
            scanf("%d", &spread[i][j]);
            if(spread[i][j]==2) {
                vloc[vnum++] = 10*i+j;
            }
        }
    }

    calc(n,m,0,0,0);

    printf("%d", resnum);


    return 0;
}
