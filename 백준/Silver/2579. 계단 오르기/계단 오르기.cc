#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int stairs[n];
    for(int i=0; i<n; i++) {
        scanf("%d", &stairs[i]);
    }

    int one[n], two[n];

    if(n==1) {
        printf("%d", stairs[0]);
        return 0;
    }
    if(n==2) {
        printf("%d", stairs[0]+stairs[1]);
        return 0;
    }


    one[0]=stairs[0];
    two[0]=stairs[0];
    two[1]=stairs[1];
    one[1]=stairs[1]+stairs[0];
    for(int i=2; i<n; i++) {
        one[i]=two[i-1]+stairs[i];
        if(one[i-2]>two[i-2]) {
            two[i]=one[i-2]+stairs[i];
        }
        else {
            two[i]=two[i-2]+stairs[i];
        }
    }
    if(one[n-1]>two[n-1]) {
        printf("%d", one[n-1]);
    }
    else {
        printf("%d", two[n-1]);
    }

    return 0;
}
