#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);

    while(t--) {
        int n;
        scanf("%d", &n);
        int in[n];
        int rec[1000][n];
        for(int i=0; i<n;i++) {
            scanf("%d", &in[i]);
            rec[0][i]=in[i];
        }
        int k=0;
        while(1) {
            k++;
            int zcheck=0;
            for(int i=0; i<n;i++) {
                if(rec[k-1][i]!=0) {
                    zcheck++;
                    break;
                }
            }
            if(!zcheck) {
                printf("ZERO\n");
                break;
            }

            int rcheck=0;
            for(int i=0; i<k-1;i++) {
                int icheck=0;
                for(int j=0; j<n;j++) {
                    if(rec[k-1][j]!=rec[i][j]) {
                        icheck=1;
                        break;
                    }
                }
                if(!icheck) {
                    rcheck=1;
                    break;
                }
            }
            if(rcheck) {
                printf("LOOP\n");
                break;
            }

            for(int i=0; i<n-1;i++) {
                int dif=rec[k-1][i]-rec[k-1][i+1];
                if(dif<0) {
                    dif*=-1;
                }
                rec[k][i]=dif;
            }
            int dif=rec[k-1][n-1]-rec[k-1][0];
            if(dif<0) {
                dif*=-1;
            }
            rec[k][n-1]=dif;
        }
    }

    return 0;
}
