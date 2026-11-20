#include <stdio.h>
#include <stdlib.h>

int map[27][27];
int housesize[700];
int housenum=0;

int compare(const void *a, const void *b) {
    return (*(int*)a-*(int*)b);
}


void dfs(int i, int j) {
    if(map[i][j]==1) {
        map[i][j]=2;
        housesize[housenum]++;
        if(map[i-1][j]==1) {
            dfs(i-1,j);
        }
        if(map[i][j-1]==1) {
            dfs(i,j-1);
        }
        if(map[i][j+1]==1) {
            dfs(i,j+1);
        }
        if(map[i+1][j]==1) {
            dfs(i+1,j);
        }
    }
}



int main() {
    int n;
    scanf("%d", &n);

    for(int i=1; i<n+1; i++) {
        for(int j=1; j<n+1; j++) {
            char see;
            scanf(" %c", &see);
            map[i][j]=see-'0';
        }
    }

    for(int i=1; i<n+1; i++) {
        for(int j=1; j<n+1; j++) {
            if(map[i][j]==1) {
                dfs(i,j);
                housenum++;
            }
        }
    }

    qsort(housesize, housenum, sizeof(int), compare);

    printf("%d\n", housenum);

    for(int i=0; i<housenum; i++) {
        printf("%d\n", housesize[i]);
    }

    return 0;
}
