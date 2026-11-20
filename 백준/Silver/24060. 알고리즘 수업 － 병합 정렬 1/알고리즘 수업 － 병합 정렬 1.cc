#include <stdio.h>

void merge(int A[], int p, int q, int r, int *num, int ek, int *tar) {
    int n1 = q - p + 1;
    int n2 = r - q;
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = A[p + i];
    for (int j = 0; j < n2; j++)
        R[j] = A[q + 1 + j];

    int i = 0, j = 0, k = p;
    while (i < n1 && j < n2) {
        (*num)++;
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
        if ((*num) == ek) {
            *tar = A[k];
            return;
        }
        k++;
    }

    while (i < n1) {
        (*num)++;
        A[k] = L[i];
        if ((*num) == ek) {
            *tar = A[k];
            return;
        }
        i++;
        k++;
    }

    while (j < n2) {
        (*num)++;
        A[k] = R[j];
        if ((*num) == ek) {
            *tar = A[k];
            return;
        }
        j++;
        k++;
    }
}

void merge_sort(int A[], int p, int r, int *num, int ek, int *tar) {
    if (p < r) {
        int q = (p + r) / 2;
        merge_sort(A, p, q, num, ek, tar);
        merge_sort(A, q + 1, r, num, ek, tar);
        merge(A, p, q, r, num, ek, tar);
    }
}

int main() {
    int En, Ek;
    scanf("%d %d", &En, &Ek);
    int A[En];

    int tar = 0;
    for (int i = 0; i < En; i++) {
        scanf("%d", &A[i]);
    }

    int num = 0;

    merge_sort(A, 0, En - 1, &num, Ek, &tar);

    if (tar == 0) {
        printf("-1\n");
    } else {
        printf("%d\n", tar);
    }

    return 0;
}
