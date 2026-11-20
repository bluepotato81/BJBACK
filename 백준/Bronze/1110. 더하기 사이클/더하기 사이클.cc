#include <stdio.h>
#include <stdlib.h>


int main() {
    int n;
    scanf("%d", &n);



    int next1;
    int next2;
    int rot=1;

    next1=(((n/10)+(n%10))%10)+((n%10)*10);



    while(next1!=n && next2!=n) {
        next2=next1;
        next2=((next1/10)+(next1%10))%10+((next1%10)*10);
        rot++;
        next1=next2;

    }

    printf("%d", rot);

    return 0;
}
