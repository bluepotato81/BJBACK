#include <stdio.h>

int main() {
    int x[2]={-1, -1};
    int y[2]={-1,-1};

    for(int i=0; i<3; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        if(x[0]==a) {
            x[0] = 0;
        }
        else if(x[1]==a) {
            x[1] = 0;
        }
        else {
            if(x[0]==-1) {
                x[0] = a;
            }
            else {
                x[1]=a;
            }
        }
        if(y[0]==b) {
            y[0] = 0;
        }
        else if(y[1]==b) {
            y[1] = 0;
        }
        else {
            if(y[0]==-1) {
                y[0] = b;
            }
            else {
                y[1]=b;
            }
        }
    }

    if(x[0]==0) {
        printf("%d ", x[1]);
    }
    else {
        printf("%d ", x[0]);
    }

    if(y[0]==0) {
        printf("%d ", y[1]);
    }
    else {
        printf("%d ", y[0]);
    }

    return 0;
}
