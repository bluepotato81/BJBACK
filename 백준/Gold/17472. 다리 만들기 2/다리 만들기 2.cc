#include <iostream>
#include <limits.h>

int world[11][11];
int islands[11][11]={0, };

int isnum=0;

int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};


void isfill(int n, int m, int x, int y) {
    islands[y][x]=isnum;

    for(int i=0; i<4;i++) {
        int newx=x+dx[i];
        int newy=y+dy[i];
        if(newx>=0 && newx<m && newy>=0 && newy<n &&world[newy][newx]==1&& islands[newy][newx]==0) {
            isfill(n,m,newx,newy);
        }
    }
}

void isfind(int n, int m, int x, int y) {
    if(islands[y][x]!=0) {
        return;
    }
    isnum++;

    isfill(n,m,x,y);

}



int main() {
    int n,m;
    scanf("%d %d", &n, &m);


    for(int i=0; i<n;i++) {
        for(int j=0; j<m;j++) {
            scanf("%d", &world[i][j]);
        }
    }
    for(int i=0; i<n;i++) {
        for(int j=0; j<m;j++) {
            if(world[i][j]==1) {
                isfind(n,m,j,i);
            }
        }
    }

    int ldis[7][7];


    for(int i=1;i<=isnum;i++) {
        for(int j=1; j<=isnum;j++) {
            ldis[i][j]=11;
        }
    }


    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(islands[i][j]!=0) {
                int start=islands[i][j];
                if(i<n-1 && islands[i+1][j]==0 && islands[i+2][j]==0) {
                    int hit=0;
                    int len=2;
                    for(int k=i+3; k<n; k++) {
                        if(islands[k][j]!=0) {
                            hit=islands[k][j];
                            break;
                        }
                        len++;
                    }
                    if(hit!=0) {
                        if(ldis[start][hit]>len) {
                            ldis[start][hit]=len;
                            ldis[hit][start]=len;
                        }
                    }
                }

                if(j<m-1 && islands[i][j+1]==0 && islands[i][j+2]==0) {
                    int hit=0;
                    int len=2;
                    for(int k=j+3; k<m; k++) {
                        if(islands[i][k]!=0) {
                            hit=islands[i][k];
                            break;
                        }
                        len++;
                    }
                    if(hit!=0) {
                        if(ldis[start][hit]>len) {
                            ldis[start][hit]=len;
                            ldis[hit][start]=len;
                        }
                    }

                }


            }
        }
    }

    int cc[isnum+1];
    int ce[isnum+1];
    int explored[isnum+1];

    int done=1;

    for(int i=1; i<=isnum; i++) {
        cc[i]=INT_MAX;
        ce[i]=-1;
        explored[i]=0;
    }

    int start=1;
    cc[start]=0;
    while(done<isnum) {
        int cvex;
        int cvexin=INT_MAX;
        for(int i=1; i<=isnum;i++) {
            if(explored[i]==0 && cc[i]<cvexin) {
                cvex=i;
                cvexin=cc[i];
            }
        }
        explored[cvex]=1;
        done++;

        for(int i=1; i<=isnum;i++) {
            if(ldis[cvex][i]!=11) {
                if(explored[i]==0 && ldis[cvex][i]<cc[i]) {
                    cc[i]=ldis[cvex][i];
                    ce[i]=cvex;
                }
            }
        }
    }

    int tot=0;

    for(int i=1; i<=isnum;i++) {
        if(ce[i]!=-1) {
            tot+=cc[i];
        }
        if(cc[i] == INT_MAX) {
            printf("-1\n");
            return 0;
        }

    }

    printf("%d", tot);


    return 0;
}
