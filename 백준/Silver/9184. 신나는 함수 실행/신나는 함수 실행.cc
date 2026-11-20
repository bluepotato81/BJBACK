#include <stdio.h>

int wn[101][101][101];

void setup() {

    for(int i=0; i<101; i++) {
        for(int j=0; j<101; j++) {
            for(int k=0; k<101; k++) {
                if(i<=50 || j<=50 || k<=50) {
                    wn[i][j][k]=1;
                }
            }
        }
    }
    for(int i=51; i<=70; i++) {
        for(int j=51; j<=70; j++) {
            for(int k=51; k<=70; k++) {
                if(i<j && j<k) {
                    wn[i][j][k]=wn[i][j][k-1]+wn[i][j-1][k-1]-wn[i][j-1][k];
                }
                else {
                    wn[i][j][k]=wn[i-1][j][k]+wn[i-1][j-1][k]+wn[i-1][j][k-1]-wn[i-1][j-1][k-1];
                }
            }
        }
    }

}

int w(int a,int b, int c) {
    if(a<=0 || b<=0 || c<=0) {
        return 1;
    }
    else if(a>20 || b>20 ||c>20) {
        return wn[70][70][70];
    }
    else {
        return wn[a+50][b+50][c+50];
    }
}

int main() {
    int a=0, b=0, c=0;
    setup();
    while(1) {
        scanf("%d %d %d", &a, &b, &c);
        if(!(a==-1 && b==-1 && c==-1)) {
            int k=w(a,b,c);
            printf("w(%d, %d, %d) = %d\n", a,b,c,k);
        }
        else {
            break;
        }


    }

    return 0;
}
