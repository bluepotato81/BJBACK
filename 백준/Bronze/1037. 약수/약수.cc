#include <stdio.h>
#include <stdlib.h>

int compare_integers(const void *a, const void *b) {
    int int_a= *(int *)a;
    int int_b= *(int *)b;

    return (int_a-int_b);
}

int main() {
    int num;
    scanf("%d", &num);
    int d[num];
    for(int i=0; i<num; i++) {
        scanf("%d", &d[i]);
    }

    qsort(d, num, sizeof(int), compare_integers);

    printf("%d", d[0]*d[num-1]);

    return 0;
}
