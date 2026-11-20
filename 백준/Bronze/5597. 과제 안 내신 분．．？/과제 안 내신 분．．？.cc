#include <stdio.h>

int main() {
    int cl[30] = {0,};

    for(int i=0; i<28; i++) {
        int a;
        scanf("%d", &a);
        cl[a-1]++;
    }

    for(int i=0; i<30; i++) {
        if(cl[i]==0) {
            printf("%d\n", i+1);
        }
    }

    return 0;
}

