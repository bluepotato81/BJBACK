#include <stdio.h>

char love[4];

int main() {
    scanf("%s", love);
    

    for(int i=2; i>=0; i--) {
        printf("%c", love[i]);
    }
    
    return 0;
}