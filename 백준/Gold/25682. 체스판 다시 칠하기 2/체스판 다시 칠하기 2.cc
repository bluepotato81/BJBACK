#include <stdio.h>
#include <limits.h>

int main() {
    int n,m,k;
    scanf("%d %d %d", &n, &m, &k);
    getchar();

    int board[n][m];
    char a;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            scanf("%c", &a);
            if(a=='B') {
                board[i][j]=0;
            }
            else {
                board[i][j]=1;
            }
        }
        getchar();
    }

    int perfect1[n][m];
    int perfect0[n][m];
    int comp1[n][m];
    int comp2[n][m];

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            perfect1[i][j]=(i+j+1)%2;
            perfect0[i][j]=(i+j)%2;
            if(board[i][j]==perfect1[i][j]) {
                comp1[i][j]=0;
            }
            else {
                comp1[i][j]=1;
            }
            if(board[i][j]==perfect0[i][j]) {
                comp2[i][j]=0;
            }
            else {
                comp2[i][j]=1;
            }
        }
    }

    int comlist1[n][m];
    int comlist2[n][m];
    comlist1[0][0]=comp1[0][0];
    comlist2[0][0]=comp2[0][0];
    for(int i=1; i<m; i++) {
        comlist1[0][i]=comlist1[0][i-1]+comp1[0][i];
        comlist2[0][i]=comlist2[0][i-1]+comp2[0][i];
    }
    for(int i=1; i<n; i++) {
        comlist1[i][0]=comlist1[i-1][0]+comp1[i][0];
        comlist2[i][0]=comlist2[i-1][0]+comp2[i][0];
    }

    for(int i=1; i<n; i++) {
        for(int j=1; j<m; j++) {
            comlist1[i][j]=comlist1[i-1][j]+comlist1[i][j-1]-comlist1[i-1][j-1]+comp1[i][j];
            comlist2[i][j]=comlist2[i-1][j]+comlist2[i][j-1]-comlist2[i-1][j-1]+comp2[i][j];
        }
    }

    int kmin=INT_MAX;
    int o;
    for(int i=0; i<n-k+1; i++) {
        for(int j=0; j<m-k+1; j++) {
            if(i!=0 && j!=0) {
                o=comlist1[i+k-1][j+k-1]-comlist1[i-1][j+k-1]-comlist1[i+k-1][j-1]+comlist1[i-1][j-1];
                if(o<kmin) {
                    kmin=o;
                }
            }
            else if(i==0 && j!=0) {
                o=comlist1[i+k-1][j+k-1]-comlist1[i+k-1][j-1];
                if(o<kmin) {
                    kmin=o;
                }
            }
            else if(i!=0 && j==0) {
                o=comlist1[i+k-1][j+k-1]-comlist1[i-1][j+k-1];
                if(o<kmin) {
                    kmin=o;
                }
            }
            else {
                o=comlist1[i+k-1][j+k-1];
                if(o<kmin) {
                    kmin=o;
                }
            }
        }
    }
    for(int i=0; i<n-k+1; i++) {
        for(int j=0; j<m-k+1; j++) {
            if(i!=0 && j!=0) {
                o=comlist2[i+k-1][j+k-1]-comlist2[i-1][j+k-1]-comlist2[i+k-1][j-1]+comlist2[i-1][j-1];
                if(o<kmin) {
                    kmin=o;
                }
            }
            else if(i==0 && j!=0) {
                o=comlist2[i+k-1][j+k-1]-comlist2[i+k-1][j-1];
                if(o<kmin) {
                    kmin=o;
                }
            }
            else if(i!=0 && j==0) {
                o=comlist2[i+k-1][j+k-1]-comlist2[i-1][j+k-1];
                if(o<kmin) {
                    kmin=o;
                }
            }
            else {
                o=comlist2[i+k-1][j+k-1];
                if(o<kmin) {
                    kmin=o;
                }
            }
        }
    }
    printf("%d", kmin);

    return 0;
}
