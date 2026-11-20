#include <stdio.h>

int main() {
    int n,m,q;
    scanf("%d %d %d", &n, &m, &q);


    int w[n+1];
    int a,d;

    for(int i=1;i<=n;i++) {
        w[i]=0;
    }

    for(int i=1; i<=m;i++) {
        scanf("%d %d", &a, &d);
        w[a]=d;
    }

    int p[q];
    for(int i=0; i<q;i++) {
        scanf("%d", &p[i]);
    }

    long long comp[n+1];
    long long c=0;
    comp[0]=0;
    for(int i=1;i<=n;i++) {
        if(w[i]!=0) {
            c+=w[i];
            comp[i]=c;
        }
        else {
            comp[i]=c;
        }
        //printf("%d ", comp[i]);
    }

    int l=0;
    int r=n;

    for(int i=0;i<q;i++) {
        if(p[i]>r) {
            printf("0\n");
            continue;
        }
        if(p[i]<l) {
            printf("0\n");
            continue;
        }
        long long lw=comp[p[i]]-comp[l];
        long long rw=comp[r]-comp[p[i]];
        if(lw>rw) {
            r=p[i];
            printf("%lld\n", rw);
        }
        else if(rw>lw) {
            l=p[i];
            printf("%lld\n", lw);
        }
        else {
            int cen=(1+n)/2;
            if(p[i]<=cen) {
                l=p[i];
                printf("%lld\n", lw);
            }
            else {
                r=p[i];
                printf("%lld\n", rw);
            }
        }
    }



    return 0;
}
