#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int s;
    int f;
    int order;
}conf;



int compare_finish(const void *a, const void *b) {
    conf* confA=(conf *)a;
    conf* confB=(conf *)b;


    if(confA->f != confB->f) {
        return(confA->f - confB->f);
    }
    else {
        return (confA->s - confB->s);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    conf c[n];
    for(int i=0; i<n; i++) {
        scanf("%d %d", &c[i].s, &c[i].f);
        c[i].order=i;
    }

    int k=0;

    qsort(c, n, sizeof(conf), compare_finish);

    int num=1;
    for(int i=1; i<n; i++) {
        if(c[i].s>=c[k].f) {
            k=i;
            num++;
        }
    }

    printf("%d", num);

    return 0;
}
