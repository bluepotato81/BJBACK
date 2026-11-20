#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int m,i=0;
    while(n>0) {
        i++;
        m=n;
        n-=i;
    }

    if(i%2==1) {
        printf("%d/%d", i-m+1, m);
    }
    else if(i%2==0) {
        printf("%d/%d", m, i-m+1);
    }


    return 0;
}

