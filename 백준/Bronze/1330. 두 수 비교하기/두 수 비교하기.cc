#include <stdio.h>

int main() {
    int h, m;
    scanf("%d %d", &h, &m);
    if(h>m) {
        printf(">");
    }
    else if(h<m) {
        printf("<");
    }
    else {
        printf("==");
    }


    return 0;
}
