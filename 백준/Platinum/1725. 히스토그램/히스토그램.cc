#include <stdio.h>

typedef struct {
    int height;
    int start_loc;
}rectangle;

int hist[100000];
rectangle stack[100000];

int main() {
    int n;
    scanf("%d", &n);

    for(int i=0; i<n; i++) {
        scanf("%d", &hist[i]);
    }

    long long max_area=0;

    int stacklen=0;
    for(int i=0; i<n; i++) {
        int start=i;

        while(stacklen>0 && hist[i]<stack[stacklen-1].height) {
            stacklen--;
            int height = stack[stacklen].height;
            long long area=(long long)height*(i-stack[stacklen].start_loc);
            if(area>max_area) {
                max_area=area;
            }
            start=stack[stacklen].start_loc;

        }
        stack[stacklen].height=hist[i];
        stack[stacklen].start_loc=start;
        stacklen++;
    }

    while(stacklen>0) {
        stacklen--;
        int height = stack[stacklen].height;
        long long area=(long long)height*(n-stack[stacklen].start_loc);
        if(area>max_area) {
            max_area=area;
        }
    }

    printf("%lld",max_area);

    return 0;
}
