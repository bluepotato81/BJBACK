#include <stdio.h>

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

int main() {
    int r,c,t;
    scanf("%d %d %d", &r, &c, &t);

    int room[r][c];

    int clx;
    int clyd;
    int clyu;

    for(int i=0; i<r;i++) {
        for(int j=0; j<c; j++) {
            scanf("%d", &room[i][j]);
            if(room[i][j]==-1) {
                clx=j;
                clyd=i;
                clyu=i-1;
            }
        }
    }

    while(t--) {
        int change[r][c];

        for(int i=0; i<r;i++) {
            for(int j=0; j<c; j++) {
                change[i][j]=0;
            }
        }

        for(int i=0; i<r;i++) {
            for(int j=0; j<c; j++) {
                if(room[i][j]!=0 && room[i][j]!=-1) {
                    int moveam=room[i][j]/5;
                    int spreads=0;
                    for(int k=0;k<4;k++) {
                        int newx=j+dx[k];
                        int newy=i+dy[k];
                        if(newx>=0 && newx<c && newy>=0 && newy<r && !(newx==clx && (newy==clyd ||newy==clyu))) {
                            spreads++;
                            change[newy][newx]+=moveam;
                        }
                    }
                    change[i][j]-=moveam*spreads;
                }
            }
        }

        //printf("After spread\n");

        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                room[i][j]+=change[i][j];
                //printf("%d ", room[i][j]);
            }
            //printf("\n");
        }

        //printf("//\n");




        //top move
        for(int i=clx-1;i>=0; i--) {
            if(i+1==clx) {
                room[clyu][i]=0;
            }
            else {
                room[clyu][i+1]=room[clyu][i];
                room[clyu][i]=0;
            }
        }

        for(int i=clyu-1; i>=0;i--) {
            if(clx==0 && i+1==clyu) {
                room[i][0]==0;
            }
            else {
                room[i+1][clx]=room[i][clx];
                room[i][clx]=0;
            }
        }

        for(int i=1; i<c;i++) {
            room[0][i-1]=room[0][i];
            room[0][i]=0;
        }

        for(int i=1; i<=clyu;i++) {
            room[i-1][c-1]=room[i][c-1];
            room[i][c-1]=0;
        }

        for(int i=c-2;i>clx;i--) {
            room[clyu][i+1]=room[clyu][i];
            room[clyu][i]=0;
        }

        /*printf("After top move\n");

        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                printf("%d ", room[i][j]);
            }
            printf("\n");
        }
        printf("//\n");*/

        // bottom move
        for(int i=clx-1;i>=0; i--) {
            if(i+1==clx) {
                room[clyd][i]=0;
            }
            else {
                room[clyd][i+1]=room[clyd][i];
                room[clyd][i]=0;
            }
        }

        for(int i=clyd+1; i<r;i++) {
            if(clx==0 && i-1==clyd) {
                room[i][0]==0;
            }
            else {
                room[i-1][clx]=room[i][clx];
                room[i][clx]=0;
            }
        }




        for(int i=1; i<c;i++) {
            room[r-1][i-1]=room[r-1][i];
            room[r-1][i]=0;
        }

        for(int i=r-2; i>=clyd;i--) {
            room[i+1][c-1]=room[i][c-1];
            room[i][c-1]=0;
        }

        for(int i=c-2;i>clx;i--) {
            room[clyd][i+1]=room[clyd][i];
            room[clyd][i]=0;
        }

        /*for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                printf("%d ", room[i][j]);
            }
            printf("\n");
        }
        printf("//\n");*/

    }

    int tot=0;

    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            tot+=room[i][j];
        }
    }

    printf("%d", tot+2);

    return 0;
}
