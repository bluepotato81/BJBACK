#include <stdio.h>

int max=0;
int paper[500][500];

void longone(int n, int m) {
    for(int i=0;i<m; i++) {
        for(int j=0; j<n-3; j++) {
            int k=paper[j][i]+paper[j+1][i]+paper[j+2][i]+paper[j+3][i];
            if(k>max) {
                max=k;
            }
        }
    }
    for(int i=0;i<m-3; i++) {
        for(int j=0; j<n; j++) {
            int k=paper[j][i]+paper[j][i+1]+paper[j][i+2]+paper[j][i+3];
            if(k>max) {
                max=k;
            }
        }
    }
}

void square(int n, int m) {
    for(int i=0;i<m-1; i++) {
        for(int j=0; j<n-1; j++) {
            int k=paper[j][i]+paper[j+1][i]+paper[j][i+1]+paper[j+1][i+1];
            if(k>max) {
                max=k;
            }
        }
    }
}

void lshape(int n, int m) {
    for(int i=0;i<m-1; i++) {
        for(int j=0; j<n-2; j++) {
            int k=paper[j][i]+paper[j+1][i]+paper[j+2][i]+paper[j+2][i+1];
            if(k>max) {
                max=k;
            }
        }
    }
    for(int i=0;i<m-2; i++) {
        for(int j=0; j<n-1; j++) {
            int k=paper[j][i]+paper[j+1][i]+paper[j][i+1]+paper[j][i+2];
            if(k>max) {
                max=k;
            }
        }
    }
    for(int i=0;i<m-1; i++) {
        for(int j=0; j<n-2; j++) {
            int k=paper[j][i]+paper[j][i+1]+paper[j+1][i+1]+paper[j+2][i+1];
            if(k>max) {
                max=k;
            }
        }
    }
    for(int i=0;i<m-2; i++) {
        for(int j=0; j<n-1; j++) {
            int k=paper[j][i+2]+paper[j+1][i]+paper[j+1][i+1]+paper[j+1][i+2];
            if(k>max) {
                max=k;
            }
        }
    }
    for(int i=0;i<m-1; i++) {
        for(int j=0; j<n-2; j++) {
            int k=paper[j][i+1]+paper[j+1][i+1]+paper[j+2][i+1]+paper[j+2][i];
            if(k>max) {
                max=k;
            }
        }
    }
    for(int i=0;i<m-2; i++) {
        for(int j=0; j<n-1; j++) {
            int k=paper[j][i]+paper[j+1][i]+paper[j+1][i+1]+paper[j+1][i+2];
            if(k>max) {
                max=k;
            }
        }
    }
    for(int i=0;i<m-1; i++) {
        for(int j=0; j<n-2; j++) {
            int k=paper[j][i]+paper[j][i+1]+paper[j+1][i]+paper[j+2][i];
            if(k>max) {
                max=k;
            }
        }
    }
    for(int i=0;i<m-2; i++) {
        for(int j=0; j<n-1; j++) {
            int k=paper[j][i]+paper[j][i+1]+paper[j][i+2]+paper[j+1][i+2];
            if(k>max) {
                max=k;
            }
        }
    }
}
void sshape(int n, int m) {
    for(int i=0;i<m-1; i++) {
        for(int j=0; j<n-2; j++) {
            int k=paper[j][i]+paper[j+1][i]+paper[j+1][i+1]+paper[j+2][i+1];
            if(k>max) {
                max=k;
            }
        }
    }
    for(int i=0;i<m-1; i++) {
        for(int j=0; j<n-2; j++) {
            int k=paper[j][i+1]+paper[j+1][i+1]+paper[j+1][i]+paper[j+2][i];
            if(k>max) {
                max=k;
            }
        }
    }
    for(int i=0;i<m-2; i++) {
        for(int j=0; j<n-1; j++) {
            int k=paper[j][i+1]+paper[j+1][i+1]+paper[j+1][i]+paper[j][i+2];
            if(k>max) {
                max=k;
            }
        }
    }
    for(int i=0;i<m-2; i++) {
        for(int j=0; j<n-1; j++) {
            int k=paper[j][i]+paper[j][i+1]+paper[j+1][i+1]+paper[j+1][i+2];
            if(k>max) {
                max=k;
            }
        }
    }
}
void tshape(int n, int m) {
    for(int i=0;i<m-1; i++) {
        for(int j=0; j<n-2; j++) {
            int k=paper[j][i]+paper[j+1][i]+paper[j+1][i+1]+paper[j+2][i];
            if(k>max) {
                max=k;
            }
        }
    }
    for(int i=0;i<m-1; i++) {
        for(int j=0; j<n-2; j++) {
            int k=paper[j][i+1]+paper[j+1][i+1]+paper[j+1][i]+paper[j+2][i+1];
            if(k>max) {
                max=k;
            }
        }
    }
    for(int i=0;i<m-2; i++) {
        for(int j=0; j<n-1; j++) {
            int k=paper[j][i]+paper[j+1][i+1]+paper[j][i+1]+paper[j][i+2];
            if(k>max) {
                max=k;
            }
        }
    }
    for(int i=0;i<m-2; i++) {
        for(int j=0; j<n-1; j++) {
            int k=paper[j][i+1]+paper[j+1][i]+paper[j+1][i+1]+paper[j+1][i+2];
            if(k>max) {
                max=k;
            }
        }
    }
}

int main() {
    int n,m;
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            scanf("%d", &paper[i][j]);
        }
    }
    longone(n,m);
    square(n,m);
    lshape(n,m);
    sshape(n,m);
    tshape(n,m);
    printf("%d", max);

    return 0;
}
