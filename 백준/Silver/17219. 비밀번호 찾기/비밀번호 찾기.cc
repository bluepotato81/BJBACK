#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct{
    char site[21];
    char password[21];
}pass;

int compare_mystruct(const void *a, const void *b) {
    const pass *structA = (const pass *)a;
    const pass *structB = (const pass *)b;

    if (strcmp(structA->site, structB->site)>0) {
        return 1;
    }
    else {
        return -1;
    }
}

int main() {
    int n,m;
    scanf("%d %d", &n, &m);

    pass sites[n];

    for(int i=0; i<n; i++) {
        scanf("%s %s", sites[i].site, sites[i].password);
    }

    qsort(sites, n, sizeof(pass), compare_mystruct);

    for(int i=0; i<m; i++) {
        char k[21];
        scanf("%s",k);
        int l=0;
        int r=n-1;
        int spot;
        while(1) {
            int m=(l+r)/2;
            if(strcmp(sites[m].site, k)>0) {
                r=m-1;
            }
            else if(strcmp(sites[m].site,k)<0) {
                l=m+1;
            }
            else {
                spot=m;
                break;
            }
        }
        printf("%s\n", sites[spot].password);
    }




    return 0;
}
