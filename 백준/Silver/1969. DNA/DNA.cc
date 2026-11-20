#include <stdio.h>
char dna[1000][50];


int main() {
    int n,m;
    scanf("%d %d", &n, &m);

    for(int i=0; i<n;i++) {
        for(int j=0; j<m;j++) {
            scanf(" %c", &dna[i][j]);
        }
    }

    char res[m];
    int dif=0;

    for(int i=0; i<m;i++) {
        int tnum=0;
        int anum=0;
        int gnum=0;
        int cnum=0;
        int tot;
        for(int j=0;j<n;j++) {
            if(dna[j][i]=='T') {
                tnum++;
            }
            if(dna[j][i]=='A') {
                anum++;
            }
            if(dna[j][i]=='G') {
                gnum++;
            }
            if(dna[j][i]=='C') {
                cnum++;
            }
        }

        int bignum=0;
        if(anum>bignum) {
            bignum=anum;
            res[i]='A';
            tot=cnum+gnum+tnum;
        }
        if(cnum>bignum) {
            bignum=cnum;
            res[i]='C';
            tot=anum+gnum+tnum;
        }
        if(gnum>bignum) {
            bignum=gnum;
            res[i]='G';
            tot=anum+cnum+tnum;
        }
        if(tnum>bignum) {
            bignum=tnum;
            res[i]='T';
            tot=cnum+gnum+anum;
        }

        dif+=tot;

    }


    for(int i=0; i<m;i++) {
        printf("%c", res[i]);
    }
    printf("\n");

    printf("%d", dif);

    return 0;
}
