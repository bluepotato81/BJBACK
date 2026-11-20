#include <stdio.h>
#include <math.h>

long long buildings[50];

int check(int a, int b) {
    long long dis=b-a;
    long long dif=buildings[b]-buildings[a];
    //printf("(%d, %d)", dis, dif);
    for(int i=a+1; i<b; i++) {
        //printf("%d ", ((i-a)*dif)+(buildings[a]*dis));
        if(buildings[i]*dis>=((i-a)*dif)+(buildings[a]*dis)) {
            //printf("a\n");
            return 0;
        }
    }
    //printf("o\n");
    return 1;
}


int main() {
    int n;
    scanf("%d", &n);

    for(int i=0; i<n; i++) {
        scanf("%lld", &buildings[i]);
    }

    int max=0;

    for(int i=0; i<n; i++) {
        int see=0;
        //printf("%d.\n", i+1);
        for(int j=0;j<n;j++) {
            if(i<j) {
                see+=check(i,j);
            }
            else if(i>j) {
                see+=check(j,i);
            }
        }
        if(see>max) {
            max=see;
        }
        //printf("%d\n", see);
    }

    printf("%d", max);


    return 0;
}
