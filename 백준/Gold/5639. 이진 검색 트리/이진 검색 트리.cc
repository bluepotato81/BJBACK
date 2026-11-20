#include <stdio.h>

#define MAX_NODES 10000

int input[MAX_NODES];

void postOrder(int start, int end) {
    if (start >= end)
        return;

    int root = input[start];
    int i = start + 1;

    // Find the index where right subtree starts
    while (i < end && input[i] < root) {
        i++;
    }

    // Recursively process left and right subtrees
    postOrder(start + 1, i);
    postOrder(i, end);

    // Print root (postorder)
    printf("%d\n", root);
}

int main() {
    int len = 0;
    while (scanf("%d", &input[len]) != EOF) {
        len++;
    }

    postOrder(0, len);

    return 0;
}
