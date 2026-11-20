#include <stdio.h>

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int a;
    scanf("%d", &a);
    int tree[a];
    int treespace[a-1];
    for(int i=0; i<a; i++) {
        scanf("%d", &tree[i]);
        if(a!=0) {
            treespace[i-1]=tree[i]-tree[i-1];
        }
    }

    int g=treespace[0];


    for(int i=1;i<a-1;i++) {
        g = gcd(treespace[i],g);
    }

    int newtree=0;
    for(int i=0;i<a-1;i++) {
        newtree+=treespace[i]/g - 1;
    }
    printf("%d", newtree);

    return 0;
}
