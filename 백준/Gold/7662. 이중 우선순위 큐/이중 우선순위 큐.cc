#include <iostream>
#include <queue>
#include <set>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);

    while(t--) {
        priority_queue<long long> max_pq;
        priority_queue<long long, vector<long long>, greater<long long>> min_pq;
        multiset<long long> tracker;
        int k;
        scanf("%d", &k);

        char input;
        long long in;
        for(int i=0; i<k;i++) {
            scanf(" %c %lld", &input, &in);
            if(input=='I') {
                max_pq.push(in);
                min_pq.push(in);
                tracker.insert(in);
            }
            else {
                if (tracker.empty()) continue;

                if(in==1) {
                    while (!max_pq.empty() && tracker.find(max_pq.top()) == tracker.end())
                        max_pq.pop();
                    if (!max_pq.empty()) {
                        tracker.erase(tracker.find(max_pq.top()));
                        max_pq.pop();
                    }
                }
                else {
                    while (!min_pq.empty() && tracker.find(min_pq.top()) == tracker.end())
                        min_pq.pop();
                    if (!min_pq.empty()) {
                        tracker.erase(tracker.find(min_pq.top()));
                        min_pq.pop();
                    }
                }
            }

        }

        while (!max_pq.empty() && tracker.find(max_pq.top()) == tracker.end())
            max_pq.pop();
        while (!min_pq.empty() && tracker.find(min_pq.top()) == tracker.end())
            min_pq.pop();

        if (tracker.empty()) {
            printf("EMPTY\n");
        } else {
            printf("%lld %lld\n", max_pq.top(), min_pq.top());
        }
    }

    return 0;
}

