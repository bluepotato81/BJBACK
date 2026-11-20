#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);
    while(n--) {
        char k[21];
        scanf("%s", k);
        
        if(strlen(k)>=6 && strlen(k)<=9) {
            printf("yes\n");
        }
        else {
            printf("no\n");
        }
    }
    
    return 0;
}