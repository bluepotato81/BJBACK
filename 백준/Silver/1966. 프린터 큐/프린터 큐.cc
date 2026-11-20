#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int order;
    int importance;
} print;

int main() {
    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; i++) {
        int n, m;
        scanf("%d %d", &n, &m);

        print papers[n];

        for (int j = 0; j < n; j++) {
            scanf("%d", &papers[j].importance);
            papers[j].order = j;
        }

        int printedCount = 0;
        while (1) {
            int maxImportance = papers[0].importance;
            for (int k = 1; k < n; k++) {
                if (papers[k].importance > maxImportance) {
                    maxImportance = papers[k].importance;
                }
            }

            if (papers[0].importance == maxImportance) {
                printedCount++;
                if (papers[0].order == m) {
                    printf("%d\n", printedCount);
                    break;
                }

                // Move the queue to the left
                for (int l = 1; l < n; l++) {
                    papers[l - 1] = papers[l];
                }
                n--;
            } else {
                // Move the first element to the end of the queue
                print temp = papers[0];
                for (int l = 1; l < n; l++) {
                    papers[l - 1] = papers[l];
                }
                papers[n - 1] = temp;
            }
        }
    }
    return 0;
}
