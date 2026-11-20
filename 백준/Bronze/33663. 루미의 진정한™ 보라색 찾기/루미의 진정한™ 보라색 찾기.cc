#include <stdio.h>

int main() {
    int h1,h2,s1,s2,v1,v2,r,g,b,M,m;
    scanf("%d %d\n%d %d\n%d %d\n%d %d %d", &h1, &h2, &s1, &s2, &v1, &v2, &r, &g, &b);

    int comp[3];
    comp[0]=r;
    comp[1]=g;
    comp[2]=b;

    M=0;
    m=255;
    int Mid;
    for(int i=0; i<3; i++) {
        if(M<comp[i]) {
            M=comp[i];
            Mid=i;
        }
        if(m>comp[i]) {
            m=comp[i];
        }
    }

    int V=M;
    int S=255*(V-m);
    int H;

    if(Mid==0) {
        H=60*(g-b);
    }
    else if(Mid==1) {
        H=(120*(V-m))+(60*(b-r));
    }
    else {
        H=(240*(V-m))+(60*(r-g));
    }

    if(H<0) {
        H+=360*(V-m);
    }

    if(V>=v1 && V<=v2 && S>=s1*V && S<=s2*V && H>=h1*(V-m) && H<=h2*(V-m)) {
        printf("Lumi will like it.");
    }
    else {
        printf("Lumi will not like it.");
    }
    return 0;
}
