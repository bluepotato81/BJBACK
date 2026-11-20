#include <stdio.h>
#include <string.h>
char c[1000001];

int main() {
    gets(c);
    int count=0;
    if(strlen(c)==0 || (strlen(c)==1 && c[0]==' ')) {
        printf("0");
        return 0;
    }
    else {
        for(size_t i=0; i<strlen(c); i++) {
            if(c[i]==' ' && (i!=0 && i!=strlen(c)-1)) {
                count++;
        }
    }
    }
    printf("%d", count+1);

    return 0;

}
