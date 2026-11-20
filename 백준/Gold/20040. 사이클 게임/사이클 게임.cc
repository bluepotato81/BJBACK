#include <iostream>
#include <vector>

using namespace std;

vector<int> parent, ranks;

int find(int x) {
    if(parent[x]!=x) {
        parent[x]=find(parent[x]);
    }
    return parent[x];
}

int combine(int x, int y) {
    int xpar=find(x);
    int ypar=find(y);

    if(xpar==ypar) {
        return 0;
    }

    if(ranks[xpar]>ranks[ypar]) {
        parent[ypar]=xpar;
    }
    else if(ranks[xpar]<ranks[ypar]) {
        parent[xpar]=ypar;
    }
    else {
        parent[ypar]=xpar;
        ranks[xpar]++;
    }

    return 1;
}


int main() {
    int n,m;
    scanf("%d %d", &n, &m);

    int ans=0;

    parent.resize(n+1);
    ranks.resize(n+1,0);

    for(int i=1; i<=n; i++) {
        parent[i]=i;
    }


    for(int i=0; i<m; i++) {
        int a,b;
        scanf("%d %d", &a, &b);

        if(!combine(a,b) && ans==0) {
            ans=i+1;
        }
    }

    printf("%d", ans);



    return 0;
}
