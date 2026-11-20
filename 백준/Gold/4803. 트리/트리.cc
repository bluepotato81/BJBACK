#include <iostream>
#include <vector>

using namespace std;

int treenum;
int nodecount;
int edgecount;
vector<int> nodes;
vector<vector<int>> edges;

void dfs(int n,int parent, int lev) {
    nodes[n]=1;
    for(int next: edges[n]) {
        if(nodes[next]!=1) {
            dfs(next,n, lev+1);
            nodecount++;
            edgecount++;
        }
        else if(next!=parent) {
            edgecount++;
        }
    }
    if(lev==0) {
        if(edgecount==nodecount-1) {
            treenum++;
        }
    }
    return;
}

int main() {
    int cs=0;
    while(1) {
        cs++;
        treenum=0;
        int a,b;
        scanf("%d %d", &a, &b);
        if(a==0 && b==0) {
            break;
        }
        nodes.resize(a+1,0);
        edges.resize(a+1);
        int in1, in2;
        for(int i=0; i<b; i++) {
            scanf("%d %d", &in1, &in2);
            edges[in1].push_back(in2);
            edges[in2].push_back(in1);
        }
        for(int i=1; i<=a; i++) {
            nodecount=1;
            edgecount=0;
            if(nodes[i]==0) {
                dfs(i, 0, 0);
                //printf("cycled at %d.\n", i);
            }
        }
        if(treenum==1) {
            printf("Case %d: There is one tree.\n", cs);
        }
        else if(treenum==0) {
            printf("Case %d: No trees.\n", cs);
        }
        else {
            printf("Case %d: A forest of %d trees.\n",cs, treenum);
        }
        nodes.clear();
        edges.clear();
    }



    return 0;
}
