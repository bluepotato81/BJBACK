#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

long long in[3000][4];
vector<vector<int>> group;

int parent[3000];
vector<int> siz;

int seek(int x) {
    if(parent[x]==x) {
        return x;
    }
    else {
        return parent[x]=seek(parent[x]);
    }
}

void unite(int a, int b) {
    a=seek(a);
    b=seek(b);
    if(a!=b) {
        if(siz[a]<siz[b]) {
            swap(a,b);
        }
        parent[b]=a;
        siz[a]+=siz[b];
    }
}

int si(int x) {
    return siz[seek(x)];
}

long long ori(long long a, long long b, long long c, long long d, long long e, long long f) {
    long long k = (d-b)*(e-c) - (c-a)*(f-d);
    if(k>0) {
        return 1;
    }
    else if(k==0) {
        return 0;
    }
    else {
        return -1;
    }
}

long long mi(long long x, long long y) {
    if(x<y) {
        return x;
    }
    else {
        return y;
    }
}
long long ma(long long x, long long y) {
    if(x>y) {
        return x;
    }
    else {
        return y;
    }
}

int on_segment(long long a, long long b, long long c, long long d, long long e, long long f) {
    return mi(a, c) <= e && e <= ma(a, c) && mi(b, d) <= f && f <= ma(b, d);
}

int check(long long a, long long b,long long c,long long d,long long e,long long f,long long g,long long h) {
 long long o1=ori(a,b,c,d,e,f);
    long long o2=ori(a,b,c,d,g,h);
    long long o3=ori(e,f,g,h,a,b);
    long long o4=ori(e,f,g,h,c,d);

    if(o1*o2<0 && o3*o4<0) {
        return 1;
    }
    else if(o1*o2==0 || o3*o4==0) {
        if ((o1 == 0 && on_segment(a, b, c, d, e, f)) ||
            (o2 == 0 && on_segment(a, b, c, d, g, h)) ||
            (o3 == 0 && on_segment(e, f, g, h, a, b)) ||
            (o4 == 0 && on_segment(e, f, g, h, c, d))) {
            return 1;
        }
        else {
            return 0;
        }
    }
    else{
        return 0;
    }

    return 0;
}

int main() {
    int n;
    scanf("%d", &n);

    siz.resize(n,1);
    for(int i=0; i<n;i++) {
        for(int j=0; j<4;j++) {
            scanf("%lld", &in[i][j]);
        }
        parent[i]=i;
    }

    for(int i=0; i<n;i++) {
        for(int j=i+1;j<n;j++) {
            if(check(in[i][0], in[i][1], in[i][2], in[i][3],in[j][0], in[j][1], in[j][2], in[j][3])) {
                unite(i,j);
            }
        }
    }

    unordered_set<int> roots;
    int m=0;
    for(int i=0;i<n;i++) {
        roots.insert(seek(i));
        m=max(m,si(i));
    }


    printf("%zu\n", roots.size());
    printf("%d", m);


    return 0;
}
