#include <iostream>
#include <vector>

#define INF 2000000000

using namespace std;

int small[201][201];
int large[201][201];

int main() {
    int n,m;
    scanf("%d %d", &n, &m);

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            small[i][j]=INF;
            large[i][j]=-1;
        }
    }

    for(int i=1;i<=n;i++) {
        small[i][i]=0;
    }

    int s,e,l;
    for(int i=0; i<m;i++) {
        scanf("%d %d %d", &s, &e, &l);

        if(large[s][e]<l) {
            large[s][e]=l;
            large[e][s]=l;
        }

        if(small[s][e]>l) {
            small[s][e]=l;
            small[e][s]=l;
        }

    }

    for(int k=1;k<=n;k++) {
        for(int i=1; i<=n;i++) {
            for(int j=1; j<=n;j++) {
                if(small[i][k] < INF && small[k][j] < INF) {
                    small[i][j] = min(small[i][j], small[i][k] + small[k][j]);
                }
            }
        }
    }

    double ans=INF;

    for(int i=1; i<=n;i++) {
        double peak=0;
        for(int j=1; j<=n;j++) {
            for(int k=1; k<=n;k++) {
                int maxlen=large[j][k];

                if(maxlen!=-1) {
                    double toburn=maxlen-(small[i][k]-small[i][j]);

                    if(toburn>0) {
                        double done=(toburn/2)+small[i][k];
                        peak=max(peak,done);
                    }
                }
            }
        }
        ans=min(peak,ans);
    }

    printf("%.1f", ans);



    return 0;
}
