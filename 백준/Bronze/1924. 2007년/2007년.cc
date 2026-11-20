#include <stdio.h>

int main() {
    int x,y;
    scanf("%d %d", &x, &y);

    int totdays=0;
    for(int i=1; i<x; i++) {
        if(i==1 || i==3 || i==5 || i==7 || i==8 ||i==10) {
            totdays+=31;
        }
        else if(i==2) {
            totdays+=28;
        }
        else {
            totdays+=30;
        }
    }

    totdays+=y;

    int week=totdays%7;

    if(week==2) {
        printf("TUE");
    }
    if(week==3) {
        printf("WED");
    }
    if(week==4) {
        printf("THU");
    }
    if(week==5) {
        printf("FRI");
    }
    if(week==6) {
        printf("SAT");
    }
    if(week==0) {
        printf("SUN");
    }
    if(week==1) {
        printf("MON");
    }

    return 0;
}
