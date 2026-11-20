#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    int nums[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    vector<int> bucket;
    vector<int> previous(n, -1);
    vector<int> lastIndex(n, -1);

    int maxlen = 0;
    int endIndex = -1;

    for(int i = 0; i < n; i++) {
        auto it = lower_bound(bucket.begin(), bucket.end(), nums[i]);

        int pos = it - bucket.begin();
        if (pos < bucket.size()) {
            bucket[pos] = nums[i];
        } else {
            bucket.push_back(nums[i]);
        }

        lastIndex[pos] = i;

        if (pos > 0) {
            previous[i] = lastIndex[pos - 1];
        }

        if (pos + 1 > maxlen) {
            maxlen = pos + 1;
            endIndex = i;
        }
    }

    vector<int> lis;
    for (int i = endIndex; i != -1; i = previous[i]) {
        lis.push_back(nums[i]);
    }

    reverse(lis.begin(), lis.end());

    printf("%d\n", maxlen);
    for (int i = 0; i < maxlen; i++) {
        printf("%d ", lis[i]);
    }

    return 0;
}
