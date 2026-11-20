#include <stdio.h>

typedef struct{
    int jump;
    int pre;
}list;

int main() {
    int a;
    scanf("%d", &a);


    list cal[a+1];
    cal[1].jump=0;
    cal[1].pre=0;

    for(int i=2; i<=a; i++) {
        int bef;
        cal[i].jump = cal[i-1].jump +1;
        bef=1;
        if(i%2==0) {
            if(cal[i].jump>cal[i/2].jump+1) {
                cal[i].jump=cal[i/2].jump+1;
                bef=2;
            }
        }
        if(i%3==0) {
            if(cal[i].jump>cal[i/3].jump+1) {
                cal[i].jump=cal[i/3].jump+1;
                bef=3;
            }
        }
        if(bef==1) {
            cal[i].pre=i-1;
        }
        else if(bef==2) {
            cal[i].pre=i/2;
        }
        else {
            cal[i].pre=i/3;
        }
    }

    printf("%d\n", cal[a].jump);

    int loc=a;
    while(loc>=1) {
        printf("%d ", loc);
        loc=cal[loc].pre;
    }
    return 0;
}
