#include <stdio.h>

int main() {
    int k;
    scanf("%d",&k);

    int w=0,h=0;
    int windex, hindex;
    int dir[6];
    int len[6];

    for(int i=0; i<6; i++) {
        int a,b;
        scanf("%d %d", &a, &b);
        if(a>2) {
            if(b>h) {
                h=b;
                hindex=i;
            }
        }
        else {
            if(b>w) {
                w=b;
                windex=i;
            }
        }

        dir[i]=a;
        len[i]=b;
    }

    int notw, noth;

    if(hindex==windex+1 || (hindex==0 && windex==5)) {
        if(windex==0) {
            noth=5;

        }
        else {
            noth=windex-1;
        }
        if(hindex==5) {
            notw=0;
        }
        else {
            notw=hindex+1;
        }
    }
    else {
        if(hindex==0) {
            notw=5;
        }
        else {
            notw=hindex-1;
        }
        if(windex==5) {
            noth=0;
        }
        else {
            noth=windex+1;
        }
    }

    int minw, minh;

    for(int i=0; i<6; i++) {
        if(i!=windex && i!=hindex && i!=noth && i!=notw) {
            if(dir[i]>2) {
                minh=i;
            }
            else {
                minw=i;
            }
        }
    }

    //printf("%d %d %d %d\n", len[hindex], len[windex], len[minh], len[minw]);
    int area=len[hindex]*len[windex]-len[minh]*len[minw];

    printf("%d", area*k);

    return 0;
}
