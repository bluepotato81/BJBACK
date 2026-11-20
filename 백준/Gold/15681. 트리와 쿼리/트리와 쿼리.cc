#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> tree;
vector<int> parent;
vector<vector<int>> son;
vector<int> treesize;

void relate(int a) {
    for(int node : tree[a]) {
        if(node!=parent[a]) {
            parent[node]=a;
            son[a].push_back(node);
            relate(node);
        }
    }
}

void below(int k) {
    treesize[k]=1;
    for(int node:son[k]) {
        below(node);
        treesize[k]+=treesize[node];
    }
}

int main() {
    int n,r,q;
    scanf("%d %d %d", &n, &r, &q);

    tree.resize(n+1);

    int a,b;
    for(int i=0; i<n-1;i++) {
        scanf("%d %d", &a, &b);
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    parent.resize(n+1,0);
    son.resize(n+1);
    treesize.resize(n+1);

    relate(r);
    below(r);

    int u;
    for(int i=0; i<q; i++) {
        scanf("%d", &u);
        printf("%d\n", treesize[u]);

    }

    return 0;
}
