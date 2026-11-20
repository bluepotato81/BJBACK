#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

vector<int> parent;
vector<int> ran;
vector<int> siz;
unordered_map<string, int> dic;

string inf, ins;
int curid = 0;

int seek(int n) {
    if (parent[n]!=n) {
        parent[n]=seek(parent[n]);
    }
    return parent[n];
}

void uni(int x, int y) {
    int rx=seek(x);
    int ry=seek(y);

    if (rx != ry) {
        if (ran[rx] > ran[ry]) {
            parent[ry] = rx;
            siz[rx] += siz[ry];
            printf("%d\n", siz[rx]);
        } else if (ran[rx] < ran[ry]) {
            parent[rx] = ry;
            siz[ry] += siz[rx];
            printf("%d\n", siz[ry]);
        } else {
            parent[ry] = rx;
            ran[rx]++;
            siz[rx] += siz[ry];
            printf("%d\n", siz[rx]);
        }
    }
    
    else{
        printf("%d\n", siz[rx]);
    }
}

int get_1id() {
    if (dic.find(inf) == dic.end()) {
        dic[inf] = curid;
        parent[curid] = curid;
        ran[curid] = 0;
        siz[curid] = 1;
        return curid++;
    }
    return dic[inf];
}

int get_2id() {
    if (dic.find(ins) == dic.end()) {
        dic[ins] = curid;
        parent[curid] = curid;
        ran[curid] = 0;
        siz[curid] = 1;
        return curid++;
    }
    return dic[ins];
}

int main() {

    int t;
    scanf("%d", &t);

    while (t--) {
        parent.clear();
        ran.clear();
        siz.clear();
        dic.clear();
        parent.resize(200001);
        ran.resize(200001);
        siz.resize(200001);
        curid = 0;

        int f;
        scanf("%d", &f);

        while (f--) {
            cin>>inf>>ins;
            int id1 = get_1id();
            int id2 = get_2id();
            uni(id1, id2);

        }
    }

    return 0;
}
