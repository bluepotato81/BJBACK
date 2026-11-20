#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector<int> suffix(const string &s) {
    int n=s.size();
    vector<int> sa(n), ranks(n), tmp(n);

    for (int i = 0; i<n; ++i) {
        sa[i]=i;
        ranks[i]=s[i];
    }

    for (int k=1; k<n; k<<=1) {
        auto cmp = [&](int i, int j) {
            if (ranks[i]!= ranks[j]) {
                return ranks[i] < ranks[j];
            }
            int ri = i+k<n ? ranks[i+k] : -1;
            int rj = j+k<n ? ranks[j+k] : -1;
            return ri<rj;
        };
        sort(sa.begin(), sa.end(), cmp);

        tmp[sa[0]]=0;
        for (int i=1; i<n; ++i)
            tmp[sa[i]]=tmp[sa[i-1]]+cmp(sa[i-1],sa[i]);
        ranks=tmp;
    }

    return sa;
}
vector<int> genlcp(const string &s, const vector<int> &sa) {
    int n=s.size();
    vector<int> r(n), lcp(n-1);

    for (int i=0; i<n; ++i)
        r[sa[i]]=i;

    int h=0;
    for (int i=0; i<n; ++i) {
        if (r[i]>0) {
            int j=sa[r[i]-1];
            while (i+h<n && j+h<n && s[i+h]==s[j+h]){
                ++h;
            }
                
            lcp[r[i]-1]=h;
            if (h>0) {
                --h;
            }
        }
    }

    return lcp;
}

int main() {
    string input;
    cin >> input;

    vector<int> sa = suffix(input);
    vector<int> lcp = genlcp(input, sa);

    int max_len = 0;
    for (int len : lcp)
        max_len = max(max_len, len);

    printf("%d", max_len);
    return 0;
}
