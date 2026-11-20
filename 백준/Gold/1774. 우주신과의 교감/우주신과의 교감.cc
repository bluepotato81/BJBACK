#include <stdio.h>
#include <math.h>
#include <float.h>

typedef struct{
    long long o;
    long long t;
}edge;

int main() {
    long long n,m;
    scanf("%lld %lld", &n, &m);

    long long x[n];
    long long y[n];

    for(int i=0; i<n;i++) {
        scanf("%lld %lld", &x[i], &y[i]);
    }

    double len[n][n];

    for(long long i=0; i<n;i++) {
        for(long long j=0; j<n;j++) {
            len[i][j]=pow(x[i]-x[j],2)+pow(y[i]-y[j],2);
            len[i][j]=sqrt(len[i][j]);
        }
    }
    
	
	for(long long i=0; i<m; i++) {
		long long a,b;
		scanf("%lld %lld", &a, &b);
		
		len[a-1][b-1]=0;
		len[b-1][a-1]=0;
	}
	
    double cc[n];
    edge ce[n];
    long long explored[n];

    for(long long i=0; i<n;i++) {
        cc[i]=FLT_MAX;
        explored[i]=0;
        ce[i].o=-1;
        ce[i].t=-1;
    }

    long long seen=n;

    long long start=0;
    cc[start]=0;

    while(seen>0) {
        long long curvex;
        double mincost=FLT_MAX;
        for(long long i=0; i<n; i++) {
            if(explored[i]==0 && mincost>cc[i]) {
                mincost=cc[i];
                curvex=i;
            }
        }
        explored[curvex]=1;
        seen--;

        for(long long i=0; i<n;i++) {
            if(explored[i]==0 && len[curvex][i]<cc[i]) {
                cc[i]=len[curvex][i];
                ce[i].o=curvex;
                ce[i].t=i;
            }
        }

    }
    double res=0;
    for(long long i=0; i<n;i++) {
        if(ce[i].o!=-1) {
            res+=cc[i];
        }
    }
    printf("%.2f", res);
    return 0;
}
