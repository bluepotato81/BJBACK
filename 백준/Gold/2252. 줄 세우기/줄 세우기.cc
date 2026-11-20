#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> graph;

int main() {
    int n,m;
    scanf("%d %d", &n, &m);

    graph.resize(n+1);

    int in[n+1] ={0, };

    for(int i=0;i<m;i++) {
        int a,b;
        scanf("%d %d", &a, &b);
        graph[a].push_back(b);
        in[b]++;
    }

    queue<int> kahn;

    for(int i=1; i<=n;i++) {
        if(in[i]==0) {
            kahn.push(i);
        }
    }


    while(!kahn.empty()) {
        int a=kahn.front();
        for(int c:graph[a]) {
            in[c]--;
            if(!in[c]) {
                kahn.push(c);
            }
        }
        printf("%d ", a);
        kahn.pop();
    }



    return 0;
}
