#include <stdio.h>
#include <cstring>

int main() {
    char one[1000];
    char two[1000];
    
    scanf("%s\n%s", one,two);
    
    if(strlen(one)<strlen(two)) {
        printf("no");
    }
    else {
        printf("go");
    }
    
    return 0;
}