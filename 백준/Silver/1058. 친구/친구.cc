#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    char fr[n][n];

    for(int i=0; i<n; i++) {
        scanf("%s", fr[i]);
    }

    int maxfr=0;

    for(int i=0; i<n; i++) {
        int f2[n];
        for(int i=0; i<n;i++) {
            f2[i]=0;
        }

        for(int j=0; j<n; j++) {
            if(fr[i][j]=='Y') {
                f2[j]++;
                for(int k=0; k<n; k++) {
                    if(fr[j][k]=='Y' && k!=i) {
                        f2[k]++;
                    }
                }
            }
        }
        int tot=0;
        for(int j=0; j<n;j++) {
            if(f2[j]) {
                tot++;
            }
        }
        if(tot>maxfr) {
            maxfr=tot;
        }
    }

    printf("%d", maxfr);

    return 0;
}

