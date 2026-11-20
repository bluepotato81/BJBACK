#include <stdio.h>
#include <math.h>

int switch_val(int x) {
    if(x==1) {
        return 1;
    }
    else if(x==2) {
        return 2;
    }
    else if(x==0) {
        return 0;
    }

    int n = (int) sqrt((double) x);

    if (n*n==x) {
        return 2*n-1;
    }
    else if(x<=n*(n+1)) {
        return 2*n;
    }
    else {
        return 2*n+1;
    }
    return -1;

}

int main() {
    int a;
    scanf("%d", &a);

    while(a>0) {
        int x,y;
        scanf("%d %d",&x, &y);
        printf("%d\n", switch_val(y-x));
        a--;
    }

    return 0;
}
