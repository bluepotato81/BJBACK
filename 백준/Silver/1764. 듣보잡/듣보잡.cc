#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[21];
    int order;
} person;

// Corrected comparison function
int compare_string(const void *a, const void *b) {
    const person *person1 = (const person *)a;
    const person *person2 = (const person *)b;
    return strcmp(person1->name, person2->name);
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    person no_hear[n];
    for (int i = 0; i < n; i++) {
        scanf("%s", no_hear[i].name);
        no_hear[i].order = i;
    }

    qsort(no_hear, n, sizeof(person), compare_string);

    person no_hear_see[n];
    int count = 0;

    for (int i = 0; i < m; i++) {
        char in_see[21];
        scanf("%s", in_see);

        int l = 0;
        int r = n - 1;
        int found = 0;

        while (l <= r) {
            int mid = (l + r) / 2;
            int cmp = strcmp(no_hear[mid].name, in_see);
            if (cmp > 0) {
                r = mid - 1;
            } else if (cmp < 0) {
                l = mid + 1;
            } else {
                found = 1;
                break;
            }
        }

        if (found) {
            strcpy(no_hear_see[count].name, in_see);
            no_hear_see[count].order = i;
            count++;
        }
    }

    // Sort the resulting array by names
    qsort(no_hear_see, count, sizeof(person), compare_string);

    // Print the results
    printf("%d\n", count);
    for (int i = 0; i < count; i++) {
        printf("%s\n", no_hear_see[i].name);
    }

    return 0;
}
