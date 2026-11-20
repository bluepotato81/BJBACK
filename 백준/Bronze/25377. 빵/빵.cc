#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int min=1001;
    while(n--) {
        int a,b;
        scanf("%d %d", &a, &b);
        if(a<=b) {
            if(b<min) {
                min=b;
            }
        }
    }
    if(min==1001){
        printf("-1");
    }
    else {
        printf("%d", min);
    }
    
    return 0;
}