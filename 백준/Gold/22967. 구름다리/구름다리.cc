#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    vector<vector<int>> bu;
    bu.resize(n+1);

    int noo=n-1;
    int nooc[n+1];

    for(int i=1; i<=n;i++) {
        nooc[i]=0;
    }

    int a,b;
    for(int i=0; i<n-1;i++) {
        scanf("%d %d", &a, &b);
        if(a==1) {
            noo--;
            nooc[b]=1;
        }
        if(b==1) {
            noo--;
            nooc[a]=1;
        }
        bu[a].push_back(b);
        bu[b].push_back(a);
    }

    if(n==2) {
        printf("0\n");
        printf("1\n");
        return 0;
    }

    if(n==3) {
        printf("1\n");
        printf("1\n");
        for(int i=1; i<=n;i++) {
            int yes[n+1];
            for(int j=1;j<=n;j++) {
                yes[j]=0;
            }
            for(int k:bu[i]) {
                yes[k]=1;
            }
            for(int j=1;j<=n;j++) {
                if(i<j && yes[j]==0) {
                    printf("%d %d\n", i, j);
                }
            }
        }
        return 0;
    }

    if(n==4) {
        printf("3\n");
        printf("1\n");
        for(int i=1; i<=n;i++) {
            int yes[n+1];
            for(int j=1;j<=n;j++) {
                yes[j]=0;
            }
            for(int k:bu[i]) {
                yes[k]=1;
            }
            for(int j=1;j<=n;j++) {
                if(i<j && yes[j]==0) {
                    printf("%d %d\n", i, j);
                }
            }
        }
        return 0;
    }

    printf("%d\n", noo);
    printf("2\n");
    for(int i=2; i<=n;i++) {
        if(nooc[i]==0) {
            printf("%d %d\n", 1, i);
        }
    }

    return 0;
}
