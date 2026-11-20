#include <stdio.h>

char al[20][20];

int visited[26]={0, };

int max=0;
int r, c;

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

void move(int x, int y, int moves) {
    //printf("%d %d\n", x,y);
    visited[al[y][x]-'A']=1;
    int posmoves=0;
    for(int i=0; i<4;i++) {
        int newx=x+dx[i];
        int newy=y+dy[i];
        if(newx>=0 &&newx<c && newy>=0 &&newy<r&&visited[al[newy][newx]-'A']!=1) {
            posmoves++;
            move(newx,newy, moves+1);
        }
    }

    if(!posmoves) {
        if(moves>max) {
            max=moves;
        }
        //printf("cut\n");
    }

    visited[al[y][x]-'A']=0;
}

int main() {
    scanf("%d %d", &r, &c);

    for(int i=0; i<r;i++) {
        for(int j=0;j<c;j++) {
            scanf(" %c", &al[i][j]);
        }
    }




    move(0,0,1);

    printf("%d", max);

    return 0;
}
