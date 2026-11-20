#include <stdio.h>
#include <stdlib.h>

int good[100000];
int bad[100000];

int comp(const void *a, const void *b) {
    return *(int *)a-*(int *)b;
}

int find_good(int x, int a) {
    int l=0;
    int r=a-1;
    while(l<=r) {
        int m=(l+r)/2;
        if(good[m]<x) {
            l=m+1;
        }
        else if(good[m]>x) {
            r=m-1;
        }
        else {
            return 1;
        }
    }
    int m=(l+r)/2;
    if(good[m]==x) {
        return 1;
    }
    else {
        return 0;
    }
}

int find_bad(int x, int b) {
    int l=0;
    int r=b-1;
    while(l<=r) {
        int m=(l+r)/2;
        if(bad[m]<x) {
            l=m+1;
        }
        else if(bad[m]>x) {
            r=m-1;
        }
        else {
            return 1;
        }
    }
    int m=(l+r)/2;
    if(bad[m]==x) {
        return 1;
    }
    else {
        return 0;
    }
}

int find(int x, int a, int b) {
    if(find_good(x,a)) {
        return 1;
    }
    else if(find_bad(x,b)) {
        return -1;
    }
    else {
        return 0;
    }
}

int main() {
    int n,m,a,b;
    scanf("%d %d %d %d", &n, &m, &a, &b);

    int sch[n];

    for(int i=0; i<n; i++) {
        scanf("%d", &sch[i]);
    }


    for(int i=0; i<a; i++) {
        scanf("%d", &good[i]);
    }

    for(int i=0; i<b; i++) {
        scanf("%d", &bad[i]);
    }

    qsort(good, a, sizeof(int), comp);
    qsort(bad, b, sizeof(int), comp);

    int score=0;
    int consgood=0;
    int consbad=0;

    for(int i=0; i<n; i++) {
        int k=find(sch[i],a,b);
        if(k==1) {
            consgood++;
            if(consbad>=3) {
                score-=consbad;
            }
            consbad=0;
        }
        else if(k==-1) {
            consbad++;
            if(consgood>=3) {
                score+=consgood;
            }
            consgood=0;
        }
        else {
            if(consbad>=3) {
                score-=consbad;
            }
            if(consgood>=3) {
                score+=consgood;
            }
            consbad=0;
            consgood=0;
        }
    }

    if(consbad>=3) {
        score-=consbad;
    }
    if(consgood>=3) {
        score+=consgood;
    }

    printf("%d", score);

    return 0;
}
