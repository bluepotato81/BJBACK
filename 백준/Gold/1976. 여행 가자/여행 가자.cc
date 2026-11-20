#include <stdio.h>

int parent[201];
int rank[201];
int asked[201];

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
    scanf("%d\n%d", &n, &m);
    for(int i=0; i<=n; i++) {
        parent[i]=i;
        rank[i]=0;
    }
    int in;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            scanf("%d", &in);
            if(in==1) {
                uni(i+1, j+1);
            }
        }
    }
    for(int i=0; i<m; i++) {
        scanf("%d", &in);
        asked[in]=1;
    }


    int index=1;
    while(1) {
        if(asked[index]==1) {
            break;
        }
        index++;
    }


    int key=find(index);
    for(int i=index+1; i<=n; i++) {
        if(asked[i]==1) {
            if(key!=find(i)) {
                printf("NO");
                return 0;
            }
        }
    }

    printf("YES");

    return 0;
}
