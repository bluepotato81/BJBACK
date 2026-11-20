#include <stdio.h>

int parent[1000001];
int rank[1000001];

int find(int n) {
    if(parent[n]!=n) {
         parent[n] = find(parent[n]);
    }
    return parent[n];
}

void uni(int x, int y) {
    int rx=find(x);
    int ry=find(y);

    if(rx!=ry) {
        if(rank[rx]>rank[ry]) {
            parent[ry]=rx;
        }
        else if(rank[rx]< rank[ry]) {
            parent[rx]=ry;
        }
        else {
            parent[ry]=rx;
            rank[rx]++;
        }
    }
}

int main() {
    int n,m;
    scanf("%d %d", &n, &m);
    for(int i=0; i<=n; i++) {
        parent[i]=i;
        rank[i]=0;
    }
    int a,b,c;
    for(int i=0; i<m; i++) {
        scanf("%d %d %d",&a, &b, &c);
        if(a==0) {
            uni(b,c);
        }
        else if(a==1) {
            if(find(b)==find(c)) {
                printf("YES\n");
            }
            else {
                printf("NO\n");
            }
        }
    }

    return 0;
}
