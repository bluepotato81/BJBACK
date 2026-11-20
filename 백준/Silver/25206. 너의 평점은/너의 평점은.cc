#include <stdio.h>
#include <string.h>

int main() {
    float tot=0;
    float pointtot=0;
    for(int i=0;i<20;i++){
        char subname[51];
        float point;
        char rank[3];
        scanf("%s", subname);

        scanf("%f", &point);
        scanf("%s", rank);
        if(strcmp(rank, "A+") == 0) {
            tot += point * 4.5;
            pointtot += point;
        }
        else if(strcmp(rank, "A0") == 0) {
            tot += point * 4.0;
            pointtot += point;
        }
        else if(strcmp(rank, "B+") == 0) {
            tot += point * 3.5;
            pointtot += point;
        }
        else if(strcmp(rank, "B0") == 0) {
            tot += point * 3.0;
            pointtot += point;
        }
        else if(strcmp(rank, "C+") == 0) {
            tot += point * 2.5;
            pointtot += point;
        }
        else if(strcmp(rank, "C0") == 0) {
            tot += point * 2.0;
            pointtot += point;
        }
        else if(strcmp(rank, "D+") == 0) {
            tot += point * 1.5;
            pointtot += point;
        }
        else if(strcmp(rank, "D0") == 0) {
            tot += point * 1.0;
            pointtot += point;
        }
        else if(strcmp(rank, "F") == 0) {
            tot += point * 0.0;
            pointtot += point;
        }
    }
    float fin=tot/pointtot;

    printf("%f", fin);

    return 0;
}
