#include <stdio.h>

int abin[60];
int bbin[60];

int a_am1[60];
int b_am1[60];

int tobin(long long in, int aorb) {
    int len=0;
    while(in>0) {
        if(aorb) {
            abin[len]=in%2;
            if(in%2) {
                if(len) {
                    a_am1[len]=a_am1[len-1]+1;
                    len++;
                }
                else {
                    a_am1[len]=1;
                    len++;
                }
            }
            else {
                if(len) {
                    a_am1[len]=a_am1[len-1];
                    len++;
                }
                else {
                    a_am1[len]=0;
                    len++;
                }
            }
            in/=2;
        }
        else {
            bbin[len]=in%2;
            if(in%2) {
                if(len) {
                    b_am1[len]=b_am1[len-1]+1;
                    len++;
                }
                else {
                    b_am1[len]=1;
                    len++;
                }
            }
            else {
                if(len) {
                    b_am1[len]=b_am1[len-1];
                    len++;
                }
                else {
                    b_am1[len]=0;
                    len++;
                }
            }
            in/=2;
        }
    }
    return len;
}


long long cal1s(int len) {
    long long k=0;
    long long per=1;
    for(int i=0;i<len-2; i++) {
        per*=2;
    }
    per*=len-1;
    k+=per;


    per=1;
    for(int i=0; i<len-1; i++) {
        per*=2;
    }
    k+=per;

    return k;
}

long long back1s(int len) {
    long long k=1;
    for(int i=0; i<len-1; i++) {
        k*=2;
    }

    return k*len;
}

int main() {
    long long a, b;
    scanf("%lld %lld", &a, &b);

    int alen=tobin(a,1);
    int blen=tobin(b,0);

    /*for(int i=0; i<alen; i++) {
        printf("%d", abin[i]);
    }

    printf("\n");

    for(int i=0; i<blen; i++) {
        printf("%d", bbin[i]);
    }

    printf("\n");*/


    if(alen==blen) {
        long long bto1s=0;

        for(int i=0; i<blen-1; i++) {
            if(bbin[i]) {
                int set_1s = b_am1[blen-1]-b_am1[i];
                long long fronttime=1;
                for(int j=0; j<i;j++) {
                    fronttime*=2;
                }
                bto1s+=set_1s*fronttime;
                bto1s+=back1s(i);
            }
        }

        long long ato1s=0;
        for(int i=0; i<alen-1; i++) {
            if(abin[i]) {
                int set_1s = a_am1[alen-1]-a_am1[i];

                long long fronttime=1;
                for(int j=0; j<i;j++) {
                    fronttime*=2;
                }

                ato1s+=set_1s*fronttime;
                ato1s+=back1s(i);
            }
        }

        //printf("%d %d %d %d\n", bto1s, ato1s, b_am1[blen-1], a_am1[alen-1]);

        if(a==b) {
            printf("%lld", bto1s-ato1s+a_am1[blen-1]);
        }
        else {
            printf("%lld", bto1s-ato1s+b_am1[blen-1]);
        }
    }
    else {
        long long between_1s=0;


        for(int i=alen+1; i<blen; i++) {
            between_1s+=cal1s(i);
        }

        long long bto1s=0;

        for(int i=0; i<blen-1; i++) {
            if(bbin[i]) {
                int set_1s = b_am1[blen-1]-b_am1[i];
                long long fronttime=1;
                for(int j=0; j<i;j++) {
                    fronttime*=2;
                }
                bto1s+=set_1s*fronttime;
                bto1s+=back1s(i);
            }
        }
        //printf("%lld\n", bto1s);

        long long ato1s=0;
        for(int i=0; i<alen-1; i++) {
            if(!abin[i]) {
                int set_1s = a_am1[alen-1]-a_am1[i]+1;

                long long fronttime=1;
                for(int j=0; j<i;j++) {
                    fronttime*=2;
                }

                ato1s+=set_1s*fronttime;
                ato1s+=back1s(i);
            }
        }

        //printf("%lld\n", ato1s);

        printf("%lld", between_1s+bto1s+ato1s+b_am1[blen-1]+a_am1[alen-1]);
    }




    return 0;
}
