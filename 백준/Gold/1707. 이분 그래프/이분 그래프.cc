#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> near;
vector<int> colors;

int check=0;

void dfs(int r, int color) {
    colors[r]=color;
    int nextcolor = (color==1)?2:1;
    for(int next:near[r]) {
        if(colors[next]==0) {
            dfs(next, nextcolor);
        }
        else if(colors[next]==color) {
            check=1;
        }
    }
}


int main() {
    int k;
    scanf("%d", &k);

    for(int i=0; i<k; i++) {
        int v,e;
        scanf("%d %d", &v, &e);

        near.clear();
        near.resize(v+1);
        colors.clear();
        colors.resize(v+1, 0);
        check=0;

        int a,b;
        for(int i=0; i<e; i++) {
            scanf("%d %d", &a,&b);
            near[a].push_back(b);
            near[b].push_back(a);
        }

        for(int i=1; i<=v; i++) {
            sort(near[i].begin(), near[i].end());
        }

        for(int i=1; i<=v; i++) {
            if(colors[i]==0) {
                dfs(i,1);
            }
        }

        if(check) {
            printf("NO\n");
        }
        else {
            printf("YES\n");
        }
    }




    return 0;
}
