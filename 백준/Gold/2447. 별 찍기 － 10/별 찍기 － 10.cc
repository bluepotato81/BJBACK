#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int st=0;
    for(int i=n; i>=1; i/=3) {
        st++;
    }

    char star[n][n];
    for(int i=0; i<n;i++) {
        for(int j=0; j<n;j++) {
            star[i][j]='*';
        }
    }
    int th[9]={1,3,9,27,81,243,729,2187,6561};

    for(int i=0; i<st;i++) {
        for(int j=0;j<n;j++) {
            for(int k=0;k<n;k++) {
                if(j%th[i+1]==th[i] && k%th[i+1]==th[i]) {
                    for(int m=j;m<j+th[i];m++) {
                        for(int o=k;o<k+th[i];o++) {
                            star[m][o]=' ';
                        }
                    }
                }
            }
        }
    }

    for(int i=0; i<n;i++) {
        for(int j=0;j<n;j++) {
            printf("%c",star[i][j]);
        }
        printf("\n");
    }


    return 0;
}
