#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n;
    scanf("%d", &n);

    int sol[n];

    int allpluscheck=1;
    int allminuscheck=1;
    for(int i=0; i<n; i++) {
        scanf("%d", &sol[i]);
        if(sol[i]<0) {
            allpluscheck=0;
        }
        if(sol[i]>0) {
            allminuscheck=0;
        }
    }

    qsort(sol, n, sizeof(int), compare);

    if(allpluscheck==1) {
        printf("%d %d", sol[0],sol[1]);
        return 0;
    }

    if(allminuscheck==1) {
        printf("%d %d", sol[n-2],sol[n-1]);
        return 0;
    }




    int minabs=1000000000;
    int switchtime = -1;
    for (int i = 0; i < n - 1; i++) {
        if (abs(sol[i]) < minabs) {
            switchtime = i;
            minabs=abs(sol[i]);
        }
    }


    int min=switchtime;
    int pl=switchtime+1;

    int close=2147483647;
    int bestn, bestp;
    while(min>=0 && pl<n) {
        int sum=sol[min]+sol[pl];
        if(abs(sum)<abs(close)) {
            close=sum;
            bestn=sol[min];
            bestp=sol[pl];
        }
        if(sum<0) {
            pl++;
        }
        else {
            min--;
        }
    }


    min=switchtime-1;
    pl=switchtime;

    int nbestn, nbestp;

    int check=0;
    while(min>=0 && pl<n) {
        int sum=sol[min]+sol[pl];
        if(abs(sum)<abs(close)) {
            close=sum;
            nbestn=sol[min];
            nbestp=sol[pl];
            check=1;
        }
        if(sum<0) {
            pl++;
        }
        else {
            min--;
        }
    }


    if(check==0) {
        printf("%d %d", bestn, bestp);
    }
    else {
        printf("%d %d", nbestn, nbestp);
    }


    return 0;
}
