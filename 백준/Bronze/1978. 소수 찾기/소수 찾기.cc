#include <stdio.h>
#include <math.h>

int main() {
    int n;
    scanf("%d", &n);

    int num=0;
    for(int i=0; i<n;i++) {
        int a;
        scanf("%d", &a);
        int f=0;
        for(int j=1; j<=sqrt(a);j++) {
            if(a%j==0) {
                if(j*j==a) {
                    f++;
                }
                else {
                    f+=2;
                }

            }
        }
        if(f==2 && a!=1) {
            num++;
        }

    }

    printf("%d", num);

    return 0;
}
