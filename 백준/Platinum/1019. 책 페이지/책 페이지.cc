#include <stdio.h>


int main() {
    int n;
    scanf("%d", &n);

    int ncop=n;
    int digits=0;
    while(ncop>0) {
        digits++;
        ncop/=10;
    }

    long long am[digits][10];
    long long comp[digits][10];

    for(int i=0; i<digits;i++) {
        for(int j=0; j<10;j++) {
            am[i][j]=0;
            comp[i][j]=0;
        }
    }

    if(n<10) {
        printf("0 ");
        for(int i=1; i<=n; i++) {
            printf("1 ");
        }
        for(int i=n+1;i<10;i++) {
            printf("0 ");
        }

        return 0;
    }

    for(int i=0; i<=9; i++) {
        am[0][i]=1;
        comp[0][i]=1;
    }

    am[0][0]=0;

    long long rep=10;
    for(int i=1; i<digits-1; i++) {
        for(int j=0; j<10; j++) {
            comp[i][j]+=comp[i-1][j];
        }
        comp[i][0]+=rep;
        for(int j=1; j<10; j++) {
            for(int k=0; k<10;k++) {
                am[i][k]+=comp[i-1][k];
                comp[i][k]+=comp[i-1][k];
            }
            am[i][j]+=rep;
            comp[i][j]+=rep;
        }
        rep*=10;
    }

    int dig[digits];
    int ncop2=n;
    long long repcop=rep;
    for(int i=0; i<digits; i++) {
        dig[i]=ncop2/repcop;
        ncop2%=repcop;
        repcop/=10;
    }

    for(int i=0; i<digits-1; i++) {
        for(int j=1-!(!i); j<dig[i]; j++) {
            for(int k=0; k<10;k++) {
                am[digits-1][k]+=comp[digits-2-i][k];
            }
            am[digits-1][j]+=rep;
        }
        am[digits-1][dig[i]]+=(n%rep)+1;
        rep/=10;

    }

    for(int i=0; i<=dig[digits-1];i++) {
        am[digits-1][i]++;
    }

    long long ans[10]={0, };

    for(int i=0; i<digits;i++) {
        for(int j=0; j<10;j++) {
            //printf("%d ", am[i][j]);
            ans[j]+=am[i][j];
        }
        //printf("\n");
    }

    for(int i=0; i<10; i++) {
        printf("%lld ", ans[i]);
    }

    return 0;
}
