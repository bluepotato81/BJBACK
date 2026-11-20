#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare_string(const void *a, const void *b) {
    const char *string1 = *(const char **)a;
    const char *string2 = *(const char **)b;
    return strcmp(string1, string2);
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    char *strings[n];
    for (int i = 0; i < n; i++) {
        strings[i] = malloc(501 * sizeof(char));
        scanf("%s", strings[i]);
    }

    qsort(strings, n, sizeof(char *), compare_string);

    int num = 0;
    for (int i = 0; i < m; i++) {
        char k[501];
        scanf("%s", k);
        int l = 0;
        int r = n - 1;
        int found = 0;
        while (l <= r) {
            int mid = (l + r) / 2;
            int cmp = strcmp(k, strings[mid]);
            if (cmp > 0) {
                l = mid + 1;
            } else if (cmp < 0) {
                r = mid - 1;
            } else {
                found = 1;
                break;
            }
        }
        if (found) {
            num++;
        }
    }

    printf("%d\n", num);


    return 0;
}
