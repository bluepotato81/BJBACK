#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct{
    int u;
    int v;
    int dis;
}edge;

vector<edge> edges;
vector<int> parent;

int compare(edge a, edge b) {
    return (a.dis<b.dis);
}

int seek(int x) {
    if (parent[x]==x) {
        return x;
    }
    return parent[x]=seek(parent[x]);
}


void one(int x,int y) {
    int rootx = seek(x);
    int rooty = seek(y);
    if (rootx != rooty) {
        parent[rootx] = rooty;
    }
}

int solve(int v) {
    int mst = 0;
    int cou = 0;

    sort(edges.begin(), edges.end(), compare);

    parent.resize(v+1);
    for (int i=1; i<=v; i++) {
        parent[i]=i;
    }

    for (edge e:edges) {
        if (seek(e.u) != seek(e.v)) {
            mst += e.dis;
            one(e.u, e.v);
            cou++;
            if (cou == v - 1) {
                break;
            }
        }
    }

    return mst;
}


int main() {
    int v,e;
    scanf("%d %d", &v, &e);

    int a,b,c;
    for(int i=0; i<e;i++) {
        scanf("%d %d %d", &a, &b, &c);
        edges.push_back({a,b,c});
    }

    int weight=solve(v);

    printf("%d", weight);




    return 0;
}
