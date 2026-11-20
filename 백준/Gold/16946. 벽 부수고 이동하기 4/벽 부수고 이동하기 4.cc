#include <stdio.h>

typedef struct{
    int size;
    int id;
}space;

char pl[1000][1000];

space ar[1000][1000];

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

int w[1000][1000];

int a=0;
int o=1;
int n,m;
void arcal(int y,int x) {
    a++;
    ar[y][x].size=-1;
    for(int i=0; i<4;i++) {
        int newx=x+dx[i];
        int newy=y+dy[i];

        if(newx>=0 && newx<m && newy>=0 && newy<n && ar[newy][newx].size==0) {
            arcal(newy, newx);
        }
    }
}

void arfill(int y, int x) {
    ar[y][x].size=a;
    ar[y][x].id=o;
    for(int i=0; i<4;i++) {
        int newx=x+dx[i];
        int newy=y+dy[i];

        if(newx>=0 && newx<m && newy>=0 && newy<n && ar[newy][newx].size==-1) {
            arfill(newy, newx);
        }
    }
}

int main() {

    scanf("%d %d", &n, &m);

    for(int i=0;i<n;i++) {
        scanf("%s", pl[i]);
        for(int j=0;j<m;j++) {
            if(pl[i][j]=='1') {
                ar[i][j].size=-2;
                ar[i][j].id=0;
            }
            else {
                ar[i][j].size=pl[i][j]-'0';
            }

        }
    }

    for(int i=0; i<n;i++) {
        for(int j=0; j<m;j++) {
            if(ar[i][j].size==0) {
                a=0;

                arcal(i,j);
                //printf("A");
                arfill(i,j);
                o++;
            }
        }
    }


    /*for(int i=0; i<n;i++) {
        for(int j=0; j<m;j++) {
            printf("%d", ar[i][j].id);
        }
        printf("\n");
    }*/

    for(int i=0; i<n;i++) {
        for(int j=0; j<m;j++) {
            if(ar[i][j].size==-2) {
                int comp=0;
                int donechunks[o];
                for(int k=0; k<o;k++) {
                    donechunks[k]=0;
                }

                for(int k=0; k<4;k++) {
                    int newx=j+dx[k];
                    int newy=i+dy[k];

                    if(newx>=0 && newx<m && newy>=0 && newy<n && ar[newy][newx].size>0 && donechunks[ar[newy][newx].id]==0) {
                        comp+=ar[newy][newx].size;
                        donechunks[ar[newy][newx].id]=1;
                    }
                }
                w[i][j]=(comp+1)%10;
            }
            else {
                w[i][j]=0;
            }
        }
    }

    for(int i=0; i<n;i++) {
        for(int j=0; j<m;j++) {
            printf("%d", w[i][j]);
        }
        printf("\n");
    }



    return 0;
}
