#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int val, order;
}que;

int big(const void *a, const void *b) {
    const que *A = (const que *)a;
    const que *B = (const que *)b;
    return B->val-A->val;
}

int small(const void *a, const void *b) {
    const que *A = (const que *)a;
    const que *B = (const que *)b;
    return A->val-B->val;
}

int ans(const void *a, const void *b) {
    const que *A = (const que *)a;
    const que *B = (const que *)b;
    return A->order-B->order;
}

que in[3000];
int curnum;

void up(int ord) {
    for(int i=0; i<curnum; i++) {
        if(in[i].order>ord) {
            in[i].order++;
        }
    }
}

int main() {
    int q;
    scanf("%d", &q);


    int a,b,c;
    for(int i=0; i<q; i++) {
        scanf("%d", &a);
        if(a==1) {
            scanf("%d", &b);
            if(b==1) {
                qsort(in, curnum, sizeof(que), small);
                for(int j=0; j<curnum; j++) {
                    in[j].order=j+1;
                }
            }
            else {
                qsort(in, curnum, sizeof(que), big);
                for(int j=0; j<curnum; j++) {
                    in[j].order=j+1;
                }
            }
        }
        else {
            scanf("%d %d", &b, &c);
            up(b);
            in[curnum].val=c;
            in[curnum++].order=b+1;
        }
       // for(int j=0; j<curnum; j++) {
            //printf("{%d, %d} ", in[j].val, in[j].order);
        //}
        //printf("\n");
    }

    qsort(in, curnum, sizeof(que), ans);
    printf("%d\n", curnum);
    if(curnum==0) {
        return 0;
    }


    for(int i=0; i<curnum; i++) {
        printf("%d ", in[i].val);
    }

    return 0;
}
