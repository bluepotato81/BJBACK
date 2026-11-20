#include <stdio.h>


int main() {
    int x, n;
    scanf("%d %d", &x, &n);
    int tot=0;
    for(int i=0; i<n; i++) {
        int a,b;
        scanf("%d %d", &a, &b);
        tot+=a*b;
    }
   if(tot==x) {
        printf("Yes");
   }
   else {
        printf("No");
   }



    return 0;
}
