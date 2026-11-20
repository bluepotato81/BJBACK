#include <stdio.h>

int main() {
    int a;
    scanf("%d", &a);

    int cal[a+1];
    cal[1]=0;

    for(int i=2; i<=a; i++) {
        cal[i] = cal[i-1] +1;
        if(i%2==0) {
            if(cal[i]>cal[i/2]+1) {
                cal[i]=cal[i/2]+1;
            }
        }
        if(i%3==0) {
            if(cal[i]>cal[i/3]+1) {
                cal[i]=cal[i/3]+1;
            }
        }
    }

    printf("%d", cal[a]);
    return 0;
}
