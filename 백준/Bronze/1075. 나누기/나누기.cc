#include <stdio.h>

int main() {
    int n,f;
    scanf("%d %d", &n, &f);
    int en=n/100;
    int an, s;
    for(int i=0; i<100; i++) {
        an=en*100+i;
        if(an%f==0) {
            s=i;
            break;
        }
    }
    
    if(s<10) {
        printf("0");
        printf("%d", s);
    }
    else {
        printf("%d", s);
    }
    
    
    return 0;
}
