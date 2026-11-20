#include <stdio.h>
#include <limits.h>

int main() {
    int t;
    scanf("%d", &t);

    while(t--) {
        int n,m;
        scanf("%d %d", &n, &m);

        int s[m];
        int d[m];

        for(int i=0; i<m;i++) {
            scanf("%d %d", &s[i], &d[i]);
            s[i]--;
            d[i]--;
        }

        int cc[n];
        int ce[n];

        for(int i=0; i<n; i++) {
            cc[i]=INT_MAX;
            ce[i]=-1;
        }

        int exnum=n;
        int explored[n];

        for(int i=0; i<n; i++) {
            explored[i]=0;
        }

        int start=0;
        cc[start]=0;

        while(exnum>0) {
            int curvex;
            int mincost=INT_MAX;
            for(int i=0; i<n; i++) {
                if(explored[i]==0 && mincost>cc[i]) {
                    mincost=cc[i];
                    curvex=i;
                }
            }

            explored[curvex]=1;
            exnum--;

            for(int i=0; i<m;i++) {
                if(s[i]==curvex && explored[d[i]]==0 && 1<cc[d[i]]) {
                    cc[d[i]]=1;
                    ce[d[i]]=i;
                }
            }

            for(int i=0; i<m;i++) {
                if(d[i]==curvex && explored[s[i]]==0 && 1<cc[s[i]]) {
                    cc[s[i]]=1;
                    ce[s[i]]=i;
                }
            }
        }

        int result=0;
        for(int i=0;i<n;i++) {
            if(ce[i]!=-1) {
                result++;
            }
        }

        printf("%d\n", result);


    }


    return 0;
}
