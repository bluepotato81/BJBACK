#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int compareIntegers(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int a;
    scanf("%d", &a);
    int dif[a];
    
    if(a==0) {
        printf("0");
        return 0;
    }

    for(int i=0; i<a; i++) {
        scanf("%d", &dif[i]);
    }

    qsort(dif, a, sizeof(int), compareIntegers);

    float top=a*0.15, bottom=a*0.15;
    int to=round(top), bot=round(bottom);

    int com=0;

    for(int i=to; i<a-bot; i++) {
        com+=dif[i];
    }


    int av_num=a-to-bot;
    float b=(float)com/av_num;

    int f=round(b);
    printf("%d", f);



    return 0;
}
