#include <iostream>
#include <vector>

using namespace std;

typedef struct{
    long long des;
    long long val;
}road;

vector<vector<road>> farm;
long long n;
vector<long long> below;
vector<long long> visited;
vector<long long> res;

void belcal(long long x) {
    visited[x]=1;
    long long tot=1;
    for(road i:farm[x]) {
        if(visited[i.des]==0) {
            belcal(i.des);
            tot+=below[i.des];
        }
    }
    below[x]=tot;
}

long long stan=0;

long long onedis(long long x) {
    visited[x]=1;
    long long tot=0;
    for(road i:farm[x]) {
        if(visited[i.des]==0) {
            tot+=i.val*below[i.des];
            tot+=onedis(i.des);
        }
    }
    //printf("%d %d\n", x, tot);
    return tot;
}

void rescal(long long x) {
    visited[x]=1;
    for(road i:farm[x]) {
        if(visited[i.des]==0) {
            res[i.des]=res[x] - (i.val)*(2*below[i.des]-n);
            rescal(i.des);
        }
    }
}

int main() {

    scanf("%lld", &n);

    farm.resize(n+1);

    long long a,b,c;
    for(long long i=0; i<n-1;i++) {
        scanf("%lld %lld %lld", &a, &b, &c);
        farm[a].push_back({b,c});
        farm[b].push_back({a,c});
    }

    below.resize(n+1,0);
    visited.resize(n+1,0);

    belcal(1);

    visited.resize(0);
    visited.resize(n+1,0);

    stan=onedis(1);


    visited.resize(0);
    visited.resize(n+1,0);

    res.resize(n+1);
    res[1]=stan;

    rescal(1);

    for(long long i=1; i<=n;i++) {
        printf("%lld\n", res[i]);
    }





    return 0;
}
