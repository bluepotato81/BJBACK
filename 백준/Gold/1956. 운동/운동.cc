#include <stdio.h>

#define INT_MAX 2147483647

typedef struct {
    int start;
    int end;
    int cost;
} bus;

int dist[400][400];

void floyd(int n) {
    for (int i = 0; i < n; i++) {
        dist[i][i] = 0;
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dist[i][j] = INT_MAX;
        }
    }


    for (int i = 0; i < m; i++) {
        int start, end, cost;
        scanf("%d %d %d", &start, &end, &cost);
        start--;
        end--;
        if (dist[start][end] > cost) {
            dist[start][end] = cost;
        }
    }


    floyd(n);


    int min = INT_MAX;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j && dist[i][j] != INT_MAX && dist[j][i] != INT_MAX) {
                int cycle_cost = dist[i][j] + dist[j][i];
                if (cycle_cost < min) {
                    min = cycle_cost;
                }
            }
        }
    }


    if (min == INT_MAX) {
        printf("-1\n");
    } else {
        printf("%d\n", min);
    }

    return 0;
}
