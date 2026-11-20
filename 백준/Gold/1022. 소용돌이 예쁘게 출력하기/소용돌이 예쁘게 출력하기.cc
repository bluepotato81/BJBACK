#include <stdio.h>

int numfig(int j, int i) {
    int ring;
    int abi;
    int abj;
    int ij;
    if(i>0) {
        abi=i;
    }
    else {
        abi=-i;
    }
    if(j>0) {
        abj=j;
    }
    else {
        abj=-j;
    }

    if(abi>=abj) {
        ring=abi;
        ij=1;
    }
    else {
        ring=abj;
        ij=2;
    }
    int sq=ring*2+1;

    int num;
    if(ij==1) {
        if(i<0) {
            int cent=sq*sq-ring*5;
            num=cent-j;
        }
        else {
            int cent=sq*sq-ring;
            num=cent+j;
        }
    }
    else {
        if(j<0) {
            int cent=sq*sq-ring*3;
            num=cent+i;
        }
        else {
            int cent=sq*sq-ring*7;
            num=cent-i;
        }
    }
    return num;
}

int main() {
    int r1, c1, r2, c2;
    scanf("%d %d %d %d", &r1, &c1, &r2, &c2);

    int corn[4];

    corn[0]=numfig(c1, r1);
    corn[1]=numfig(c2, r2);
    corn[2]=numfig(c1, r2);
    corn[3]=numfig(c2, r1);


    int big=0;
    for(int i=0; i<4; i++) {
        if(big<corn[i]) {
            big=corn[i];
        }
    }

    int dig=1;
    while(big>=10) {
        big/=10;
        dig++;
    }

    for(int i=r1; i<=r2; i++) {
        for(int j=c1; j<=c2; j++) {
            int ring;
            int abi;
            int abj;
            int ij;
            if(i>0) {
                abi=i;
            }
            else {
                abi=-i;
            }
            if(j>0) {
                abj=j;
            }
            else {
                abj=-j;
            }

            if(abi>=abj) {
                ring=abi;
                ij=1;
            }
            else {
                ring=abj;
                ij=2;
            }
            int sq=ring*2+1;

            int num;
            if(ij==1) {
                if(i<0) {
                    int cent=sq*sq-ring*5;
                    num=cent-j;
                }
                else {
                    int cent=sq*sq-ring;
                    num=cent+j;
                }
            }
            else {
                if(j<0) {
                    int cent=sq*sq-ring*3;
                    num=cent+i;
                }
                else {
                    int cent=sq*sq-ring*7;
                    num=cent-i;
                }
            }
            int dignum=num;
            int numdig=1;
            while(dignum>=10) {
                dignum/=10;
                numdig++;
            }

            for(int i=dig; i>numdig; i--) {
                printf(" ");
            }

            printf("%d ", num);
        }
        printf("\n");
    }

    return 0;
}
