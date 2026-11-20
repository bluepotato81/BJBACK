#include <stdio.h>

int num[20];

int count=0;

int s;

void check(int com, int n, int i) {
    if(n==i) {
        if(com==s) {
            count++;
        }
    }
    else {
        check(com+num[i],n,i+1);
        check(com,n,i+1);
    }
}

int main() {
    int n;
    scanf("%d %d", &n, &s);



    for(int i=0; i<n; i++) {
        scanf("%d", &num[i]);
    }

    check(0,n,0);

    if(s==0) {
        count--;
    }

    printf("%d", count);

    return 0;
}
