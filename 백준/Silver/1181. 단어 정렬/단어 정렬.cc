#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct word {
    char w[51];
    size_t len;
};

int compare(const void *a, const void *b) {
    struct word *wordA = (struct word *)a;
    struct word *wordB = (struct word *)b;
    if (wordA->len != wordB->len) {
        return (wordA->len - wordB->len);
    } else {
        return strcmp(wordA->w, wordB->w);
    }
}

int main() {
    int a;
    scanf("%d", &a);
    struct word words[a];
    for (int i = 0; i < a; i++) {
        scanf("%s", words[i].w);
        words[i].len = strlen(words[i].w);
    }

    qsort(words, a, sizeof(struct word), compare);

    printf("%s\n", words[0].w);
    for (int i = 1; i < a; i++) {
        if (strcmp(words[i].w, words[i-1].w) != 0) {
            printf("%s\n", words[i].w);
        }
    }

    return 0;
}
