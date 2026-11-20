#include <iostream>
#include <stdlib.h>
#include <queue>

typedef struct {
    int weight;
    int value;
}jewel;

jewel gems[300000];
int bag[300000];

int comparej(const void *a, const void *b) {
    jewel *A = (jewel *)a;
    jewel *B = (jewel *)b;

    return A->weight - B->weight;
}

int compareb(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}



int main() {
    int n,k;
    scanf("%d %d", &n, &k);

    for(int i=0; i<n; i++) {
        scanf("%d %d", &gems[i].weight, &gems[i].value);
    }

    for(int i=0; i<k;i++) {
        scanf("%d", &bag[i]);
    }

    qsort(gems, n, sizeof(jewel), comparej);
    qsort(bag, k, sizeof(int), compareb);


    std::priority_queue<int> pq;

    long long total = 0;
    int gindex=0;

    for(int i=0; i<k; i++) {
        int cap=bag[i];

        while(gindex<n && gems[gindex].weight<=cap) {
            pq.push(gems[gindex].value);
            gindex++;
        }

        if(!pq.empty()) {
            total+=pq.top();
            pq.pop();
        }

    }

    printf("%lld", total);

    return 0;
}
