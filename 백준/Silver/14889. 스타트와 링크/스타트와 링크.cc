#include <stdio.h>

int sc[21][21];

void diff(int n,int used[], int *min_ch, int count, int idx) {
    if(count == n/2) {
        int st=0, li=0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(used[i]==1 && used[j]==1) {
                    st+=sc[i][j];
                }
                if(used[i]==0 && used[j]==0) {
                    li+=sc[i][j];
                }
            }
        }
        int k;
        if(st-li<0) {
            k=li-st;
        }
        else {
            k=st-li;
        }
        if((*min_ch)>k) {
            (*min_ch) = k;
        }
        return;
    }

    for(int i=idx; i<n; i++) {
        used[i]=1;
        diff(n, used, min_ch, count+1, i+1);
        used[i]=0;
    }

}


int main() {
    int n;
    scanf("%d", &n);
    int tot=0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            scanf("%d", &sc[i][j]);
            tot+=sc[i][j];
        }
    }
    int min_ch=10000000;
    int used[n];
    for(int i=0; i<n; i++) {
        used[i]=0;
    }
    diff(n, used, &min_ch,0, 0);

    printf("%d", min_ch);

    return 0;
}
