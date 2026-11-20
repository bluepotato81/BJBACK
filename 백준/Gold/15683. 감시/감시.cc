#include <stdio.h>

int room[8][8];
int cx[8];
int cy[8];
int emp;
int n,m;

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int ans=70;
void check(int cam, int cur, int cr[][8], int emp) {
    //printf("%d %d\n", cur, emp);
    if(cam==cur) {
        if(emp<ans) {
            ans=emp;
        }
        return;
    }

    int crex=cx[cur];
    int crey=cy[cur];

    int k=emp;
    if(room[crey][crex]==1) {
        for(int i=0;i<4;i++) {
            int l=0;
            int sx=crex, sy=crey;
            int mod[8][8];
            for(int i=0;i<8;i++) {
                for(int j=0;j<8;j++) {
                    mod[i][j]=cr[i][j];
                }
            }
            while(1) {
                sx+=dx[i];
                sy+=dy[i];
                if(sx>=m || sx<0 || sy>=n || sy<0 || room[sy][sx] == 6) {
                    break;
                }
                if(room[sy][sx] == 0 && cr[sy][sx] != -1) {
                    l++;
                    mod[sy][sx]=-1;
                }
            }
            int res = k-l;
            check(cam, cur+1, mod, res);
        }
    }
    if(room[crey][crex]==2) {
        for(int i=0;i<2;i++) {
            int l=0;
            int sx=crex, sy=crey;
            int mod[8][8];
            for(int i=0;i<8;i++) {
                for(int j=0;j<8;j++) {
                    mod[i][j]=cr[i][j];
                }
            }
            while(1) {
                sx+=dx[i];
                sy+=dy[i];
                if(sx>=m || sx<0 || sy>=n || sy<0 || room[sy][sx] == 6) {
                    break;
                }
                if(room[sy][sx] == 0 && cr[sy][sx] != -1) {
                    l++;
                    mod[sy][sx]=-1;
                }
            }
            sx=crex, sy=crey;
            while(1) {
                sx+=dx[i+2];
                sy+=dy[i+2];
                if(sx>=m || sx<0 || sy>=n || sy<0 || room[sy][sx] == 6) {
                    break;
                }
                if(room[sy][sx] == 0 && cr[sy][sx] != -1) {
                    l++;
                    mod[sy][sx]=-1;
                }
            }
            int res = k-l;
            check(cam, cur+1, mod, res);
        }
    }
    if(room[crey][crex]==3) {
        for(int i=0;i<4;i++) {
            int l=0;
            int sx=crex, sy=crey;
            int mod[8][8];
            for(int i=0;i<8;i++) {
                for(int j=0;j<8;j++) {
                    mod[i][j]=cr[i][j];
                }
            }
            while(1) {
                sx+=dx[i];
                sy+=dy[i];
                if(sx>=m || sx<0 || sy>=n || sy<0 || room[sy][sx] == 6) {
                    break;
                }
                if(room[sy][sx] == 0 && cr[sy][sx] != -1) {
                    l++;
                    mod[sy][sx]=-1;
                }
            }
            sx=crex, sy=crey;
            while(1) {
                sx+=dx[(i+1)%4];
                sy+=dy[(i+1)%4];
                if(sx>=m || sx<0 || sy>=n || sy<0 || room[sy][sx] == 6) {
                    break;
                }
                if(room[sy][sx] == 0 && cr[sy][sx] != -1) {
                    l++;
                    mod[sy][sx]=-1;
                }
            }

            int res = k-l;
            check(cam, cur+1, mod, res);
        }
    }
    if(room[crey][crex]==4) {
        for(int i=0;i<4;i++) {
            int l=0;
            int sx=crex, sy=crey;
            int mod[8][8];
            for(int i=0;i<8;i++) {
                for(int j=0;j<8;j++) {
                    mod[i][j]=cr[i][j];
                }
            }
            while(1) {
                sx+=dx[i];
                sy+=dy[i];
                if(sx>=m || sx<0 || sy>=n || sy<0 || room[sy][sx] == 6) {
                    break;
                }
                if(room[sy][sx] == 0 && cr[sy][sx] != -1) {
                    l++;
                    mod[sy][sx]=-1;
                }
            }
            sx=crex, sy=crey;
            while(1) {
                sx+=dx[(i+1)%4];
                sy+=dy[(i+1)%4];
                if(sx>=m || sx<0 || sy>=n || sy<0 || room[sy][sx] == 6) {
                    break;
                }
                if(room[sy][sx] == 0 && cr[sy][sx] != -1) {
                    l++;
                    mod[sy][sx]=-1;
                }
            }
            sx=crex, sy=crey;
            while(1) {
                sx+=dx[(i+2)%4];
                sy+=dy[(i+2)%4];
                if(sx>=m || sx<0 || sy>=n || sy<0 || room[sy][sx] == 6) {
                    break;
                }
                if(room[sy][sx] == 0 && cr[sy][sx] != -1) {
                    l++;
                    mod[sy][sx]=-1;
                }
            }
            int res = k-l;
            check(cam, cur+1, mod, res);
        }
    }
    if(room[crey][crex]==5) {
        int l=0;
        int sx=crex, sy=crey;
        int mod[8][8];
        for(int i=0;i<8;i++) {
            for(int j=0;j<8;j++) {
                mod[i][j]=cr[i][j];
            }
        }
        for(int i=0;i<4;i++) {
            sx=crex, sy=crey;
            while(1) {
                sx+=dx[i];
                sy+=dy[i];
                if(sx>=m || sx<0 || sy>=n || sy<0 || !(cr[sy][sx]>=-1 && cr[sy][sx]<=5)) {
                    break;
                }
                if(room[sy][sx] == 0 && cr[sy][sx] != -1) {
                    l++;
                    mod[sy][sx]=-1;
                }
            }

        }
        int res = k-l;
        check(cam, cur+1, mod, res);
    }
    return;
}

int main() {
    scanf("%d %d", &n, &m);


    emp=n*m;
    int cam=0;
    for(int i=0;i<n;i++) {
        for(int j=0; j<m;j++) {
            scanf("%d", &room[i][j]);
            if(room[i][j]) {
                emp--;
            }
            if(room[i][j]>=1 && room[i][j]<=5) {
                cx[cam]=j;
                cy[cam]=i;
                cam++;
            }
        }
    }

    //printf("%d\n", emp);
    check(cam, 0,room,emp);

    printf("%d", ans);






    return 0;
}
