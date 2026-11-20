#include <stdio.h>


int main() {
    int n;
    scanf("%d", &n);

    char m[2*n];
    scanf("%s", m);
    
    for(int i=1; i<2*n;i+=2) {
        if(m[i]==m[i+1]) {
            printf("No");
            return 0;
        }
    }
    
    printf("Yes");

    return 0;
}
