#include <stdio.h>

int main() {
    int N, r, c;
    scanf("%d %d %d", &N, &r, &c);

    int len=1;
    for(int i=0; i<N; i++) {
        len*=2;
    }

    int xb = 0, yb = 0;
    int pos = 0;

    while(len>1) {
        len/=2;
        if(r<yb+ len && c< xb+len) {

        }
        else if(r<yb+len && c>=xb+len) {
            pos+=len*len;
            xb+=len;
        }
        else if(r>=yb+len && c<xb+len) {
            pos += 2*len*len;
            yb+=len;
        }
        else {
            pos+= 3*len*len;
            xb+=len;
            yb+=len;
        }
    }

    printf("%d", pos);

    return 0;
}
