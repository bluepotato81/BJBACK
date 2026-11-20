#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int input[n];
    int rightbig[n];
    int stack[n];
    int stacklen=0;
    for(int i=0; i<n; i++) {
        scanf("%d", &input[i]);
    }

    for (int i=0; i<n; i++) {
        while(stacklen>0 && input[stack[stacklen-1]]<input[i]) {
            rightbig[stack[stacklen-1]]=input[i];
            stacklen--;
        }
        stack[stacklen]=i;
        stacklen++;
    }
    for(int i=0; i<stacklen; i++) {
        rightbig[stack[i]]=-1;
    }

    for(int i=0; i<n; i++) {
        printf("%d ", rightbig[i]);
    }

    return 0;
}
