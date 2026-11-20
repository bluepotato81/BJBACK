#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> items(30);
vector<int> com1, com2;

int n,c;

void combine(vector<int>& v, int in, int x, int end) {
    if(x>c) {
        return;
    }
    if(in==end) {
        v.push_back(x);
        return;
    }
    combine(v,in+1, x+items[in], end);
    combine(v, in+1, x, end);
}

int main() {
    scanf("%d %d", &n, &c);
    for(int i=0; i<n; i++) {
        scanf("%d", &items[i]);
    }

    combine(com1, 0, 0, n/2);
    combine(com2, n/2, 0, n);

    sort(com2.begin(), com2.end());

    long long ans=0;
    for(int x:com1) {
        ans+=upper_bound(com2.begin(), com2.end(), c-x) - com2.begin();
    }

    printf("%d", ans);

    return 0;
}
