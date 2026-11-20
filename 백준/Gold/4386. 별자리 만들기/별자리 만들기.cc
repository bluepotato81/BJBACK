#include <stdio.h>
#include <math.h>
#include <float.h>

typedef struct{
    int o;
    int t;
}edge;

int main() {
    int n;
    scanf("%d", &n);

    float x[n];
    float y[n];

    for(int i=0; i<n;i++) {
        scanf("%f %f", &x[i], &y[i]);
    }

    float len[n][n];

    for(int i=0; i<n;i++) {
        for(int j=0; j<n;j++) {
            len[i][j]=sqrt((x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]));
        }
    }

    float cc[n];
    edge ce[n];
    int explored[n];

    for(int i=0; i<n;i++) {
        cc[i]=FLT_MAX;
        explored[i]=0;
        ce[i].o=-1;
        ce[i].t=-1;
    }

    int seen=n;

    int start=0;
    cc[start]=0;

    while(seen>0) {
        int curvex;
        float mincost=FLT_MAX;
        for(int i=0; i<n; i++) {
            if(explored[i]==0 && mincost>cc[i]) {
                mincost=cc[i];
                curvex=i;
            }
        }
        explored[curvex]=1;
        seen--;

        for(int i=0; i<n;i++) {
            if(explored[i]==0 && len[curvex][i]<cc[i]) {
                cc[i]=len[curvex][i];
                ce[i].o=curvex;
                ce[i].t=i;
            }
        }

    }
    float res=0;
    for(int i=0; i<n;i++) {
        if(ce[i].o!=-1) {
            res+=cc[i];
        }
    }
    printf("%.2f", res);
    return 0;
}
