#include <stdio.h>
#include <stdlib.h>

int comp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int main() {
    int n;
    scanf("%d", &n);
    if(n==1) {
        scanf("%d", &n);
        printf("0");
        return 0;
    }
    int c[n-1];
    int cn;
    scanf("%d", &cn);
    for(int i=0; i<n-1;i++) {
        scanf("%d", &c[i]);
    }

    int k=0;
    while(1){
        qsort(c,n-1,sizeof(int),comp);
        if(cn>c[n-2]) {
            break;
        }
        else {
            c[n-2]--;
            cn++;
            k++;
        }

    }
    printf("%d", k);



    return 0;
}
