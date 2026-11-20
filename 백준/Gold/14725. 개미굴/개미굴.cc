#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;


vector<vector<vector<char>>> result;

bool antsort(const vector<vector<char>> &a, const vector<vector<char>> &b) {
    size_t n = min(a.size(), b.size());
    for(size_t i=0; i<n;i++) {
        if(a[i]<b[i]) {
            return 1;
        }
        else if(a[i]>b[i]) {
            return 0;
        }
    }
    return a.size() <b.size();
}


int main() {
    int n;
    scanf("%d", &n);

    result.resize(n);

    for(int i=0;i<n;i++) {
        int k;
        scanf("%d", &k);
        result[i].resize(k);
        for(int j=0; j<k;j++) {
            char buf[16];
            scanf("%s", buf);

            result[i][j]=vector<char>(buf, buf+strlen(buf));
        }
    }

    sort(result.begin(), result.end(), antsort);

    for (int i=0; i<n; i++) {
        size_t start=0;
        if (i > 0) {
            while (start<result[i].size() && start<result[i-1].size() && result[i][start]==result[i-1][start]) {
                start++;
            }
        }

        for (size_t j=start; j<result[i].size(); j++) {
            for (int dash=0; dash<j*2; dash++) {
                printf("-");
            }
            for (char c:result[i][j]) {
                printf("%c", c);
            }
            printf("\n");
        }
    }







    return 0;
}
