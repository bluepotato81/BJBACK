#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);

    while(t--) {
        int n;
        scanf("%d", &n);

        int prev[n];
        for(int i=0; i<n;i++) {
            scanf("%d", &prev[i]);
        }

        int dir[n+1][n+1];

        for(int i=0; i<n;i++) {
            for(int j=0; j<n;j++) {
                if(i<j) {
                    dir[prev[i]][prev[j]]=1;
                }
                else {
                    dir[prev[i]][prev[j]]=0;
                }
            }
        }

        int m;
        scanf("%d", &m);

        for(int i=0;i<m;i++) {
            int a,b;
            scanf("%d %d", &a, &b);
            dir[a][b]=(dir[a][b]+1)%2;
            dir[b][a]=(dir[b][a]+1)%2;
        }

        int ins[n+1]={0, };

        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                if(dir[j][i]==1) {
                    ins[i]++;
                }
            }
        }

        vector<int> order;
        int check=0;

        for(int j=0; j<n;j++) {
            int num=0;
            int cen;
            for(int i=1; i<=n;i++) {
                if(ins[i]==0) {
                    cen=i;
                    order.push_back(i);
                    num++;
                }
            }
            if(num==0) {
                check=2;
                break;
            }
            else if(num>1) {
                check=1;
                break;
            }

            for(int i=1;i<=n;i++) {
                if(dir[cen][i]=1) {
                    ins[i]--;
                }
            }

        }

        if(check==1) {
            printf("?\n");
        }
        else if(check==2) {
            printf("IMPOSSIBLE\n");
        }
        else {
            for(int i=0; i<n;i++) {
                printf("%d ", order[i]);
            }
            printf("\n");
        }



    }


    return 0;
}
