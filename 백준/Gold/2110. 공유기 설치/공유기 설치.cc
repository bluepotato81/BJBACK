#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}


int main() {
    int n,c;
    scanf("%d %d", &n, &c);

    int h[n];
    for(int i=0; i<n; i++) {
        scanf("%d", &h[i]);
    }

    qsort(h, n, sizeof(int), compare);

    int startlen=1;
    int endlen=h[n-1]-h[0];

    int ans=0;
    while(startlen<=endlen) {
        int r=1;
        int mid=(startlen+endlen)/2;
        int index=h[0];

        for(int i=1; i<n; i++) {
            if(h[i]-index>=mid) {
                r++;
                index=h[i];
            }
        }

        if(r>=c) {
            if(mid>ans) {
                ans=mid;
            }
            startlen=mid+1;
        }
        else {
            endlen=mid-1;
        }

    }

    printf("%d", ans);


    return 0;
}
