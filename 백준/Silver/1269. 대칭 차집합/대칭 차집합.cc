#include <stdio.h>
#include <stdlib.h>

int compare_integers(const void *a, const void *b){
    return (*(int*)a - *(int*)b);
}


int main() {
    int a,b;
    scanf("%d %d", &a, &b);

    int A[a];
    for(int i=0; i<a; i++) {
        scanf("%d", &A[i]);
    }

    qsort(A, a, sizeof(int), compare_integers);

    int b_num=0;

    for(int i=0; i<b; i++) {
        int k;
        scanf("%d", &k);
        int l=0;
        int r=a-1;
        int found=1;
        while(l<=r) {
            int mid=(l+r)/2;
            found=mid;
            if(A[mid]<k) {
                l=mid+1;
            }
            else if(A[mid]>k) {
                r=mid-1;
            }
            else {
                break;
            }
        }
        if(A[found]!=k) {
            b_num++;
        }
    }

    printf("%d", b_num+(a-(b-b_num)));






    return 0;
}
