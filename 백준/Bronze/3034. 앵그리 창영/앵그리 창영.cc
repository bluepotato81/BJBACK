#include <stdio.h>
#include <math.h>

int main() {
    int n,w,h;
    scanf("%d %d %d", &n, &w, &h);

    float lim=sqrt(w*w+h*h);


    while(n--) {
        int l;
        scanf("%d", &l);
        if(l<=lim){
            printf("DA\n");
        }
        else{
            printf("NE\n");
        }
    }
    return 0;
}

