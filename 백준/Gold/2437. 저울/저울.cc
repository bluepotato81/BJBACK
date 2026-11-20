#include <stdio.h>
#include <stdlib.h>

int comp(const void *a, const void *b) {
    return (*(int*)a-*(int*)b);
}

int main() {
    int n;
    scanf("%d", &n);

    int ch[n];

    for(int i=0; i<n;i++) {
        scanf("%d", &ch[i]);
    }

    qsort(ch, n, sizeof(int), comp);

    if(ch[0]!=1) {
        printf("1");
        return 0;
    }

    int max=1;

    for(int i=1; i<n;i++) {
        if(ch[i]>max+1) {
            printf("%d", max+1);
            return 0;
        }
        max+=ch[i];
    }

    printf("%d", max+1);

    return 0;

}
