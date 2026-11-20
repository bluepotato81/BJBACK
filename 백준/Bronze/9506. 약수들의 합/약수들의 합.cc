#include <stdio.h>
#include <math.h>

int main() {

    while(1) {
        int num;
        scanf("%d",&num);
        if(num==-1) {
            break;
        }
        int ch=num;
        for(int i=1; i<=sqrt(num); i++) {
            if(num%i==0) {
                ch-=i;
                if(i!=sqrt(num) && i!=1) {
                    ch-=num/i;
                }
            }
        }
        if(ch==0) {
            printf("%d = ", num);
            for(int i=1; i<num; i++) {
                if(num%i==0) {
                    if(i!=1) {
                        printf("+ ");
                    }
                    if(i!=num) {
                        printf("%d ", i);
                    }
                }
            }
            printf("\n");
        }
        else {
            printf("%d is NOT perfect.\n", num);
        }
    }

    return 0;
}
